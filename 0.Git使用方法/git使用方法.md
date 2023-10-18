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

![7.GitKey.png](https://github.com/CaiNiao-Z/Test_Project_Github/edit/main/0.Git使用方法/img/7.GitKey.png)

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

![5.git.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\5.git.png)

## git代码拉取

```
git pull origin main   			# 从远端仓库拉取文件到本地 可以省略为git pull
```

![0.git_pull.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\0.git_pull.png)

## git pull 部分文件无法获取时：

今天发现git pull origin master 的时候部分文件无法获取，然后学到了一个新方法：git fetch

```
# 可以单独获取github 仓库中的单个文件
git checkout origin/master -- 文件/文件夹名称 (path/to/file)
```

![1.git_fetch.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\1.git_fetch.png)

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

![2.git_rm.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\2.git_rm.png)

```
# 提交到本地并推送到远程服务器
git commit -m "提交说明"
```

![3.git_commit.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\3.git_commit.png)

```
git push origin 远程仓库分支(branches) # 略写 git pull
```

![4.git_pull.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\4.git_pull.png)



## 常见错误：

### 1.使用git push提交代码时，出现如下错误。

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

![6.git_error.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\6.git_error.png)

**解决办法：**

使用-f参数

![6.git_solve.png](E:\GitProject\Test_Project_Github\0.Git使用方法\img\6.git_solve.png)

### 2.使用git add向缓存区提交文件时，出现如下警告。

```
$ E:\GitProject\Test_Project_Github>git add 4.TEST_PROJECT_ALL_MODEL

warning: in the working copy of '4.TEST_PROJECT_ALL_MODEL/MDK-ARM/TEST_PROJECT.uvguix.30832', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of '4.TEST_PROJECT_ALL_MODEL/MDK-ARM/TEST_PROJECT.uvoptx', LF will be replaced by CRLF the next time Git touches it
warning: in the working copy of '4.TEST_PROJECT_ALL_MODEL/MDK-ARM/TEST_PROJECT.uvprojx', LF will be replaced by CRLF the next time Git touches it
```

git工作区默认为CRLF来作为换行符。如果 改动文件时引入了 LF,提交改动时，git 会警告你哪些文件不是纯 CRLF 文件，但 git 不会擅自修改工作区的那些文件，而是对暂存区（我们对工作区的改动）进行修改。也因此，当我们进行 git add 的操作时，只要 git 发现改动的内容里有 LF 换行符，就还会出现这个警告。

```
#提交检出均不转换
$ git config --global core.autocrlf false
```

**扩展：关于换行和回车。**

1. 由来

在计算机还没有出现之前，有一种叫做电传打字机的机械打字机，每秒钟可以打10个字符。但是它有一个问题，就是打完一行换行的时候，要用去0.2秒，正好可以打两个字符。要是在这0.2秒里面，又有新的字符传过来，那么这个字符将丢失。于是，研制人员想了个办法解决这个问题，就是在每行后面加两个表示结束的字符。一个叫做“回车”，告诉打字机把打印头定位在左边界，不卷动滚筒；另一个叫做“换行”，告诉打字机把滚筒卷一格，不改变水平位置。这就是“换行”和“回车”的由来。

2. 使用

后来，计算机发明了，这两个概念也就被般到了计算机上。那时，存储器很贵，一些科学家认为在每行结尾加两个字符太浪费了，加一个就可以。于是，就出现了分歧。

回车 \r 本义是光标重新回到本行开头，r的英文return，控制字符可以写成CR，即Carriage Return

换行 \n 本义是光标往下一行（不一定到下一行行首），n的英文newline，控制字符可以写成LF，即Line Feed

符号 ASCII码 意义

\n 10 换行NL

\r 13 回车CR

在不同的操作系统这几个字符表现不同，比如在WIN系统下，这两个字符就是表现的本义，在UNIX类系统，换行\n就表现为光标下一行并回到行首，在MAC上，\r就表现为回到本行开头并往下一行，至于ENTER键的定义是与操作系统有关的。通常用的Enter是两个加起来。

不同操作系统下的含义：

\n: UNIX 系统行末结束符

\r\n: window 系统行末结束符

\r: MAC OS 系统行末结束符

我们经常遇到的一个问题就是，Unix/Mac系统下的文件在Windows里打开的话，所有文字会变成一行；而Windows里的文件在Unix/Mac下打开的话，在每行的结尾可能会多出一个^M符号。

3. 软回车和硬回车

再扩展一下回车的一些知识。

硬回车就是普通我们按回车产生的，它在换行的同时也起着段落分隔的作用。

软回车是用 Shift + Enter 产生的，它换行，但是并不换段，即前后两段文字在 Word 中属于同一“段”。在应用格式时你会体会到这一点。

软回车能使前后两行的行间距大幅度缩小，因为它不是段落标记，要和法定的段落标记——硬回车区别出来。硬回车的html代码是

…

，段落的内容就夹在里面，而软回车的代码很精悍：
网页的文字如果复制到word中，则硬回车变为弯曲的箭头，软回车变为向下的箭头。
