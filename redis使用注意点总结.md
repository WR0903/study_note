## redis的使用注意点总结

### 如何使用redis更节省内存

redis之所以快是因为它是一款内存数据库，但是一台机器内存都是有限且比较珍贵的资源，使用redis的时候需要合理的规划对应的内存优化策略。

1、控制key的长度，当key的量级很大的时候，合理的控制key的长度可以节省很大的空间。

2、避免存储bigkey，除了控制key的长度，value的大小也要关注，string的大小控制在10kb以下，list、hash、set、zset也要控制。

3、合理的选择数据类型

String、Set 在存储 int 数据时，会采用整数编码存储。Hash、ZSet 在元素数量比较少时（可配置），会采用压缩列表（ziplist）存储，在存储比较多的数据时，才会转换为哈希表和跳表。

- String、Set：尽可能存储 int 类型数据
- Hash、ZSet：存储的元素数量控制在转换阈值之下，以压缩列表存储，节约内存

4、把redis尽可能的当成缓存使用

5、实例设置maxmemory+淘汰策略

虽然使用redis的时候会设置key的过期时间，但是如果业务写入量比较大的话，那么短期内redis的内存依旧会快速增加。需要提前预估业务数据量，然后给实例设置maxmemory控制实例的内存上限，然后需要设置内存过期策略。

- volatile-lru / allkeys-lru：优先保留最近访问过的数据
- volatile-lfu / allkeys-lfu：优先保留访问次数最频繁的数据（4.0+版本支持）
- volatile-ttl ：优先淘汰即将过期的数据
- volatile-random / allkeys-random：随机淘汰数据

6、数据压缩后写入redis

### 如何持续的发挥redis的高性能

1、避免存储bigkey

redis是单线程的，当写入一个bigkey的时候，redis会用更多的时间消耗在内存分配上，同样删除的时候也会比较耗时，另外就是客户端在读取bigkey的时候，在网络数据传输上比较耗时。

2、开启lazy-free机制

如果无法避免的使用bigkey的时候，可以开启lazy-free机制，当删除bigkey的时候，释放内存的操作会交给后台线程执行，这样可以最大程度上避免对主线程的影响。

3、不适用复杂度过高的命令

4、执行O（N）级别的命令的时候，要关注以下N的大小

对于容器类型（List/Hash/Set/ZSet），在元素数量未知的情况下，一定不要无脑执行 LRANGE key 0 -1 / HGETALL / SMEMBERS / ZRANGE key 0 -1

在查询数据时，你要遵循以下原则：

1. 先查询数据元素的数量（LLEN/HLEN/SCARD/ZCARD）
2. 元素数量较少，可一次性查询全量数据
3. 元素数量非常多，分批查询数据（LRANGE/HASCAN/SSCAN/ZSCAN）

5、关注del的时间复杂度

当你删除的是一个 String 类型 key 时，时间复杂度确实是 O(1)。

但当你要删除的 key 是 List/Hash/Set/ZSet 类型，它的复杂度其实为 O(N)，N 代表元素个数。

**也就是说，删除一个 key，其元素数量越多，执行 DEL 也就越慢！**

- List类型：执行多次 LPOP/RPOP，直到所有元素都删除完成
- Hash/Set/ZSet类型：先执行 HSCAN/SSCAN/SCAN 查询元素，再执行 HDEL/SREM/ZREM 依次删除每个元素

6、批量的命令代替单个命令

- String / Hash 使用 MGET/MSET 替代 GET/SET，HMGET/HMSET 替代 HGET/HSET
- 其它数据类型使用 Pipeline，打包一次性发送多个命令到服务端执行

7、避免集中过期key

如果业务中有大量的key集中过期，这个会阻塞主线程，可以在设置过期时间的时候增加一个随机时间，将过期时间打散。

8、使用长链接操作redis，合理配置连接池

尽量避免短链接，因为每次都是tcp，三次握手和四次挥手，这个过程会增加操作消耗。

9、只使用db0

1. 在一个连接上操作多个 db 数据时，每次都需要先执行 SELECT，这会给 Redis 带来额外的压力
2. 使用多个 db 的目的是，按不同业务线存储数据，那为何不拆分多个实例存储呢？拆分多个实例部署，多个业务线不会互相影响，还能提高 Redis 的访问性能
3. Redis Cluster 只支持 db0，如果后期你想要迁移到 Redis Cluster，迁移成本高

