# 剑指offer

## 09、用两个栈实现一个队列

用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操作返回 -1 )

**示例1**

```
输入：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]
```

**示例2：**

```
输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
```

**思路**

用两个栈，一个栈用来进行数据的进栈操作，另一个栈是用来出战，注意的是，当第二个栈空的时候才把第一个栈的数据转移到第二个栈中。

**例程**

```c++
class CQueue {
public:
    CQueue() {

    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if (s2.empty()) {
            while (!s1.empty()) {
                int tmp = s1.top();
                s1.pop();
                s2.push(tmp);
            }
        }
        if (s2.empty()) {
            return -1;
        }
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
    stack<int> s1;
    stack<int> s2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

## 10、斐波那契数列1

写一个函数，输入 `n` ，求斐波那契（Fibonacci）数列的第 `n` 项（即 `F(N)`）。斐波那契数列的定义如下：

```
F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
```

斐波那契数列由 0 和 1 开始，之后的斐波那契数就是由之前的两数相加而得出。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例1**：

```
输入：n = 2
输出：1
```

**示例2：**

```
输入：n = 5
输出：5
```

**思路**

可以用递归，但是递归会增加很多运算，简单的方法是从第一个数往后算。

**例程**

```c++
class Solution {
public:
    int fib(int n) {
        if (n == 0) {
			return 0;
		}
        vector<int>f(n + 1, 0);
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
            f[i] = f[i] % 1000000007;
		}
		return f[n];
    }
};
```

## 03、数组中重复的数字

找出数组中重复的数字。

在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

**示例：**

```
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
```

**例程**

```c++
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int flag_zero = 0;
		for (int i = 0; i < nums.size(); i++) {
			int tmp = abs(nums[i]);
			if (tmp == 0 && flag_zero)
				return tmp;
			else if (tmp == 0 && !flag_zero)
				flag_zero = 1;
			if (nums[tmp] < 0)
				return tmp;
			else
				nums[tmp] = -nums[tmp];
		}
		return -1;
    }
};
```

```python
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        flag = 0
        n=len(nums)
        for index in xrange(n):
            num =abs(nums[index])
            if num == 0 and flag==0:
                flag=1
            elif num==0 and flag ==1:
                return 0
            elif nums[num] <0:
                return num
            else:
                nums[num] = -nums[num]
```



## 04、二维数组中的查找

在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个高效的函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。

**示例：**

```
现有矩阵 matrix 如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

给定 target = 5，返回 true。

