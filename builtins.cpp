#include "builtins.h"
#include <iostream>
#include <unistd.h>
using namespace std;

bool is_builtin(const string& cmd) {
    return cmd == "cd" || cmd == "pwd" ||
           cmd == "exit" || cmd == "help";
}

int run_builtin(const Command& cmd) {
    const string& command = cmd.args[0];

    if (command == "exit") {
        exit(0);
    }
    else if (command == "pwd") {
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)))
            cout << cwd << "\n";
        else
            perror("pwd");
    }
    else if (command == "cd") {
        const char* path = (cmd.args.size() > 1)
                            ? cmd.args[1].c_str()
                            : getenv("HOME");
        if (chdir(path) != 0)
            perror("cd");
    }
    else if (command == "help") {
        cout << "Built-in commands: cd, pwd, exit, help\n";
        cout << "Any other command runs as an external program.\n";
    }
    return 0;
}