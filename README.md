*This project has been created as part of the 42 curriculum by hrhalmi, and grivault.*

# Minishell

## Description
Minishell is a project that involves creating a simple, custom UNIX shell. The goal is to deeply understand how a shell operates behind the scenes, managing processes, file descriptors, and command-line interpretation. 

This project was developed in a team of two, divided into two main components:
*   **Parsing (developed by hrhalmi):** Responsible for reading the user input, handling quotes `' '`, `" "`,handle redirections (`>`, `<`, `>>`, `<<`) and get the file descriptor for the execution, manage pipes (`|`), tokenizing the string into a data structure and expanding environment variables that the execution engine can understand.

*   **Execution (developed by grivault):** Responsible for traversing the parsed data structure to execute commands, and run built-in commands (like `cd`, `echo`, `env`).

## Instructions
To compile and run this project, you need a standard C environment and the `readline` library.

**1. Compilation:**
Run the following command at the root of the repository to compile the executable:
`make`

Other available rules:
*   `make clean`: Removes object files.
*   `make fclean`: Removes object files and the executable.
*   `make re`: Recompiles the entire project.

**2. Execution:**
Once compiled, you can start the shell by running:
`./minishell`

From there, you will be prompted with a custom shell prompt and can start typing standard bash commands.

## Resources
Here are the main resources and documentation we used to build this project:
*   [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html) - For understanding the exact behavior of shell built-ins and tokenization rules.
*   `man readline` - For handling user input and command history.
*   `man signal`, `man fork`, `man execve` - For process creation and management.

**AI Usage:**
*   **Generative AI (e.g., NoteBookLLM / Gemini):** Used primarily to understand complex POSIX concepts and for debugging specific edge cases in memory management (e.g., explaining Valgrind output). AI was *not* used to generate the core logic or the code of the project itself.