# Git笔记
---
### 1.1 Git安装
在Windows上安装Git

在Windows上使用Git，可以从Git官网直接下载安装程序，然后按默认选项安装即可。
安装完成后，在开始菜单里找到“Git”->“Git Bash”，蹦出一个类似命令行窗口的东西，就说明Git安装成功！
安装完成后，还需要最后一步设置，在命令行输入：

	$ git config --global user.name "Your Name"
	$ git config --global user.email "email@example.com"

### 1.2 创建版本库
版本库又名仓库，英文名repository，你可以简单理解成一个目录，这个目录里面的所有文件都可以被Git管理起来，每个文件的修改、删除，Git都能跟踪，以便任何时刻都可以追踪历史，或者在将来某个时刻可以“还原”。

创建一个库

首先创建一个空目录

	$ mkdir learngit
	$ cd learngit
	$ pwd
	/Users/michael/learngit

再通过git init命令把这个目录变成Git可以管理的仓库：

	$ git init
	Initialized empty Git repository in /Users/michael/learngit/.git/

第三步编写自己的文档/copy

第四步用命令git add告诉Git，把文件添加到缓冲区，这其中可以分别多个add命令把文件添加到缓冲区：

	$ git add readme.txt

第五步用命令git commit告诉Git，把在缓冲区的文件提交到仓库

	$ git commit -m "wrote a readme file"
	[master (root-commit) eaadf4e] wrote a readme file
	 1 file changed, 2 insertions(+)
	 create mode 100644 readme.txt

简单解释一下git commit命令，-m后面输入的是本次提交的说明，可以输入任意内容，当然最好是有意义的，这样你就能从历史记录里方便地找到改动记录。

### 2.1 版本回退

当修改文件，然后把修改提交到Git版本库，像这样，你不断对文件进行修改，然后不断提交修改到版本库里，就好比玩RPG游戏时，每通过一关就会自动把游戏状态存盘，如果某一关没过去，你还可以选择读取前一关的状态。有些时候，在打Boss之前，你会手动存盘，以便万一打Boss失败了，可以从最近的地方重新开始。Git也是一样，每当你觉得文件修改到一定程度的时候，就可以“保存一个快照”，这个快照在Git中被称为commit。一旦你把文件改乱了，或者误删了文件，还可以从最近的一个commit恢复，然后继续工作，而不是把几个月的工作成果全部丢失。
查看版本日记 git log命令

	$ git log
	commit 1094adb7b9b3807259d8cb349e7df1d4d6477073 (HEAD -> master)
	Author: xxx <SHL@qq.com>
	Date:   Fri May 18 21:06:15 2018 +0800
	
	    append GPL
	
	commit e475afc93c209a690c39c13a46716e8fa000c366
	Author: Michael Liao <askxuefeng@gmail.com>
	Date:   Fri May 18 21:03:36 2018 +0800
	
	    add distributed
	
	commit eaadf4e385e865d25c48e7ca9c8395c3f7dfaef0
	Author: Michael Liao <askxuefeng@gmail.com>
	Date:   Fri May 18 20:59:18 2018 +0800
	
	    wrote a readme file

需要友情提示的是，你看到的一大串类似1094adb...的是commit id（版本号），和SVN不一样，Git的commit id不是1，2，3……递增的数字，而是一个SHA1计算出来的一个非常大的数字，用十六进制表示，而且你看到的commit id和我的肯定不一样，以你自己的为准。为什么commit id需要用这么一大串数字表示呢？因为Git是分布式的版本控制系统，后面我们还要研究多人在同一个版本库里工作，如果大家都用1，2，3……作为版本号，那肯定就冲突了。

版本回退/时空机回到过去

首先，Git必须知道当前版本是哪个版本，在Git中，用HEAD表示当前版本，也就是最新的提交1094adb...（注意我的提交ID和你的肯定不一样），上一个版本就是HEAD^，上上一个版本就是HEAD^^，当然往上100个版本写100个^比较容易数不过来，所以写成HEAD~100（HEAD指的是指向当前分支版本文件的指针）。

