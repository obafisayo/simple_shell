# Implementation of sh in C programming language

## Overview
Simple Shell is an ALX Africa pair project. The general goal of the project is to write a simple UNIX command interpreter. 

## Target output
* Unless specified otherwise, your program must have the exact same output as sh (/bin/sh) as well as the exact same error output.
* The only difference is when you print an error, the name of the program must be equivalent to your argv[0]

- Example of error with sh:
```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```
- Same error with your program hsh:
```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$
```
## Compilation
```
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh 
```
## Testing
- Interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

- Non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```
## Tasks
### Mandatory:
0. Betty would be proud
- Write a beautiful code that passes the Betty checks

1. Simple shell 0.1
- Write a UNIX command line interpreter.
- Your Shell should:
Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)
- You don’t have to:
use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments

2. Simple shell 0.2
- Handle command lines with arguments

3. Simple shell 0.3
- Handle the PATH

4. Simple shell 0.4
- Implement the exit built-in, that exits the shell
- Usage: exit
- You don’t have to handle any argument to the built-in exit

5. Simple shell 1.0
- Implement the env built-in, that prints the current environment

### Advanced
1. Simple shell 0.1.1 
- Write your own getline function

2. Simple shell 0.2.1
- Write your own strtok function

3. Simple shell 0.4.1
- handle arguments for the built-in exit

4. Simple shell 0.4.2
- Handle Ctrl+C: your shell should not quit when the user inputs ^C

5. setenv, unsetenv
- Implement the setenv and unsetenv builtin commands

6. cd
- Implement the builtin command cd

7. ;
- Handle the commands separator ;

8. alias 
- Implement the alias builtin command

9. Comments
- Handle comments (#)

10. help 
- Implement the help built-in

11. File as an input 
- Your shell should take a file as a command line argument

## Authors
## Authors
* [Obafisayo Abimbola](https://github.com/obafisayo-alx)
* [Maureen Onouha](https://github.com/reenaAlx)
