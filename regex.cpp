#include <iostream>
#include <fstream>
#include <string>
#include <regex>

bool m_valid(const std::string&);

int main(){
	std::string f1;
	std::cout << "Enter to text file name: ";
	std::cin >> f1;

	std::ifstream file;
	file.open(f1);

	if(!file.is_open()){
		throw std::invalid_argument("file is close if file is not a text file");
		return -1;
	}
	
	int count = 0;
	while(std::getline(file, f1), !file.eof()){
		if(m_valid(f1)){
			++count;
		}
	}
	
	std::cout << "int your file have: " << count << " valid element " << std::endl;

	file.close();
}

bool m_valid(const std::string& str){
	std::regex mail("^[a-zA-Z][a-zA-Z0-9]{0,9}([\\._][a-zA-Z0-9]{1,10})?@mail\\.com$");
	return std::regex_match(str, mail);
}