给定 target = 20，返回 false。
```

**例程：**

```c++
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
			return false;
		int n = matrix.size();
		int m = matrix[0].size();
		int i = 0, j = m - 1;
		while (i < n && j >= 0) {
			if (matrix[i][j] == target) {
				return true;
			}
			else if (matrix[i][j] > target) {
				j--;
			}
			else {
				i++;
			}
		}
		return false;
    }
};
```

## 10、青蛙跳台阶2

一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例1：**

```
输入：n = 2
输出：2
```

**示例2：**

```
输入：n = 7
输出：21
```

**示例3：**

```
输入：n = 0
输出：1
```

**思路**

其实这道题是斐波那契数列，下面的解法是空间压缩法，空间复杂度是常数c

**例程**

```c++
class Solution {
public:
    int numWays(int n) {
        vector<int>result{ 1,1 };
		if (n <= 1) {
			return result[n];
		}
		int one = 1, two = 1, ans = 0;
		for (int i = 2; i <= n; i++) {
			ans = one + two;
			ans %= 1000000007;
			one = two;
			two = ans;
		}
		return ans;
    }
};
```

## 11、旋转数组的最小数字

把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。

**示例1：**

```
输入：[3,4,5,1,2]
输出：1
```

**示例2：**

```
输入：[2,2,2,0,1]
输出：0
```

**例程**

```c++
class Solution {
public:
    int minArray(vector<int>& numbers) {
        if (numbers.empty())
			return -1;
		int n = numbers.size();
		int l = 0, r = n - 1, mid = l;
		while (numbers[l] >= numbers[r]) {
			if (r - l <= 1) {
				mid = r;
				break;
			}
			mid = (l + r) / 2;
            if (numbers[mid] == numbers[l] && numbers[mid] == numbers[r]) {
				return orderFindMin(numbers, l, r);
			}
			if (numbers[mid] >= numbers[l])
				l = mid;
			else if(numbers[mid] <= numbers[r])
				r = mid;
		}
		return numbers[mid];
    }
    int orderFindMin(vector<int>& numbers, int l, int r) {
		int ans = numbers[l];
		for (int i = l + 1; i <= r; i++) {
			if (ans > numbers[i])
				ans = numbers[i];
		}
		return ans;
	}
};
```

## 12、矩阵中的路径

给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

例如，在下面的 3×4 的矩阵中包含单词 "ABCCED"（单词中的字母已标出）。

![img](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

**示例1：**

```
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true
```

**示例2：**

```
输入：board = [["a","b"],["c","d"]], word = "abcd"
输出：false
```

**思路**

回溯法

**例程**

```c++
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
		vector<vector<bool>>visited(n, vector<bool>(m, false));
		bool find = false;
		for (int i = 0; i < n; i++) {
			if (find)
				break;
			for (int j = 0; j < m; j++) {
				if (find)
					break;
				backtracking(board, word, visited, 0, i, j, find);
			}
		}
		return find;
    }
    void backtracking(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, 
		int pose, int x, int y, bool& find) {
		int n = board.size(), m = board[0].size();
		if (x < 0 || x >= n || y < 0 || y >= m) {
			return;
		}
        if (find || visited[x][y])
			return;
		if (board[x][y] != word[pose])
			return;
		if (pose == word.length() - 1) {
			find = true;
			return;
		}
		visited[x][y] = true;
		backtracking(board, word, visited, pose + 1, x + 1, y, find);
		backtracking(board, word, visited, pose + 1, x, y + 1, find);
		backtracking(board, word, visited, pose + 1, x - 1, y, find);
		backtracking(board, word, visited, pose + 1, x, y - 1, find);
		visited[x][y] = false;
	}
};
```

## 05、替换空格

请实现一个函数，把字符串 `s` 中的每个空格替换成"%20"。

**示例：**

```
输入：s = "We are happy."
输出："We%20are%20happy."
```

**例程**

```c++
class Solution {
public:
    string replaceSpace(string s) {
        int oriLenght = s.length();
		int spaceNum = 0;
		for (int i = 0; i < oriLenght; i++) {
			if (s[i] == ' ')
				spaceNum++;
		}
		int newLenght = oriLenght + spaceNum * 2;
		string ans(newLenght, ' ');
		newLenght--;
		while (oriLenght) {
			if (s[oriLenght - 1] == ' ') {
				ans[newLenght--] = '0';
				ans[newLenght--] = '2';
				ans[newLenght--] = '%';
			}
			else {
				ans[newLenght--] = s[oriLenght-1];
			}
			oriLenght--;
		}
		return ans;
    }
};
```

## 13、机器人的运动范围

地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

**示例1：**

```
输入：m = 2, n = 3, k = 1
输出：3
```

**示例2：**

```
输入：m = 3, n = 1, k = 0
输出：1
```

**思路**

广度优先搜索或者深度优先搜索

**例程**

```c++
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
		int count = 0;
		count += dfs(visited, 0, 0, m, n, k);
		return count;
    }
    int dfs(vector<vector<bool>>& visited, int x, int y, int m, int n, int k) {
		if (x < 0 || x >= m || y < 0 || y >= n) {
			return 0;
		}
		if (visited[x][y])
			return 0;
		if (!checkVisited(x, y, k)) {
			return 0;
		}
		visited[x][y] = true;
		int count = 1;
		count += dfs(visited, x + 1, y, m, n, k);
		count += dfs(visited, x, y + 1, m, n, k);
		count += dfs(visited, x - 1, y, m, n, k);
		count += dfs(visited, x, y - 1, m, n, k);
		return count;
	}
	bool checkVisited(int x, int y, int k) {
		int num = 0;
		while (x) {
			num += x % 10;
			x = x / 10;
		}
		while (y) {
			num += y % 10;
			y = y / 10;
		}
		if (num > k)
			return false;
		return true;
	}
};
```

## 06、从尾到头打印链表

输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

**示例1：**

```
输入：head = [1,3,2]
输出：[2,3,1]
```

**例程**

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int>ans;
		helper(ans, head);
		return ans;
    }
    void helper(vector<int>& ans, ListNode* head) {
		if (head) {
			helper(ans, head->next);
			ans.push_back(head->val);
		}
	}
};
```

