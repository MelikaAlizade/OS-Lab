#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::string str;
	std::ifstream int_file("/proc/interrupts");
	std::ofstream int_txt("interrupt_output.txt");
	printf("Interrupt:\n");
	while (std::getline(int_file,str)){
		int_txt << str << std::endl;
		std::cout << str <<std::endl;
	}
	int_file.close();
	int_txt.close();

	std::ifstream sirq_file("/proc/softirqs");
        std::ofstream sirq_txt("softirqs_output.txt");
        printf("Softirqs:\n");
        while (std::getline(sirq_file,str)){
                sirq_txt << str << std::endl;
                std::cout << str << std::endl;
        }
        sirq_file.close();
        sirq_txt.close();
	return 0;
}

