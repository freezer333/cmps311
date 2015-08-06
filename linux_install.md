# Installing Linux in a Dual-Boot Environment
Linux comes in many flavors (distributions), nearly all of which are completely free of charge.  If you’ve never attempted to install Linux on a machine, its a good idea to do so.  Linux is enormously popular in the programming community, and you will likely need to use it many times in your career.  Bluntly, a computer science grad who's never installed or worked on Linux is at distinct disadvantage entering the workforce!

The recommended option is to configure a dual-boot machine, allowing you to run Windows or Linux by choosing which OS to launch at boot.  I have used Ubuntu and Linux Mint in dual-boot scenarios, and both are quite easy to install.

Warning:  While dual-booting your machine likely will go smoothly, I can’t make any promises!  There is a real chance that something could go wrong, and that you could need to reinstall Windows.  This means you could lose your data!  Please, backup your computer before attempting to install LInux.  You are responsible for taking on the risk.  

For easy steps to download and install Linux, see the links below.  Please note, in all cases, its critical that you choose either 32-bit or 64-bit version, depending on your own machine.

- [Instructions for installing Ubuntu Linux alongside (dual-boot) Windows](http://www.ubuntu.com/download/desktop/install-desktop-long-term-support)
- [Instructions for creating Linux Mint installation USB/Disk](http://community.linuxmint.com/tutorial/view/744)
- [Instructions for installing Linux Mint alongside (dual-boot) Windows](http://itsfoss.com/guide-install-linux-mint-16-dual-boot-windows/).  Note, for Step 4 - Installation Type, you can just choose “Install Linux Mint alongside...” instead of creating customized partitions.  You’ll then skip right to step 6.

## Virtual Machines
As an alternative, you could also install Linux within a Virtual Machine such as [Virtaul Box](https://www.virtualbox.org/wiki/Downloads) or [VMWare](http://www.vmware.com/products/fusion/).  This option allows you to run a full Linux environment while simultaneously working with Windows.  

Finally, you can do a more minimal Linux installation using Vagrant, which I've outlined [here](vagrant.html)