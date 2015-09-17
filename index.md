# CMPS 311 - Operating Systems - Fall 2015
**Meeting Time:  **&nbsp;&nbsp;Mondays, Wednesday, and Thursdays, 10:00am - 11:10am
**Location:  **&nbsp;&nbsp;ASB Room 429
**Professor:**&nbsp;&nbsp;Scott Frees, Professor of Computer Science
** Contact Information**
Office&nbsp;&nbsp;G315
Phone&nbsp;&nbsp;(201) 684-7726
Email&nbsp;&nbsp;[sfrees@ramapo.edu](mailto:sfrees@ramapo.edu)
Office Hours &nbsp;&nbsp;Monday 12:45-1:45pm and Thursday 4-5pm

## Course Description
A study of the design, use, and analysis of operating systems. The course will include a study of the supportive computer architecture, memory management, process management, information management, device control, operating systems structure, and evaluation.  

## Pre-Requisites
CMPS 231 Data Structures, CMPS 220 Assembly Language Programming, and MATH 237 Discrete Structures, CRWT 102 Crit. Reading & Writing 2 

## Course Materials
**Textbook** &nbsp;&nbsp; [Modern Operating Systems (4th Edition)](http://www.amazon.com/Modern-Operating-Systems-4th-Edition/dp/013359162X) by Andrew S. Tanenbaum, Herbert Bos. *Note, the textbook is required for this course, and will be relavent to nearly each lecture.*
<img src='http://ecx.images-amazon.com/images/I/51dqadCuRiL._SX390_BO1,204,203,200_.jpg' width="200"/>
<hr class="print-page"/>

## Required Programming Environment
**Attention Microsoft Windows Users** - while we will touch upon the Win32 API, the vast majority of the programming you will do in this course will require you to write C++ code targeting the POSIX API, which is supported by Max OS X and Linux.  You will absolutely be required to program in the POSIX environment, so if you do not currently use OS X or Linux, you'll need to create an environment.  

If you are using Windows, you can install Linux alongside Windows without too much trouble.  You have a few options:

1. You could configure your computer to dual-boot into Windows or Linux.  This is an advanced option - please do so at your own risk!  I'd recommend using either Ubuntu or Linux Mint for easy installation.  I've provided some additional info on this [here](linux_install.html).
2. You could install Linux in a Virtual Machine, such as Virtual Box.  Again, you may choose any Linux distribution but I'd recommend Ubuntu or Mint if you are unfamiliar with Linux.
3.  The least *invasive* option is to simply install a small Linux environment accessible via the command line *while working in Windows*.  This is a great option if you've never used Linux before.  I've prepared detailed instructions, which can be found [here](vagrant.html).

## Course Objectives
* Understand and Program Processes & Threads
* Understand and Evaluate Scheduling / Synchronization / Deadlock algorithms
* Understand Memory Management and Paging Systems used in a typical OS
* Understand and Program with File Systems and understand their implementation
* Understand Security issues involved with an OS
* Understand and evaluate different problems associated with Distributed Systems and Networking
* Understand modern OS directions and trends 

<hr class="print-page"/>
## Lecture Schedule
Below is a tentative schedule for the course.  All topics and due dates are subject to change, and if there is a difference between what is stated here and on Moodle, please always consider Moodle to be correct (and let me know so I can correct the mismatch!).

**You must keep up with the readings** associated with each lecture.  

<div style="margin:0px;padding:0px;overflow:hidden">
    <iframe src="https://docs.google.com/spreadsheets/d/1n673IdE-cTdBn2LY7U1pSpp7N9ARZr4YMpHIrt-LiHg/pubhtml?widget=true&amp;headers=false" frameborder="0" style="overflow:hidden;overflow-x:hidden;overflow-y:hidden;height:1200px;width:100%;" height="100%" width="100%"></iframe>
</div>
<hr class="print-page"/>
<a name="modules"></a>
## Modules
Note, many of these modules will span multiple lectures, be sure to cross-reference the lecture schedule above with the module listing below.

<p><a href="slides_pdf">Slides in PDF form (for printing)</a></p>

| Module #  | Module Topic | Slides |
|---------- |--------------|--------|
|01         |Course Introduction        | [Link](https://docs.google.com/presentation/d/1QSZpeD6KcWUslkiF0HrFcPhyXscZo75ajmWgBbC92dM/pub?start=false&loop=false&delayms=3000)|
|02         | Operating Systems Overview | [Link](https://docs.google.com/presentation/d/1n9vDtKH65_OFFjuvN0L3WjsG0Et99RLY_LoMjpwitB4/pub?start=false&loop=false&delayms=3000) |
|03         | System Calls | [Link](https://docs.google.com/presentation/d/1ILmDNUEbmUw4O4OMzxWuzosB4a_XGLNVxhVhLS-SWvA/pub?start=false&loop=false&delayms=3000) |
|04         | Operating System Structure | [Link](https://docs.google.com/presentation/d/1IHDZ8oJF35MPYsNDSTaINQItK7P9BVJ731c_UznQpTg/pub?start=false&loop=false&delayms=3000) |
|05         | C Programming and the POSIX Environment | [Link](https://docs.google.com/presentation/d/1HJKNR4LpQX4qI3ol6LVbSYhBlqyIOfSLoNiX7N_1a_A/pub?start=false&loop=false&delayms=3000) |
|06         | Processes | [Link](https://docs.google.com/presentation/d/1xr0XDiaK4cwbkcT8btHJO8itA-ndVMiGrg81iUeAWQk/pub?start=false&loop=false&delayms=3000) |
|07         | Threads | [Link](https://docs.google.com/presentation/d/1srgvI6jqfvfsOmK2aUnGwfNdv8K2NtgzZm-i_Mxce-o/pub?start=false&loop=false&delayms=3000) |
|08         | IPC and Synchronization | [Link](https://docs.google.com/presentation/d/1ZgoQ0JbQ1sDidKfIE_l9KNxg2ASCn_VsWlP6sQ5caiw/pub?start=false&loop=false&delayms=3000) |
|09         | Scheduling | [Link](https://docs.google.com/presentation/d/1RXM58-7qYmk0pc4CAou4bXfso7rvQDspKcnpgbyysN0/pub?start=false&loop=false&delayms=3000) |
|10         | Address Spaces | [Link](https://docs.google.com/presentation/d/1H2_cAFaKeOsqrthOOfoBW1AJdjSJMv0t2b6j4iMjsVw/pub?start=false&loop=false&delayms=3000) |

## Code Examples

Click [here](code/) for source code discussed in lectures throughout the semester.


## Homework Assignments
Homework assignments are worth 100 points, and are turned in electronically.  

* [Homework 1](hw/hw1)  - Due on 9/14/15
* [Homework 2](hw/hw2)  - Due on 9/17/15
* [Homework 3](hw/hw3)  - Due on 9/24/15
* [Homework 4](hw/hw4)  - Due on 9/30/15
* [Homework 5](hw/hw5)  - Due on 10/15/15
* [Homework 6](hw/hw6)  - Due on 11/9/15
* [Homework 7](hw/hw7)  - Due on 11/23/15

<hr class="print-page"/>

## Written Report (WI Component)
Writing will be integrated into the life of this course. You will receive comments, direction, and support as you work on strengthening your writing skills. Your writing will be evaluated and returned in a timely fashion, allowing you to incorporate my comments into your future work. For help outside the classroom, please see me during my office hours and/or work with a writing tutor in the Center for Reading and Writing (CRW), Room: L-211, x7557, crw@ramapo.edu.

You will write a written report on the history, evolution, and design of ONE of the following major operating systems in use today:

* Microsoft Windows
* Apple OS X
* Linux
* Google Android
* Apple iOS

The paper will technical aspects of the platforms, but largely focus on the its history and development.  While technical details are must (for example, what type of filesystem does the OS use?), your efforts on this report should be directed on clearly articulating where the operating system came from (did it evolve from something else?), how it became what it is today (were there any releases that were failures, spectacular successes?), and where it is headed (is it on its way out, or is it primed to take over the world?).

* A first draft is due on 10/30/2015.  This draft is expected to be a complete paper, and you will be graded on its quality.  I will offer advice for revisions.
* Your final draft is due the last day of the Fall 2015 semester (before finals).  Your grade is based on the quality of your writing, the depth in which you covered the subject, and how you responded to revision requests from your first draft. 



## Late Policy
All assignments will be turned in electronically.  A late penalty of 5 points per day will be applied to all late assignments.  The required format/method of your electronic submissions will be outlined for each assignment.  Deviation from these requirements may result in a 5-point penalty.  

## Attendance Policy
Attendance will be recorded by the instructor and, along with class participation, will be a determining factor in making border-line final grade decisions

## Grading

| % | Activity
|------------------:|:---------------
|60%|Quizzes (20%, 20%, 20%)
|25%|Final Exam
|10%|Homework
|2.5%|Written Report (WI Requirement)
|2.5%|Attendance and Participation


## Academic Integrity
Students are expected to read and understand Ramapo College’s Academic Integrity Policy, which can be found in the Ramapo College Catalog.  Members of the Ramapo College community are expected to be honest and forthright in their academic endeavors.  Students who are suspected of violating this policy will be referred to the Office of the Provost.

### ACADEMIC INTEGRITY SPECIFIC TO THIS COURSE  
For programming assignments (Homework Assignments), you may discuss ideas, however you may not allow others to see your source code or examine others’.  Sharing of source code is extremely easy to detect and is strictly prohibited.  

IF SHARING OF SOURCE CODE IS SUSPECTED, INTENTIONAL OR OTHERWISE, BOTH PARTIES WILL IMMEDIATELY BE REFERRED TO THE OFFICE OF THE PROVOST.