返回上一版本

	$ git reset --hard HEAD^
	HEAD is now at e475afc add distributed

在Git中，总是有后悔药可以吃的。当你用$ git reset --hard HEAD^回退到add distributed版本时，再想恢复到append GPL，就必须找到append GPL的commit id。Git提供了一个命令git reflog用来记录你的每一次命令：

	$ git reflog
	e475afc HEAD@{1}: reset: moving to HEAD^
	1094adb (HEAD -> master) HEAD@{2}: commit: append GPL
	e475afc HEAD@{3}: commit: add distributed
	eaadf4e HEAD@{4}: commit (initial): wrote a readme

### 2.2 工作区和暂存区

![](https://www.liaoxuefeng.com/files/attachments/919020037470528/0)

前面讲了我们把文件往Git版本库里添加的时候，是分两步执行的：

第一步是用git add把文件添加进去，实际上就是把文件修改添加到暂存区；

第二步是用git commit提交更改，实际上就是把暂存区的所有内容提交到当前分支。

因为我们创建Git版本库时，Git自动为我们创建了唯一一个master分支，所以，现在，git commit就是往master分支上提交更改。

你可以简单理解为，需要提交的文件修改通通放到暂存区，然后，一次性提交暂存区的所有修改。

Git管理的文件分为：工作区，版本库，版本库又分为暂存区stage和暂存区分支master(仓库)

工作区>>>>暂存区>>>>仓库

git add把文件从工作区>>>>暂存区，git commit把文件从暂存区>>>>仓库，

git diff查看工作区和暂存区差异，

git diff --cached查看暂存区和仓库差异，

git diff HEAD 查看工作区和仓库的差异，

git add的反向命令git checkout，撤销工作区修改，即把暂存区最新版本转移到工作区，

git commit的反向命令git reset HEAD，就是把仓库最新版本转移到暂存区。

### 2.3 管理修改
Git跟踪并管理的是修改，而非文件。

你会问，什么是修改？比如你新增了一行，这就是一个修改，删除了一行，也是一个修改，更改了某些字符，也是一个修改，删了一些又加了一些，也是一个修改，甚至创建一个新文件，也算一个修改。

每次修改，如果不用git add到暂存区，那就不会加入到commit中。

### 2.4 撤销修改

命令git checkout -- readme.txt意思就是，把readme.txt文件在工作区的修改全部撤销，这里有两种情况：

一种是readme.txt自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

一种是readme.txt已经添加到暂存区后，又作了修改，现在，撤销修改就回到添加到暂存区后的状态。

总之，就是让这个文件回到最近一次git commit或git add时的状态。

	场景1：当你改乱了工作区某个文件的内容，想直接丢弃工作区的修改时，用命令git checkout -- file。
	
	场景2：当你不但改乱了工作区某个文件的内容，还添加到了暂存区时，想丢弃修改，分两步，第一步用命令git reset HEAD <file>，就回到了场景1，第二步按场景1操作。
	
	场景3：已经提交了不合适的修改到版本库时，想要撤销本次提交，参考版本回退一节，不过前提是没有推送到远程库。

### 2.5 删除文件

在Git中，删除也是一个修改操作，我们实战一下，先添加一个新文件test.txt到Git并且提交：

	$ git add test.txt
	
	$ git commit -m "add test.txt"
	[master b84166e] add test.txt
	 1 file changed, 1 insertion(+)
	 create mode 100644 test.txt

一般情况下，你通常直接在文件管理器中把没用的文件删了，或者用rm命令删了：

	$ rm test.txt

这个时候，Git知道你删除了文件，因此，工作区和版本库就不一致了，git status命令会立刻告诉你哪些文件被删除了：

现在你有两个选择，一是确实要从版本库中删除该文件，那就用命令git rm删掉，并且git commit：

	$ git rm test.txt
	rm 'test.txt'
	
	$ git commit -m "remove test.txt"
	[master d46f35e] remove test.txt
	 1 file changed, 1 deletion(-)
	 delete mode 100644 test.txt
