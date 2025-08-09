#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>

int main() {
    std::ifstream file("/proc/version");
    std::ofstream output("Linux version.txt");
    std::string str;

    while (std::getline(file, str)) {
        output << str << std::endl;
    }

    file.close();
    output.close();
    std::cout << "Finished." << std::endl;
    return 0;
}