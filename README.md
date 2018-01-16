# CS 376 Lab 2: Introduction to C 

This lab introduces you to the C programming language. It includes exercises that involve separately compiled modules, writing command-line programs, and debugging existing code.

This lab has a total of 100 possible points.

### Objectives
Upon completion of the laboratory exercises, you will be able to do the following: 
* Clone a public GitHub repository.
* Write a program that is comprised of separately compiled modules. 
* Declare and use one-dimensional arrays in C. 
* Access arguments on the command line.
* Manipulate strings in C.
* Gain experience correcting buggy C programs.

**You should work with a partner throughout this lab; partner and seating assignments are shown at the front of the lab. Person 1 is listed first; Person 2 is listed second. If your partner has not shown up by the end of the mini-lecture, see your instructor—an attempt will be made to match you with another student.**

### PART 1 - PRELIMINARIES & LEARNING TO TRANSFER FILES (PERSON 1)

This is a refresher from last week. From now on, if you need to access the FreeBSD or Debian Virtual Machines, please revisit the previous lab sheets. Because the Unix/Linux machines are remotely accessed, the login and logout process requires several steps. First, you log into the PC; then you login into a virtual PC desktop; then you log into the Linux machine.
1.	Log into Windows desktop using your campus username and password.
2.	From the PC, run VMware Horizon Client.  You will most likely need to login again utilizing your campus username and password.  After logging in, select the “Engineering Kiosk”.   
3.	This will load another Windows OS.    After logging in, open the “Courseware” Folder on the Desktop.   Select the “Computer Science” Folder and open “Oracle Virtual Box”.   
4.	You have access to several virtual machines (VMs).  There should at least be FreeBSD and Debian available.  Last week, we selected the FreeBSD VM.  This week, please select the Debian VM for this lab.
5.	Log in as any user. If you want to use P drive integration to save your files, you should log on as `root`

For this lab, we will be fetching the starter files from GitHub. You do not need an account to clone the repository, but if you have a GitHub account already, and want to be able to easily save your files at the end of the lab, you may wish to fork the GitHub project and clone that instead. Run the following command:
```sh
git clone https://github.com/up-cs376/lab2.git
```

**Checkpoint 1 [10 points]: Each person must show the lab instructor or assistant the files have been transferred successfully and unarchived.**


At this point in the lab, you and your partner – Person 1 and Person 2 – should alternate who is working on the files on a single person’s account.  In this way, you can leverage the power of pair-programming.  Or you can work jointly on your respective computer.  If each person is working on their own computer, the pair of students will not be checked off until both students have completed the checkpoint.

### PART 2: MAKE THE MAIN FUNCTION THE FIRST FUNCTION IN MAIN.C (PERSON 2)

Enter the `lab2 `directory from whereever you cloned the repository.  Move into the subdirectory named `parts1-4`. This contains the sorting program from the “Notes on C” document available on the course Moodle site. The `main.c` file has been modified to include a `printSeparatorLine` function (not yet used), which prints a line with a row of ‘=’ signs.

Compile and run the program to confirm that it prints a sorted list of names. Since there is more than one C file, an easy way to compile all the `.c` files together is to use the Unix wild-card character, `*`:
```sh
gcc –g *.c
```
If you want, you can tell `gcc` to name the executable file something other than `a.out` using the `-o` switch. For example, this tells `gcc` to name the executable file `sort`:
```sh
gcc –g –o sort *.c
```
Many C programmers consider it good programming style to have the main function be the first function in the file.

Open `main.c` in `vim`:
```sh
vim main.c
```

Move the `main` function (in `main.c`) so that its definition comes before the` printSeparatorLine` function. Compile (`gcc –g –o sort *.c`) and run (`./sort`) your program . If it does not compile or run properly, make any fixes you need to so that it does.

***Checkpoint 2 [10 points]: Show your lab instructor or assistant your running program; let them see your code.***


### PART 3: COMPILING AND RUNNING C PROGRAMS AGAIN (PERSON 1)

In our Unix environment, we use the `gcc` command to compile a C program. For example, to compile `myProg.c`, we could say: 
```sh
gcc –g myProg.c
```
The `-g` indicates that debugging information should be produced. This creates a (large) executable file with the name `a.out`. This is the default executable file name.
 
To run the program, run the following command:
```sh
./a.out
```
When you run the program, it will begin executing in the main function, which should be declared as:
`int main(int argc, char *argv[]) { ... } `

1. Type the `gcc` command above. Notice that you receive an error message because the file `myProg.c` does not exist.

2. Use` vim` to create a C program for printing “Hello, World!”. The program should be named `hello.c`.

Type the following code into the file:
```c
#include <stdio.h>

/* main program prints Hello, world */
int main (int argc, char* argv[]) {
	printf("Hello, world!\n");
	return 0;
}
```

3. Compile and run the program in the command-line window. (Make sure you save the file before you compile.) The `&&` operator below joins two command such that the shell will only execute `a.out` if `gcc` was successful.
```sh
gcc –g hello.c && ./a.out
```

5. Switch drivers, so the other partner gets a chance to create and run a C program. Modify the program so that it prints your names 10 times (each on different lines) instead of printing “Hello, world!” once. (Note that the ‘\n’ signifies a newline—it causes each print to occur on a different line.) A for loop in C is just like a for loop in Java, except you must declare the iteration variable prior to the loop.  (A good C programming practice, shown below, is to declare the loop variable as part of the loop.)
```c
for(int i = 0; i < 10; i++) {
	/* body */
}
```
5. Compile and run your modified program. 

***Checkpoint 3 [15 points]: Let your lab instructor/assistant see the modified "Hello world" running.***


