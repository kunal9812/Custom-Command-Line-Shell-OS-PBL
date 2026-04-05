#include "parser.h"
#include <sstream>
using namespace std;

vector<string> parse(const string& input) {
    vector<string> tokens;
    istringstream stream(input);
    string token;
    while (stream >> token)
        tokens.push_back(token);
    return tokens;
}
