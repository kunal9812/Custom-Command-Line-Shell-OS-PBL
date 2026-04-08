#pragma once
#include "parser.h"

bool is_builtin(const string& cmd);
int run_builtin(const Command& cmd);