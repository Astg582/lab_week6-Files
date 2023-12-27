#include <iostream>
#include <fstream>
#include <string>

std::string add_s(std::string&, std::string&);
void revers(std::string& s1){
	int s = s1.size() - 1;
	int i = 0;
	while(s > i){
		std::swap(s1[i], s1[s]);
		++i;
		--s;
	}
}

int main(){
	std::string s1;
	std::string s2;

	std::cin >> s1 >> s2;
	
	std::ifstream f1;
	std::ifstream f2;
	
	f1.open(s1);
	f2.open(s2);
	
	std::string str1;
	std::string str2;
	
	if(!f1.is_open() or !f2.is_open()){
		std::cerr << "f1 is not open" <<std::endl;
		return 0;
	}	

	while(std::getline(f1, str1), !f1.eof() && !f2.eof()){
		std::getline(f2, str2);
		std::cout << add_s(str1, str2) << std::endl;
	}
 
	f2.close();
	f1.close();
}


std::string add_s(std::string& s1, std::string& s2){
	int l1 = s1.size();
	int l2 = s2.size();
	int n = 0;

	revers(s1);
	revers(s2);
	
	std::string rec;	
	if(l1 > l2){
		s2.resize(l1, '0');
		n = l1;
	}else{
		s1.resize(l2, '0');
		n = l2;
	}
	
	int cer = 0;
	for(int i = 0; i < n; ++i){
		int tmp = (s1[i] + s2[i] - '0' - '0') + cer;
		cer = tmp / 2;
		rec.push_back((tmp % 2) + '0');
	}

	if(cer){
		rec.push_back('1');
	}
	
	revers(rec);
	return rec;
}

