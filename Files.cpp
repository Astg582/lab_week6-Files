#include <iostream>
#include <fstream>
#include <string>

int main(){
	std::string str1;
	std::string f1name;
	std::string str2;
	std::string f2name;

	std::cin >> f1name >> f2name;	
	

	std::ifstream f1;
	std::ifstream f2;
	std::ofstream f3;

	f1.open(f1name);
	f2.open(f2name);
	f3.open("Tex.txt");
	
	int count = 0;
	while(!f1.eof() | !f2.eof()){
		f1 >> str1;
		f2 >> str2;
		++count;
		if(f1.eof() && !f2.eof()){
			f3 << count << ' ' << f2name << ' ' << "is biget" << std::endl;
			break;
		}else if (f2.eof() && !f1.eof()){
			f3 << count << ' ' << f1name << ' ' << "is biger" << std::endl;
			break;
		}
		if(str1 != str2){
			f3 << count <<' ' << str1 << " | " << str2 << std::endl; 
		
		}
	} 




	f1.close();
	f2.close();
	f3.close();
}
