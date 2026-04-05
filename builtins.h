#pragma once
#include <vector>
#include <string>
using namespace std;
bool is_builtin(const string& cmd);
int run_builtin(const vector<string>& args);