## 07、重建二叉树

输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。

假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

**示例1：**

![img](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**例程：**

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
			return nullptr;
		unordered_map<int, int>inorderMap;
		for (int i = 0; i < inorder.size(); i++) {
			inorderMap[inorder[i]] = i;
		}
		TreeNode* root = buildTreeHelper(preorder, inorderMap, 0, preorder.size() - 1, 0);
		return root;
    }
    TreeNode* buildTreeHelper(vector<int>& preorder, unordered_map<int, int>&inorderMap, int s1, int e1, int s2) {
		if (s1 > e1)
			return nullptr;
		TreeNode* root = new TreeNode(preorder[s1]);
		int pose = inorderMap[preorder[s1]];
		int leftLength = pose - s2;
		int leftStart = s1 + 1;
		int leftEnd = s1 + leftLength;
		int rightStart = s1 + leftLength + 1;
		int rightEnd = e1;
		root->left = buildTreeHelper(preorder, inorderMap, leftStart, leftEnd, s2);
		root->right = buildTreeHelper(preorder, inorderMap, rightStart, rightEnd, s2 + leftLength + 1);
        return root;
	}
};
```

## 14、 剪绳子1

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

**示例1：**

```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

**示例2：**

```
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
```

**例程**

```c++
class Solution {
public:
    int cuttingRope(int n) {
        vector<int> dp(n + 1, 1);
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j < i; j++) {
				dp[i] = max(dp[i], max(dp[i - j], i-j) * j);
			}
		}
		return dp[n];
    }
};
```

## 14、剪绳子2

给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m - 1] 。请问 k[0]*k[1]*...*k[m - 1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。

**示例1：**

```
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
```

**示例2：**

```
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
```

**例程**

```c++
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 4)
			return n - 1;
		long ans = 1;
		while (n > 4) {
			ans = ans * 3 % 1000000007;
			n -= 3;
		}
		return int(ans * n % 1000000007);
    }
};
```

## 25、合并两个排序的链表

输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

**示例1**

```
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
```

**例程**

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0), * cur = head;
		while (l1 && l2) {
			if (l1->val > l2->val) {
				cur->next = l2;
				l2 = l2->next;
                cur = cur->next;
			}
			else {
				cur->next = l1;
				l1 = l1->next;
                cur = cur->next;
			}
		}
		if (l1) {
			cur->next = l1;
		}
		if (l2) {
			cur->next = l2;
		}
		return head->next;
    }
};
```

## 26、树的子结构

输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)

B是A的子结构， 即 A中有出现和B相同的结构和节点值。

例如:
给定的树 A:

```
     3
    / \
   4   5
  / \
 1   2
```

给定的树 B：

```
   4 
  /
 1
```

返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。

**示例1：**

```
输入：A = [1,2,3], B = [3,1]
输出：false
```

**示例2：**

```
输入：A = [3,4,5,1,2], B = [4,1]
输出：true
```

**例程**

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!B)
			return false;
		bool ans = true;
		help1(A, B, ans);
		return ans;
    }
    void help1(TreeNode* A, TreeNode* B, bool& ans) {
		if (!ans)
			return;
		help2(A, B, ans);
		if (!ans && A && A->left) {
			ans = true;
			help1(A->left, B, ans);
		}
		if (!ans && A && A->right) {
			ans = true;
			help1(A->right, B, ans);
		}
	}
	void help2(TreeNode* A, TreeNode* B, bool& ans) {
		if (!ans)
			return;
		if (!A && B) {
			ans = false;
			return;
		}
		if (!B)
			return;
		if (A->val != B->val) {
			ans = false;
			return;
		}
		help2(A->left, B->left, ans);
		help2(A->right, B->right, ans);
	}
};
```



