# Adding git's binaries (and ssh) to your Windows path

After downloading and installing git, you still might encounter problems when trying to issue `vagrant ssh` commands.  This is because the git installed didn't automatically add itself to your environment path.  Here's how to do this if you do not already know.

## Step 1 - Find your git\bin directory
Git installed itself in Program Files (or, possibley Program Files (x86)).  Browse to that directory and go into the `bin` directory.  Copy the full address (`ctrl+c`).

<img src='git_path_images\1.png'>

## Step 2 - Access your environment variables.

From the start menu, right click Computer and choose **Properties**

<img src='git_path_images\2.png'>

Choose **Advanced Settings**

<img src='git_path_images\3.png'>

Choose **Environment Variables**

<img src='git_path_images\4.png'>

If you have a **PATH** entry in the system variables, then click **Edit**, if you don't already have PATH - then click **New**

<img src='git_path_images\5.png'>

## Step 3 - Add the git bin folder to your PATH
The PATH value (*your path string*) is a list of all the folders that the command prompt will search when you type commands.  You need to make sure that when `ssh` is typed, the command prompt searches the git directory.  Each directory in your PATH string is separated by a semi-colon (;)

Now paste the file path you copied earlier into the *beginning* of the PATH variable string and separate it from the rest with a semi-colon.  If you didn't have a PATH originally, the trailing semi-colon is optional.

<img src='git_path_images\6.png'>

Press OK, OK, OK.... until you've closed all the dialogs you've openned.  

## Step 4 - testing ssh
Close any command prompt window you have open (it reads the PATH variable when it starts, so it won't see any changes you've made).  

Restart the command prompt and type `ssh`.  If all is well, you should see something like this:

<img src='git_path_images\7.png'>

If you do, proceed to do the vagrant install as specified [here](vagrant.html)