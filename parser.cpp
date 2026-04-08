#include "parser.h"
#include <sstream>
using namespace std;

Command parse(const string& input) {
    Command cmd;
    istringstream stream(input);
    string token;

    while (stream >> token) {
        if (token == ">") {
            stream >> cmd.output_file;
            cmd.append = false;
        }
        else if (token == ">>") {
            stream >> cmd.output_file;
            cmd.append = true;
        }
        else if (token == "<") {
            stream >> cmd.input_file;
        }
        else {
            cmd.args.push_back(token);
        }
    }
    return cmd;
}