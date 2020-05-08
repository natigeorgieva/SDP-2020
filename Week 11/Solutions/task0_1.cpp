#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream inpt;
	std::ofstream outp;

	outp.open("example.txt", std::ostream::in| std::ostream::trunc);

	outp << "Hello World!, again";

	//outp.flush();
	outp.close();

	inpt.open("example.txt", std::ios::in);

	std::string text;
	
	std::cout << "Word by word:\n";
	while (inpt >> text)std::cout << text << std::endl;
	std::cout << std::endl;

	inpt.clear();
	inpt.seekg(0, std::istream::beg);

	getline(inpt, text);
	std::cout <<"Whole line: "<< text << std::endl;

	inpt.close();
}
