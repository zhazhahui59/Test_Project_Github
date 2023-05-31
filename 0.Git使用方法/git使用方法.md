# git使用方法

## 创建远程仓库：

## 与本地仓库建立关系：

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

![image-20230531093609093](E:\Test_Project_Github\0.Git使用方法\img\5.git.png)

## git代码拉取

```
git pull origin main   			# 从远端仓库拉取文件到本地 可以省略为git pull
```

![image-20230531093144738](E:\Test_Project_Github\0.Git使用方法\img\0.git_pull.png)

## git pull 部分文件无法获取时：

今天发现git pull origin master 的时候部分文件无法获取，然后学到了一个新方法：git fetch

```
# 可以单独获取github 仓库中的单个文件
git checkout origin/master -- 文件/文件夹名称 (path/to/file)
```

![image-20230531091013911](E:\Test_Project_Github\0.Git使用方法\img\1.git_fetch.png)

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

![image-20230531092406746](E:\Test_Project_Github\0.Git使用方法\img\2.git_rm.png)

```
# 提交到本地并推送到远程服务器
git commit -m "提交说明"
```

![image-20230531092539563](E:\Test_Project_Github\0.Git使用方法\img\3.git_commit.png)

```
git push origin 远程仓库分支(branches) # 略写 git pull
```

![image-20230531092744814](E:\Test_Project_Github\0.Git使用方法\img\4.git_pull.png)



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

![image-20230531095436635](E:\Test_Project_Github\0.Git使用方法\img\6.git_error.png)

**解决办法：**

使用-f参数

![image-20230531095722222](E:\Test_Project_Github\0.Git使用方法\img\6.git_solve.png)