10、使用读写分离+分片集群

如果读业务很大，可以采用部署多个从库的方式，实现读写分离，让从库分担读压力，提升性能。

如果写业务的请求很大，单个redis的实例无法支持大的流量，可以使用分片集群，分担写压力。

11、不开启AOF或AOF配置成每秒刷盘

对于丢失数据不敏感的业务，不建议开启AOF，如果确实需要开启，可以配置成 appendfsync everysec，将持久化放在后台线程中。

12、使用物理机部署redis

redis使用rdb持久化的时候，采用子进程的方式，虚拟机支持fork比较耗时。

13、关闭操作系统内存大页机制

### 如何保证redis的高可用

redis可靠性也是不难，难点是持续的稳定。

1、按照业务线进行部署实例

不同的业务采用不同的redis的实例，有问题的时候互不干扰。

2、部署主从集群

主库和从库也最好放在不同的机器上。

3、合理的设置主从复制参数

1. 设置合理的 repl-backlog 参数：过小的 repl-backlog 在写流量比较大的场景下，主从复制中断会引发全量复制数据的风险
2. 设置合理的 slave client-output-buffer-limit：当从库复制发生问题时，过小的 buffer 会导致从库缓冲区溢出，从而导致复制中断

4、部署哨兵集群，实现故障自动转移

只部署了主从节点，但故障发生时是无法自动切换的，所以，你还需要部署哨兵集群，实现故障的「自动切换」。

而且，多个哨兵节点需要分布在不同机器上，实例为奇数个，防止哨兵选举失败，影响切换时间。

### 日常运维redis需要注意什么

1、禁止使用 KEYS/FLUSHALL/FLUSHDB 命令，会阻塞主线程，影响线上业务

- SCAN 替换 KEYS
- 4.0+版本可使用 FLUSHALL/FLUSHDB ASYNC，清空数据的操作放在后台线程执行

2、扫描线上实例时，设置休眠时间

不管你是使用 SCAN 扫描线上实例，还是对实例做 bigkey 统计分析，我建议你在扫描时一定记得设置休眠时间。

防止在扫描过程中，实例 OPS 过高对 Redis 产生性能抖动。

3、慎用monitor命令

4、从库必现设置成slave-read-only，避免从库写入导致数据不一致。

5、合理配置 timeout 和 tcp-keepalive 参数，

如果因为网络原因，导致你的大量客户端连接与 Redis 意外中断，恰好你的 Redis 配置的 maxclients 参数比较小，此时有可能导致客户端无法与服务端建立新的连接（服务端认为超过了 maxclients）。

造成这个问题原因在于，客户端与服务端每建立一个连接，Redis 都会给这个客户端分配了一个 client fd。

当客户端与服务端发生网络问题，服务端不会立即释放client fd。

1. 不要配置过高的 timeout：让服务端尽快把无效的 client fd 清理掉
2. Redis 开启 tcp-keepalive：这样服务端会定时给客户端发送 TCP 心跳包，检测连接连通性，当网络异常时，可以尽快清理僵尸 client fd

6、调整maxmemory时，注意主从库的调整顺序

Redis 5.0 以下版本存在这样一个问题：**从库内存如果超过了 maxmemory，也会触发数据淘汰。**

在某些场景下，从库是可能优先主库达到 maxmemory 的（例如在从库执行 MONITOR 命令，输出缓冲区占用大量内存），那么此时从库开始淘汰数据，主从库就会产生不一致。

要想避免此问题，在调整 maxmemory 时，一定要注意主从库的修改顺序：

- 调大 maxmemory：先修改从库，再修改主库
- 调小 maxmemory：先修改主库，再修改从库

直到 Redis 5.0，Redis 才增加了一个配置 replica-ignore-maxmemory，默认从库超过 maxmemory 不会淘汰数据，才解决了此问题。

### redis安全问题

1. 不要把 Redis 部署在公网可访问的服务器上
2. 部署时不使用默认端口 6379
3. 以普通用户启动 Redis 进程，禁止 root 用户启动
4. 限制 Redis 配置文件的目录访问权限
5. 推荐开启密码认证
6. 禁用/重命名危险命令（KEYS/FLUSHALL/FLUSHDB/CONFIG/EVAL）

