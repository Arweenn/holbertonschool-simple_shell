
# Simple Shell Project :mortar_board:

Second group project at Holberton School : implementation of our own simplified version of a UNIX command line interpreter in C.


## Description :scroll:

The objective of this project is to create from scratch a simple UNIX command interpreter with limited functionality but applying the core concepts of a more robust shell. In simple words, the shell is a program that takes commands from the keyboard and gives them to the operating system to perform. It incorporates many features and generally executes standard Shell commands found in PATH environment variable.


## Requirements

 - Allowed editors: vi, vim, emacs
 - A README.md file, at the root of the folder of the project is mandatory
 - Your code should use the Betty style.
 - Your shell should not have any memory leaks
 - No more than 5 functions per file
 - All your header files should be include guarded
## Compilation

Your shell will be compiled on Ubuntu 20.04 LTS using:

``` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ```

## Allowed functions 

### List of allowed functions and system calls+

All functions from string.h.
- `access` (man 2 access)
- `chdir` (man 2 chdir)
- `close` (man 2 close)
- `closedir` (man 3 closedir)
- `execve` (man 2 execve)
- `exit` (man 3 exit)
- `_exit` (man 2 _exit)
- `fflush` (man 3 fflush)
- `fork` (man 2 fork)
- `free` (man 3 free)
- `getcwd` (man 3 getcwd)
- `getline` (man 3 getline)
- `getpid` (man 2 getpid)
- `isatty` (man 3 isatty)
- `kill` (man 2 kill)
- `malloc` (man 3 malloc)
- `open` (man 2 open)
- `opendir` (man 3 opendir)
- `perror` (man 3 perror)
- `printf` (man 3 printf)
- `fprintf` (man 3 fprintf)
- `vfprintf` (man 3 vfprintf)
- `sprintf` (man 3 sprintf)
- `putchar` (man 3 putchar)
- `read` (man 2 read)
- `readdir` (man 3 readdir)
- `signal` (man 2 signal)
- `stat` (__xstat) (man 2 stat)
- `lstat` (__lxstat) (man 2 lstat)
- `fstat` (__fxstat) (man 2 fstat)
- `strtok` (man 3 strtok)
- `wait` (man 2 wait)
- `waitpid` (man 2 waitpid)
- `wait3` (man 2 wait3)
- `wait4` (man 2 wait4)
- `write` (man 2 write)
### Features

- Displays a prompt and wait for the user to type a command. A command line always ends with a new line.
- The prompt is displayed again each time a command has been executed.
- The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
- Handles arguments
- Handles errors.
- Handles the “end of file” condition (`Ctrl+D`)
- Handles the PATH
- Handles the  `exit`  built-in, that exits the shell. Usage:  `exit`
- Handles the `env`  built-in, that prints the current environment




### Testing examples

Your shell should work like this in interactive mode :

``` 
root@id:/holbertonschool-simple_shell# ./hsh   
$ /bin/ls
$ hsh main.c shell.c
$ exit
root@id:/holbertonschool-simple_shell#
```

But also in non-interactive mode :

```
root@id:/holbertonschool-simple_shell# echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
root@id:/holbertonschool-simple_shell#
root@id:/holbertonschool-simple_shell# cat test_ls_2
/bin/ls
/bin/ls
root@id:/holbertonschool-simple_shell#
root@id:/holbertonschool-simple_shell# cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
root@id:/holbertonschool-simple_shell#
```
## Files :gear:

- `main.h` : Header file containing all prototypes and necessary libraries 
- `shell.c` : File containing the main function of the program
- `exec.c` : File containing the function `execve()` to execute the input received
- `tokenize.c` : File containing the function `strtok()` in order to parse the arguments received in the input as per example `ls -l` or `ls -a`, even both : `ls -l -a`
- `handlePath.c` : File containing a program to handle the `PATH` situation in the input, in order to treat commands as `ls`, `pwd`
- `printEnv.c` : File containing a little code that give the occasion to handle the `env` command received as an input
- `README.md` README file that you are reading now :)
- `AUTHORS` : The project caretakers :)

## Authors :writing_hand:

This README file, along with the entirety of this project, was made by : 
- **[Arwen Dumont](https://github.com/Arweenn)**
- **[Yassine Daoui](https://github.com/Fiegsy)**
