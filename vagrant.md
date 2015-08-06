# Installing Ubuntu Linux using Vagrant virtualization
In CMPS 311 you will be asked to write programs that target the Unix (or a Unix-like) operating system.  If you have a Mac OS X computer, you may use this; however there are small areas where your programs might differ from those presented in class.  If you only have access to a Windows computer, you *must* get access to a Unix-like system as well - which this document will help you with.  If you are a Mac user, this document might still be relevant, if you want to use the same platform as I will when testing your code.

If you are already using Linux, then you likely do not need to read on - unless you are interested in seeing how virtualization works.

> Note - this document is for CMPS 311 students, and is written with student who have limited or no experience using linux or unix systems.  If you already have experience with linux, you might want to just go to Vagrant's website and follow the Getting Started section - which is a little more succinct.

## Notes about other options
While you will need to have access to a Unix system, there are actually a whole bunch of ways to do this.  The college has a Linux server, which you can access using ssh.  You can dual-boot your computer to run a full-fledged Linux installation.  You can also install Linux as a virtual machine using free software like VirtualBox or paid-software like VMWare. You caould also dual-boot.  I've provided some additional information on this [here](linux_install.html) 

In this document, I will show you likely the *easiest* way to get up and running - executing code in a linux environment.  It is not necessarily the best way, but it lets you continue to work relatively seamlessly in your familiar environment.  You'll use source code editors in your normal operating system (you could even use Visual Studio, although I'll show you Sublime Text).  You'll compile and run your code in a virtual machine running linux though.  

The virtualization software I'll use in this document is called [Vagrant](https://www.vagrantup.com/).  It is free software.  It actually depends on VirtualBox, so the first step is to download both.

