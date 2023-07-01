Minishell is a simple command-line shell program developed in C. It aims to provide a basic shell environment with support for executing commands, managing processes, and handling input/output redirection. The project is developed as part of a learning process to understand the inner workings of a shell and gain knowledge about various system calls and process management in Unix-like systems.

The minishell program offers a prompt where users can enter commands and execute them. It supports various built-in commands such as cd, echo, pwd, export, and unset. Additionally, it allows the execution of external programs available in the system's $PATH environment variable.

The shell provides features like command history using arrow keys, signal handling for Ctrl+C, Ctrl+D, and Ctrl+\, as well as input/output redirection using <, >, and >> operators. It also supports handling pipes (|) to connect the output of one command as the input of another.

This minishell implementation is developed using the C programming language and makes use of system calls like fork, execve, wait, and dup2 for process management and execution of commands. The program follows the POSIX standards and takes into account edge cases and error handling.

Features
Basic command execution
Built-in commands (cd, echo, pwd, export, unset, etc.)
External program execution
Input/output redirection (<, >, >>)
Command history
Signal handling (Ctrl+C, Ctrl+D, Ctrl+\)
Pipes (|) for command chaining
Error handling and edge cases
Getting Started
To run the minishell program on your local machine, follow these steps:


Clone the repository
make
./minishell


Usage
After running the minishell program, you will see a prompt where you can enter commands. You can execute various commands, including built-in commands and external programs.


Some examples of usage:

| Command                            | Description                                                      |
| :--------------------------------  | :--------------------------------------------------------------- |
| `$ ls -l`                          | Execute the `ls` command with long listing format.               |
| `$ cd path/to/directory`           | Change the current working directory to the specified path.      |
| `$ pwd`                            | Print the current working directory.                             |
| `$ export VAR=value`               | Set an environment variable named `VAR` with the value `value`.  |
| `$ unset VAR`                      | Remove the environment variable named `VAR`.                     |
| `$ cat < input.txt`                | Redirect input from the `input.txt` file.                        |
| `$ ls -l > output.txt`             | Redirect output to the `output.txt` file (overwrite if exists).  |
| `$ echo "Hello, world!" >> log.txt`| Append the string "Hello, world!" to the `log.txt` file.         |
| `$ ls -l \| grep "pattern"`        | Chain commands: list files and filter results by the pattern.    |
| `$ exit`                           | Exit the minishell program.                                      |


Contributing
This project was developed in collaboration with Mario (@maricard18). 







