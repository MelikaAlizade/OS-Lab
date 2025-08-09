#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream cpuinfo("/proc/cpuinfo");
    string str;
    while (getline(cpuinfo, str)) {
	if (str.find("model name") != string::npos ||
            str.find("cpu MHz") != string::npos ||
            str.find("cache size") != string::npos) {
            cout << str << endl;
        }
    }
    cpuinfo.close();
    return 0;
}