## Download Vagrant and VirtualBox
Go to the Vagrant [download link](https://www.vagrantup.com/downloads) and be sure to choose the right platform (Mac OS X, Windows).

Go to the VirtualBox [download link](https://www.virtualbox.org/wiki/Downloads) and make sure you download the install for the right platform as well (under VirtualBox platform packages)

## Installing your Software

### Installing Vagrant on a Mac
* Download the .dmg file and save it to your desktop
* Double-click the .dmg file and then double click the vagrant.pkg file.
* Keep all the default installation options, and provide your password when asked.
* That should be it... for vagrant

### Install Virtual Box on a Mac
* Download the .dmg file and save it to your desktop
* Double-click the .dmg file and then double click the VirtualBox.pkg file.
* Keep all the default installation options, and provide your password when asked.
* That's it.

## Getting a linux installation
Now we're going to install a linux operating system which will run in a virtualized environment on your computer.  Its extremely easy to do - and we'll install a plainn 32-bit Ubuntu edition of Linux.  See [vagrant's documentation](https://docs.vagrantup.com/v2/getting-started/index.html) for listings of many other versions of linux that you can install.

Open your terminal (or command prompt on Windows).  Navigate (using `cd`)to the directory you'd like to install your guest linux installation within.

```
$ mkdir cmps311
$ cd cmps311
$ mkdir linux
$ cd linux
```


Type the following:

```
$ vagrant init hashicorp/precise32
$ vagrant plugin install vagrant-vbguest
$ vagrant up
```
Once you've run this (it will take a bit of time, and download lots of stuff), there is an operating system running in the background on your machine.  Its essentially a separate machine.  The first command gets the setup file from the cloud.  The second command is a plugin that I recommend when using virtual box to ensure you can use shared fodlers correctly ([read more here](http://kvz.io/blog/2013/01/16/vagrant-tip-keep-virtualbox-guest-additions-in-sync/)).  The third commmand is what starts up your virtual machine.

To connect to separate machines you generally use ssh - a network protocol for logging in and interacting with unix-based operating systems from the command line.  You can use ssh to connect to your new linux machine running in the backgroun too - type the following:

```
$ vagrant ssh
```
Once the ssh shell has started, you are logged into linux and can issue commands.

### Problems with git
After typing `vagrant ssh` you might see a message something like this:
```
'ssh' executable not found in any directories in the %PATH% variable.  Is an ssh client installed?....
```
This means you do not have a version of git on your machine - which is easy to get.  For Windows, download and install the [windows git](http://git-scm.com/download/win).  For a Mac, get the [OS X version](http://git-scm.com/download/mac).  After installing git fully, **close the command prompt** and start with a new command prompt (cd to your linux directory, and try `vagrant ssh` again).  If you still have problems, particularly on Windows, see info about setting up your PATH [here](git_path.html)

## Testing things out - test.c
We'll program mostly in C in this course.  Lets use the build tools, in conjunction with our own editor, to build and run a simple program that says hello, and tells us what operating system we are running.

First, we need to understand a little about how the linux file system maps to your *host* filesystem.  Your host is your normal operating system - the one you have likely have a bunch of windows and web browsers open on now.  The linux OS running in vagrant is installed within it - running in the background, accessible via command line ssh.

In vagrant's ssh session, type the following:

```
$  ls -al
```
If you are used to `dir` in windows, this is the same thing for unix systems - it lists directories.  You likely only have one actual file - `postinstall.sh` - the rest are just hidden files.

```
total 48
drwxr-xr-x 4 vagrant vagrant 4096 Sep 14  2012 .
drwxr-xr-x 3 root    root    4096 Sep 14  2012 ..
-rw------- 1 vagrant vagrant  192 Jan  5 17:45 .bash_history
-rw-r--r-- 1 vagrant vagrant  220 Sep 14  2012 .bash_logout
-rw-r--r-- 1 vagrant vagrant 3486 Sep 14  2012 .bashrc
drwx------ 2 vagrant vagrant 4096 Sep 14  2012 .cache
-rwxr-xr-x 1 vagrant vagrant 6487 Sep 14  2012 postinstall.sh
-rw-r--r-- 1 vagrant vagrant  675 Sep 14  2012 .profile
drwx------ 2 vagrant vagrant 4096 Jan  5 17:31 .ssh
-rw-r--r-- 1 vagrant vagrant    0 Sep 14  2012 .sudo_as_admin_successful
-rw------- 1 vagrant vagrant    6 Sep 14  2012 .vbox_version
-rw------- 1 vagrant vagrant   12 Sep 14  2012 .veewee_version
```

Your home directory is located within the vagrant VM - its not directly accessible through the host operating system.  However, vagrant automatically mounts the **current working directory** in your host system to the `/vagrant` folder within your virtual machine.  This makes things really easy to when using tools in your host operating system (Mac or Windows).

Type `pwd`, and unix systems tell you your current working directory - you'll see it respond with `/home/vagrant`.  Now change to `/vagrant` by typing `cd /vagrant`.  Type `ls -al` again you you'll see only the `Vagrantfile` - which is a settings file for you VM (don't touch it!)

```
total 8
drwxr-xr-x  1 vagrant vagrant  136 Jan  5 17:30 .
drwxr-xr-x 23 root    root    4096 Jan  5 17:34 ..
drwxr-xr-x  1 vagrant vagrant  102 Jan  5 17:30 .vagrant
-rw-r--r--  1 vagrant vagrant 3001 Jan  5 17:26 Vagrantfile
```

### Writing some code
Open up a programming editor, which ever you prefer to use on your normal machine.  Note, if you are using Windows - Visual Studio is OK - but you don't COMPILE with Visual Studio, you will compile using the linux commands native to the virtual machine we've created.  

I recommend you use something like [Sublime Text](http://www.sublimetext.com/3) or [GitHub's atom](https://atom.io/) instead - these are simply source code editors, not complete compilers.  Things will be simpler for you...

Now, lets write a short C program that outputs the operating system it is running on.  

``` cpp

#include <sys/utsname.h>
#include <stdio.h>

int main() {
    struct utsname data;

    uname(&data); 

    printf("This program is running on %s\n", data.sysname);
}
```
Now save this file as `test.c` into the `cmps311/linux` folder on your host machine.  

Remember, vagrant has mounted the cmps311/linux folder to /vagrant in the virtual machine.  From the terminal, still logged into the virtual machine, type `ls -al` again.  You should see something like this:

```
total 12
drwxr-xr-x  1 vagrant vagrant  170 Jan  5 17:38 .
drwxr-xr-x 23 root    root    4096 Jan  5 17:34 ..
-rw-rw-r--  1 vagrant vagrant  166 Jan  5 17:38 test.c
drwxr-xr-x  1 vagrant vagrant  102 Jan  5 17:30 .vagrant
-rw-r--r--  1 vagrant vagrant 3001 Jan  5 17:26 Vagrantfile

```

So - there is a connection between your host operating system (Mac or Windows) and the virtual machine (linux).  You can edit and save files in your host's `cmps311/linux` folder, and work with the very same files in linux within the `/vagrant` folder.


### Compiling and running on linux
Now lets compile our program.   From the terminal (logged into the linux VM), type the following command to compile the source code:

```
gcc -o test test.c

```

If all goes well, another `ls -al` command will turn out something like this (obviously date/timestamps will be different on your machine).

```
total 20
drwxr-xr-x  1 vagrant vagrant  204 Jan  5 17:39 .
drwxr-xr-x 23 root    root    4096 Jan  5 17:34 ..
-rwxr-xr-x  1 vagrant vagrant 7245 Jan  5 17:39 test
-rw-rw-r--  1 vagrant vagrant  166 Jan  5 17:38 test.c
drwxr-xr-x  1 vagrant vagrant  102 Jan  5 17:30 .vagrant
-rw-r--r--  1 vagrant vagrant 3001 Jan  5 17:26 Vagrantfile
```

Now type `./test` at the terminal, you should see this:

```
This program is running on Linux
```

**Note** - it should absolutely say linux.  If it says anything else - Mac/Darwin/Apple/Etc - (on Windows, you wouldn't get past compilation), it means you compiled and ran from your host machine - you weren't logged into the linux virtual machine!  Its tricky - you need to keep this straight!

At this point, you are ready to do all the POSIX code assignments for our course.  Remember, occasionally I will ask you to program in Windows as well - which is a whole other story (you won't use vagrant - just plain old Windows)