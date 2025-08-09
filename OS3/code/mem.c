#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream meminfo("/proc/meminfo");
    string str;
    int total, available, used = 0;
    while (getline(meminfo, str)) {
    	if (str.find("MemTotal") == 0){
		sscanf(str.c_str(), "MemTotal: %d", &total);
		cout << str << endl;;
    	}
    	if (str.find("MemFree") == 0){
        	cout << str << endl;
    	}
    	if (str.find("MemAvailable") == 0){
        	sscanf(str.c_str(), "MemAvailable: %d", &available);
		cout << "MemUsed: \t" << total - available << " kB" << endl;
     	}
    }
    meminfo.close();
    return 0;
}
