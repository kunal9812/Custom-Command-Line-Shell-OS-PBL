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

        vector<string> args = parse(input);
        if (args.empty()) continue;

        if (is_builtin(args[0]))
            run_builtin(args);
        else
            execute(args);
    }

    return 0;
}