### PART 4: CREATE AND USE AN ARRAY-PRINTING FUNCTION (PERSON 2)

Create a new file `printArray.c`. 

It should define one function, `printStringArray` that:
*	takes two arguments, an array of char* (string) and an int that is the size of the array
*	returns no value
*	prints the strings in the array from first to last, one per line

Create a new file, `printArray.h`.  It should define a function prototype for `printStringArray`.

In `main.c`, add a preprocessor directive to include the `printArray.h`  file you just created.

Modify the main function so that the array-printing loop is replaced by a call to the `printStringArray` function.

Add a second `printStringArray` call to the main function so that the array is printed both before and after the sort. Add a call to `printSeparatorLine` so that the program’s “before sort” and “after sort” listings are separated.

***Checkpoint 4 [25 points]: Show your lab instructor or assistant your running program; let them see your code.***

If you have completed all the above checkpoints, you now have
a grade of D (60 points =  60%) for this lab.


### PART 5: CREATE A PROGRAM THAT PRINTS INITIAL PORTIONS OF COMMAND-LINE ARGUMENTS (PERSON 1)

Recall these facts on accessing the command-line arguments in C programs:

*	If you want to access the command-line arguments from your main function, declare it with two parameters as follows:
`int main(int argc, char* argv[]) { … }`
* The parameter `argv` is the array of the command-line arguments:
  * Slot 0 of the array is the name of the command itself
  * Slot 1 contains the first command line argument, etc.
 * The parameter `arg`c is an int tells you length of the `argv` array.

Go back to your `lab2` directory. Create a directory, `part5`, and move into it (`mkdir part5; cd part5`).

(In this checkpoint, you might find the `atoi` function useful. It converts its string argument to an int; it returns 0 if the string does not denote a valid integer.)

Create a C program, `printEm.c` that examines the command-line arguments and print them as follows:

*	The first command-line argument should be a positive integer.
    * If it is not a valid integer or it is not positive, print an error message and return.
    * If the first command-line argument is missing, print an error message and return.
* If the first command-line argument is a valid positive integer (let’s call it N):
  * Print the first N characters of each of the subsequent command line arguments, one per line. (If any are shorter than N, just print the entire string.)






For example, if the name of the executable were `printEm`, then the command
```sh
./printEm 3 George Paul Ringo John
```
should produce the output
```
Geo
Pau
Rin
Joh
```
While the command
```sh
./printEm 6 Crenshaw Nuxoll VanDeGrift Vegdahl Russell
```
should produce the output
```
Crensh
Nuxoll
VanDeG
Vegdah
Russel
```
As another example, the command
```sh
./printEm Giants Dodgers Reds
```
should produce an error message, such as
```
Error: ‘Giants’ must be a positive integer.
```
As a final, the command
```sh
./printEm
```
should produce an error message, such as
```
Error: count-value is missing.
```

***Checkpoint 5 [25 points]: Show your lab instructor or assistant your running program; let them see your code.***

If you have completed all the above checkpoints, you now have a grade of B (85 points =  85%) for this lab.

### PART 6: DEBUGGING (PERSONS 1 AND 2, ALTERNATING)

Move into the `lab2/part7` directory, which contains five buggy programs (you will only need to fix three of them). Your job is to fix the problems with these programs. Persons 1 and 2 should alternate ownership of the keyboard during this part.

When you compile these programs, use the `-o` switch so that the name of each executable is the same as the name of its primary .c file (but without the ‘.c’). 

#### Program: by_year
> At workstation: Person 1
> 
> Purpose: to print records of employees hired during (or since) a given year
> 
> To compile: `gcc -g -o by_year by_year.c`
> 
> Example runs:
> 
> `by_year 2000`
> 
> `by_year 2008`

***Checkpoint 6 [5 points]: Show your lab instructor or assistant your running by_year program.***

If you have completed all the above checkpoints, you now have a grade of A- (90 points =  90%) for this lab.

#### Program: in_order 
> At workstation: Person 2
> 
> Purpose: to print records of employees, sorted by first name
>
> To compile: `gcc -g -o in_order in_order.c sort.c`
> 
> Example run:
> 
> `in_order`

(You may want to additionally test it by modifying the code to add more people.)

***Checkpoint 7 [5 points]: Show your lab instructor or assistant your running in_order program.***

If you have completed all the above checkpoints, you now have a grade of A (95 points =  95%) for this lab.

#### Program: mark_name
> At workstation: Person 1
> 
> Purpose: to print names of employees, with a particular one marked with a ‘?’
>
> To compile: `gcc -g -o mark_name mark_name.c`
>
> Example runs:
>
> `mark_name 0`
>
> marks employee 0 (the first one) with a ‘?’
>
> `mark_name 3`
>
> marks employee 3 with a ‘?’

***Checkpoint 8 [5 points]: Show your lab instructor or assistant your running mark_name program.***

If you have completed all the above checkpoints, you now have a grade of A (100 points =  100%) for this lab.


### PART 7: FINISH UP (PERSON 2)
If you forked the sample code into your own GitHub repository, you may now push your changes back to GitHub.

Otherwise, if you wish to manually archive your lab, run the following commands:
```sh
tar cvzf ~/lab2_update.tar.gz lab2/
cp ~/lab2_update.tar.gz /media/sf_P_DRIVE/
```
You may then email `lab2_update.tar.gz` to yourself and your partner.

Shut down the VM
```sh
halt -p
```
and ***log out*** of the Engineering Kiosk.

<!--stackedit_data:
eyJoaXN0b3J5IjpbMTI5NTgzODQ0MF19
-->