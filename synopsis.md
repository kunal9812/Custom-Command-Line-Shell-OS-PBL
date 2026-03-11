# Project Synopsis: Custom Command-Line Shell

## 1. Project Title
**Custom Command-Line Shell**

## 2. Introduction
The "Custom Command-Line Shell" is a lightweight, interactive command interpreter designed to mimic the core functionalities of traditional Unix-like shells (such as Bash or Zsh). It serves as a user interface for accessing operating system services. By parsing user input and executing corresponding system commands, this project provides a deeper understanding of operating system concepts such as process management, inter-process communication, and system calls.

## 3. Objectives
*   **Process Management:** To demonstrate the creation and management of child processes using system calls like `fork()`, `exec()`, and `wait()`.
*   **Command Execution:** To support the execution of standard system commands (e.g., `ls`, `cat`, `echo`) with arguments.
*   **Built-in Commands:** To implement native shell commands such as `cd` (change directory), `pwd` (print working directory), and `exit` directly within the shell environment, as they cannot be executed as external processes.
*   **Environment Interaction:** To provide an interactive prompt that reflects the current user environment.
*   **Advanced Shell Features (Optional/Extended Scope):** To add support for input/output redirection (`>`, `<`), piping (`|`), and background process execution (`&`).

## 4. Problem Statement / Motivation
Standard operating system courses introduce theoretical concepts like process scheduling, memory boundaries, and system calls. Building a custom command-line shell bridges the gap between theory and practice. The motivation behind this project is to gain hands-on experience in systems programming and to understand the inner workings of the interface that developers use every day. 

## 5. Technology Stack
*   **Programming Language:** C or C++ (due to direct access to low-level POSIX system calls).
*   **Platform:** Linux/Unix environment (e.g., Ubuntu, as defined in the project's Dockerfile).
*   **Core Libraries:** Standard C libraries (`stdio.h`, `stdlib.h`, `string.h`, `unistd.h`, `sys/wait.h`).
*   **Compilation:** GCC (GNU Compiler Collection) or Clang (via `build-essential`).

## 6. Proposed Architecture / Modules
The shell will operate in a continuous REPL (Read-Evaluate-Print Loop) cycle:
1.  **Prompt Module:** Displays the command prompt to the user, waiting for input.
2.  **Parser Module:** Reads the standard input, tokenizes the string into a command and its arguments, and handles special characters (like quotes or redirection symbols).
3.  **Execution Engine:** 
    *   Checks if the command is a *built-in command*. If so, it executes the corresponding internal function directly in the parent process.
    *   If it is an *external command*, the engine forks a new child process. The child process uses the `exec` family of functions to load and run the requested program, while the parent process waits for it to complete.
4.  **Signal Handling (Optional):** Intercepts signals like `Ctrl+C` (SIGINT) to ensure the shell itself does not terminate unexpectedly, but rather interrupts the currently running child process.

## 7. Expected Outcomes
Upon completion, the project will yield a functional shell capable of navigating the file system, running standard utilities, and managing basic processes. It will serve as a robust demonstration of applied operating systems principles and low-level C programming proficiency.

## 8. Future Scope
*   Implementation of command history (using arrow keys to navigate previous commands).
*   Auto-completion of file paths and commands using the `Tab` key.
*   Support for scripting (reading commands from a file instead of standard input).
*   Job control (bringing background processes to the foreground and vice versa).
