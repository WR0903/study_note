# github通过终端上传文件的方法

* 首先建立本地仓
在本地项目目录创建本地仓库`git init`  
输入个人信息(代码提交者)  
`git config --global user.name "xxxx" `
`git config --global user.email xxxxx@qq.com`
新建repository,注意复制红圈标记的地址  
![](1.jpg)  
![](2.jpg)  
关联本地仓库并上传代码  
`git remote add origin https://github.com/Yanyf765/hr_sys.git（上步骤复制的地址）`

* 本地仓上传方法
首先在环境目录建立`.md`文件  
`git status` 查看工作目录的变化  
`git add .` 上交文件  
`git commit -m "<备注内容>" `备注一下  
`git push origin master` 上传成功  
在MD文件里写`![](1.jpg)`表示插入图片  
