#include <iostream>
#include <string>
#include "parser.h"
#include "builtins.h"
#include "executor.h"
using namespace std;

int main() {
    string input;

    while (true) {
        cout << "Custom_shell> ";
        flush(cout);

        if (!getline(cin, input)) break;
        if (input.empty()) continue;

        Command cmd = parse(input);
        if (cmd.args.empty()) continue;

        if (is_builtin(cmd.args[0]))
            run_builtin(cmd);
        else
            execute(cmd);
    }
    return 0;
}