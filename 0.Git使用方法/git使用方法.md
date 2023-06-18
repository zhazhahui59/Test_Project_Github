# git使用方法

## 创建Github远程仓库：

注册github，然后创建一个仓库（略……）

## 与本地仓库建立关系：

可以参考 https://www.runoob.com/w3cnote/git-guide.html 该教程，需要注意的是，要现在本地目录（准备存放github仓库文件的本地目录）中使用git init指令。不然的话在执行**git remote add origin git@github.com:yourName/yourRepo.git**指令链接远端仓库时会报如下错误：**fatal: not a git repository (or any of the parent directories): .git**

### 配置Git

首先在本地创建`ssh key；`

```
$ ssh-keygen -t rsa -C "your_email@youremail.com"
```

后面的`your_email@youremail.com`改为你在github上注册的邮箱，之后会要求确认路径和输入密码，我们这使用默认的一路回车就行。成功的话会在`~/`下生成`.ssh`文件夹，进去，打开`id_rsa.pub`，复制里面的`key`。

回到github上，进入 Account Settings（账户配置），左边选择SSH Keys，Add SSH Key,title随便填，粘贴在你电脑上生成的key。

![image-20230618171640799](E:\GitProject\Test_Project_Github\0.Git使用方法\img\7.GitKey.png)

为了验证是否成功，在git bash下输入：

```
$ ssh -T git@github.com
```

如果是第一次的会提示是否continue，输入yes就会看到：You've successfully authenticated, but GitHub does not provide shell access 。这就表示已成功连上github。

接下来我们要做的就是把本地仓库传到github上去，在此之前还需要设置username和email，因为github每次commit都会记录他们。

```
$ git config --global user.name "your name"
$ git config --global user.email "your_email@youremail.com"
```

进入要上传的仓库，右键git bash，

初始化本地仓库：

```
$ git init
```

添加远程地址：

```
$ git remote add origin git@github.com:yourName/yourRepo.git
```

后面的yourName和yourRepo表示你再github的用户名和刚才新建的仓库，加完之后进入.git，打开config，这里会多出一个remote "origin"内容，这就是刚才添加的远程地址，也可以直接修改config来配置远程地址。

创建新文件夹，打开，然后执行` git init` 以创建新的 git 仓库。检出仓库执行如下命令以创建一个本地仓库的克隆版本：`git clone /path/to/repository `

如果是远端服务器上的仓库，你的命令会是这个样子：`git clone username@host:/path/to/repository`

## 常用指令操作：

### git代码提交：

```
git add 文件/文件夹名称 (path/to/file) # 提交单个文件/文件夹
```

```
git add .    					# 提交本地仓库所有的文件。
git commit -m "提交说明"       	 # 提交说明
git push origin main			# 将提交的内容推送到远端仓库 可以省略为git push
```

![image-20230531093609093](E:\GitProject\Test_Project_Github\0.Git使用方法\img\5.git.png)

## git代码拉取

```
git pull origin main   			# 从远端仓库拉取文件到本地 可以省略为git pull
```

![image-20230531093144738](E:\GitProject\Test_Project_Github\0.Git使用方法\img\0.git_pull.png)

## git pull 部分文件无法获取时：

今天发现git pull origin master 的时候部分文件无法获取，然后学到了一个新方法：git fetch

```
# 可以单独获取github 仓库中的单个文件
git checkout origin/master -- 文件/文件夹名称 (path/to/file)
```

![image-20230531091013911](E:\GitProject\Test_Project_Github\0.Git使用方法\img\1.git_fetch.png)

## git rm 删除远程仓库代码:

```
# 加上 -n 这个参数，执行命令时，是不会删除任何文件，而是展示此命令要删除的文件列表预览。
确定无误后删除文件
git rm -r -n --cached 文件/文件夹名称(path/to/file) 
```

```
# 删除
git rm -r --cached 文件/文件夹名称(path/to/file)
```

![image-20230531092406746](E:\GitProject\Test_Project_Github\0.Git使用方法\img\2.git_rm.png)

```
# 提交到本地并推送到远程服务器
git commit -m "提交说明"
```

![image-20230531092539563](E:\GitProject\Test_Project_Github\0.Git使用方法\img\3.git_commit.png)

```
git push origin 远程仓库分支(branches) # 略写 git pull
```

![image-20230531092744814](E:\GitProject\Test_Project_Github\0.Git使用方法\img\4.git_pull.png)



## 常见错误：

### 使用git push提交代码时，出现如下错误。

```
$ git push origin main
To github.com:CaiNiao-Z/Test_Project_Github.git
 ! [rejected]        main -> main (fetch first)
error: failed to push some refs to 'github.com:CaiNiao-Z/Test_Project_Github.git'
hint: Updates were rejected because the remote contains work that you do
hint: not have locally. This is usually caused by another repository pushing
hint: to the same ref. You may want to first integrate the remote changes
hint: (e.g., 'git pull ...') before pushing again.
hint: See the 'Note about fast-forwards' in 'git push --help' for details.
```

![image-20230531095436635](E:\GitProject\Test_Project_Github\0.Git使用方法\img\6.git_error.png)

**解决办法：**

使用-f参数

![image-20230531095722222](E:\GitProject\Test_Project_Github\0.Git使用方法\img\6.git_solve.png)

