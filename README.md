# Custom Command-Line Shell

A lightweight, interactive command interpreter designed to mimic core functionalities of Unix-like shells (Bash, Zsh, etc.). This project demonstrates key operating system concepts including process management, inter-process communication, and system calls.

## Features

- **Command Execution**: Run standard system commands (e.g., `ls`, `cat`, `echo`) with arguments
- **Built-in Commands**: 
  - `cd` - Change directory
  - `pwd` - Print working directory
  - `exit` - Exit the shell
- **Process Management**: Child process creation and management using `fork()`, `exec()`, and `wait()`
- **Piping**: Chain multiple commands using `|` operator
- **Input/Output Redirection**: 
  - Redirect input with `<`
  - Redirect output with `>` or append with `>>`
- **Signal Handling**: Gracefully handle `Ctrl+C` (SIGINT) and `Ctrl+\` (SIGQUIT)

## Project Structure

```
Custom-Command-Line-Shell-OS-PBL/
├── main.cpp           # Entry point and REPL loop
├── parser.cpp         # Command parsing and tokenization
├── parser.h
├── executor.cpp       # Command execution engine
├── executor.h
├── builtins.cpp       # Built-in shell commands
├── builtins.h
├── Makefile          # Build configuration
├── Dockerfile        # Docker environment setup
├── synopsis.md       # Project overview
└── README.md         # This file
```

## Architecture

The shell operates in a continuous REPL (Read-Evaluate-Print Loop) cycle:

1. **Prompt Module**: Displays `Custom_Shell₹ ` and waits for user input
2. **Parser Module**: Tokenizes input into commands and arguments, handles special characters and redirection symbols
3. **Execution Engine**: 
   - Checks if command is built-in; if so, executes directly in parent process
   - For external commands, forks a child process to execute via `exec` family functions
   - Parent process waits for child completion
4. **Signal Handling**: Prevents shell termination on signal interrupts

## Building

### Prerequisites
- C++17 compatible compiler (GCC 7.0+)
- POSIX-compliant Unix/Linux system (Ubuntu, WSL, etc.)
- Standard development tools (#include `build-essential`)

### Compilation

**Using Make:**
```bash
make
```

**Manual compilation:**
```bash
g++ -o myshell main.cpp parser.cpp builtins.cpp executor.cpp
```

### Cleaning build artifacts:
```bash
make clean
```

## Running the Shell

```bash
./myshell
```

You'll see the custom prompt:
```
Custom_Shell₹ 
```

## Usage Examples

### Basic command execution:
```
Custom_Shell₹ ls -la
Custom_Shell₹ echo "Hello World"
Custom_Shell₹ cat file.txt
```

### Directory navigation:
```
Custom_Shell₹ pwd
Custom_Shell₹ cd /path/to/directory
Custom_Shell₹ cd ..
```

### Piping:
```
Custom_Shell₹ ls | grep .txt
Custom_Shell₹ cat file.txt | wc -l
```

### Input/Output redirection:
```
Custom_Shell₹ echo "Hello" > output.txt
Custom_Shell₹ cat file.txt >> output.txt
Custom_Shell₹ cat < input.txt
```

### Exit the shell:
```
Custom_Shell₹ exit
```

## Docker Support

Run the shell in a Docker container:

```bash
docker build -t custom-shell .
docker run -it custom-shell
```

## Core Modules

### Parser (`parser.cpp`)
- Tokenizes user input into command structures
- Handles redirection operators (`>`, `>>`, `<`)
- Processes pipe operators (`|`)
- Extracts command arguments and file operations

### Executor (`executor.cpp`)
- Manages process creation using `fork()`
- Implements command execution via `execvp()`
- Handles single command execution
- Manages piped command sequences
- Controls input/output file descriptors

### Built-ins (`builtins.cpp`)
- Implements `cd` for directory navigation
- Implements `pwd` for current directory display
- Implements `exit` for shell termination

### Main (`main.cpp`)
- REPL loop implementation
- Signal handler setup to ignore SIGINT/SIGQUIT
- Command parsing and dispatching

## Learning Outcomes

This project provides hands-on experience with:
- **System Calls**: `fork()`, `execvp()`, `wait()`, `pipe()`, `dup2()`
- **Process Management**: Child process creation and synchronization
- **Inter-process Communication**: Unix pipes
- **File Descriptors**: Redirection and stream management
- **Signal Handling**: Event-driven process interruption
- **String Parsing**: Tokenization and command-line argument processing

## Technology Stack

- **Language**: C++ (C++17)
- **Platform**: Linux/Unix (Ubuntu)
- **Compiler**: GCC

## Known Limitations

- Limited error handling and recovery
- No command history or auto-completion
- No job control (background/foreground process management)
- No scripting support (file-based command execution)
- Signal handling is basic

## Future Enhancements

- Command history using arrow keys
- Tab auto-completion for files and commands
- Scripting support (`.sh` file execution)
- Job control implementation
- Enhanced error messages and logging
- Support for environment variables
- Alias functionality

## License

This project is created for educational purposes as part of an Operating Systems course.

## Author

[Pankaj Singh] [Kunal Yadav] [Krishna Sharma]

---

For more details, see [synopsis.md](synopsis.md).
