#include "executor.h"
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
using namespace std;

int execute(const Command& cmd) {
    if (cmd.args.empty()) return 0;

    vector<char*> argv;
    for (const auto& arg : cmd.args)
        argv.push_back(const_cast<char*>(arg.c_str()));
    argv.push_back(nullptr);

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return -1;
    }

    if (pid == 0) {
        if (!cmd.output_file.empty()) {
            int flags = O_WRONLY | O_CREAT | (cmd.append ? O_APPEND : O_TRUNC);
            int fd = open(cmd.output_file.c_str(), flags, 0644);
            if (fd < 0) { perror("open"); exit(1); }
            dup2(fd, STDOUT_FILENO);  
            close(fd);                
        }

        if (!cmd.input_file.empty()) {
            int fd = open(cmd.input_file.c_str(), O_RDONLY);
            if (fd < 0) { perror("open"); exit(1); }
            dup2(fd, STDIN_FILENO);   
            close(fd);
        }

        execvp(argv[0], argv.data());
        cerr << cmd.args[0] << ": command not found\n";
        exit(1);
    }

    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
}