#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

using namespace std;

int main() {
    string pid;
    cout << "Enter a PID: ";
    cin >> pid;
    string path = "/proc/" + pid;

    char exe[1024];
    string exe_link = path + "/exe";
    ssize_t len = readlink(exe_link.c_str(), exe, sizeof(exe) - 1);
    if (len != -1) exe[len] = '\0';

    long memory = 0;
    ifstream status(path + "/status");
    string str;
    while (getline(status,str)) {
        if (str.find("VmRSS:") == 0) {
            sscanf(str.c_str(), "VmRSS: %ld", &memory);
            memory *= 1024;
            break;
        }
    }
    status.close();

    ifstream cmd(path + "/cmdline", ios::binary);
    string args;
    char c;
    while (cmd.get(c)) {
        args += (c == '\0') ? ' ' : c;
    }
    cmd.close();

    ifstream env(path + "/environ", ios::binary);
    string envs;
    while (env.get(c)) {
        envs += (c == '\0') ? '\n' : c;
    }
    env.close();

    cout << "Exe: " << exe << endl;
    cout << "Memory: " << memory << endl;
    cout << "Parameters: " << args << endl;
    cout << "Environment variables:\n" << envs << endl;

    return 0;
}
