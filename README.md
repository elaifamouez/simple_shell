# 0x16. C - Simple Shell

## A Unix Command Line Interpreter Built in C

```

                       _____ _   _ _____    ____    _  _____ _____ ____     ___  _____ 
                      |_   _| | | | ____|  / ___|  / \|_   _| ____/ ___|   / _ \|  ___|
                        | | | |_| |  _|   | |  _  / _ \ | | |  _| \___ \  | | | | |_   
                        | | |  _  | |___  | |_| |/ ___ \| | | |___ ___) | | |_| |  _|  
                        |_| |_| |_|_____|  \____/_/   \_\_| |_____|____/   \___/|_|    

                                       ____  _   _ _____ _     _     
                                      / ___|| | | | ____| |   | |    
                                      \___ \| |_| |  _| | |   | |    
                                       ___) |  _  | |___| |___| |___ 
                                      |____/|_| |_|_____|_____|_____|
                                                                      
```

## About this project

This project is a simple version of the linux shell made for [ALX SOFTWARE ENGINERRING] taking part of the "Simple Shell - Linux and Unix system programming" Project.\
It is created using the **C programming Language** and it can do many functionalities that a real shell does.

<details>
<summary>The Gates of Shell by Spencer Cheng, featuring Julien Barbier</summary>
<img src="https://user-images.githubusercontent.com/29776892/129798799-6f730688-8728-49ed-b01b-13bec0fa2896.jpeg">
</details>

## Resource

- [Unix shell](https://en.wikipedia.org/wiki/Unix_shell)
- [Thompson shell](https://en.wikipedia.org/wiki/Thompson_shell)
- [Ken Thompson](https://en.wikipedia.org/wiki/Ken_Thompson)
- [Everything you need to know to start coding your own shell](https://www.notion.so/C-Programming-f13cdb9661db464f8ea326c5a2654e8e)

---

<details>
<summary>List of allowed functions and system calls</summary>

+ `access` (man 2 access)
+ `chdir` (man 2 chdir)
+ `close` (man 2 close)
+ `closedir` (man 3 closedir)
+ `execve` (man 2 execve)
+ `exit` (man 3 exit)
+ `\_exit` (man 2 \_exit)
+ `fflush` (man 3 fflush)
+ `fork` (man 2 fork)
+ `free`(man 3 free)
+ `getcwd` (man 3 getcwd)
+ `getline` (man 3 getline)
+ `getpid` (man 2 getpid)
+ `isatty` (man 3 isatty)
+ `kill` (man 2 kill)
+ `malloc` (man 3 malloc)
+ `open` (man 2 open)
+ `opendir` (man 3 opendir)
+ `perror` (man 3 perror)
+ `read` (man 2 read)
+ `readdir` (man 3 readdir)
+ `signal` (man 2 signal)
+ `stat` (\_\_xstat) (man 2 stat)
+ `lstat` (\_\_lxstat) (man 2 lstat)
+ `fstat` (\_\_fxstat) (man 2 fstat)
+ `strtok` (man 3 strtok)
+ `wait` (man 2 wait)
+ `waitpid` (man 2 waitpid)
+ `wait3` (man 2 wait3)
+ `wait4` (man 2 wait4)
+ `write` (man 2 write)

</details>

<details>
<summary>The shell will be compiled this way:</summary>
<pre>$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 \*.c -o hsh</pre>
</details>

## Output

- Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your `argv[0]` (see below)

<details>
     <summary>Example of error with sh:</summary>
<pre>$ echo "qwerty" | /bin/sh<br>/bin/sh: 1: qwerty: not found<br>$ echo "qwerty" | /bin/../bin/sh<br>/bin/../bin/sh: 1: qwerty: not found<br>$</pre>
</details>

<details>
<summary>Same error with your program hsh:</summary>
<pre>$ echo "qwerty" | ./hsh<br>./hsh: 1: qwerty: not found<br>$ echo "qwerty" | ./././hsh<br>./././hsh: 1: qwerty: not found<br>$</pre>
</details>

## Testing

<details>
<summary>The shell should work like this in interactive mode:</summary>
<pre>$ ./hsh<br>($) /bin/ls<br>hsh main.c shell.c<br>($)<br>($) exit<br>$</pre>
</details>

<details>
<summary>But also in non-interactive mode:</summary>
<pre>$ echo "/bin/ls" | ./hsh<br>hsh main.c shell.c test\_ls\_2<br>$<br>$ cat test\_ls\_2<br>/bin/ls<br>/bin/ls<br>$<br>$ cat test\_ls\_2 | ./hsh<br>hsh main.c shell.c test\_ls\_2<br>hsh main.c shell.c test\_ls\_2<br>$</pre>
</details>

## Features

- Display a prompt and wait for the user to type a command. A command line always ends with a new line.
- If an executable cannot be found, print an error message and display the prompt again.
- Handle errors.
- Handling the “end of file” condition (Ctrl+D)
- Handling the command line with arguments
- Handle the PATH
- Support the exit features and the exit status
- Handle the Ctrl-C to not terminate the shell
- Handling the command seperator ;
- Handling && and || logical operators
- Handle variable replacements $? and $$
- Handle the comments #
- Support the history feature
- Support the file input


## Builtins

Our shell has support for the following built-in commands:


| Command                     | Definition                                                                                |
| --------------------------- | ----------------------------------------------------------------------------------------- |
| exit [STATUS]               | Exit the shell, with an optional exit status, STATUS.                                     |
| env                         | Display the environnment variables env.                                                   |
| setenv [VARIABLE] [VALUE]   | Initialize a new environnment variables or created if not match setenv.                   |
| alias [name [='value'] ...] | Support the aliases                                                                       |
| unsetenv [VARIABLE]         | Remove an environment variable.                                                           |
| cd [DIRECTORY] | [OPTION]   | Changes the current directory of the process to DIRECTORY.                                |
| help [BUILTIN]              | Read documentation for a built-in.                                                        |
| history                     | Displays the last typed user .                                                            |

## Contributors :
* [**Peter Kusare Chuwa Kusare**](https://github.com/count58)
* [**ELAIFA Mouez**](https://github.com/elaifamouez/)
