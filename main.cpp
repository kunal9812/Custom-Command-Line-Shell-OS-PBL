#include <iostream>
#include <string>
#include <signal.h> 
#include <unistd.h>     
#include "parser.h"
#include "builtins.h"
#include "executor.h"
using namespace std;

int main() {
    string input;
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);

    while (true) {
        char cwd[1024];
        getcwd(cwd, sizeof(cwd));
        cout << "Custom_Shell₹  " << cwd << "> ";
        flush(cout);

        if (!getline(cin, input)) break;
        if (input.empty()) continue;

        vector<Command> commands = parse(input);
        if (commands.empty()) continue;
        if (commands[0].args.empty()) continue;

        if (commands.size() == 1 && is_builtin(commands[0].args[0]))
            run_builtin(commands[0]);
        else
            execute(commands);
    }
    return 0;
}