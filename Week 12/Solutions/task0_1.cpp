#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

template <class T>
bool descending(T& objLeft, T& objRight) {
	return objLeft > objRight;
}

template <class T>
void readFromFile(std::vector<T>& vec, std::string path) {
	std::fstream fstr(path, std::ios::in);

	if (!fstr.is_open()) {
		std::cout << "Cannot open file : " << path << std::endl;
		return;
	}

	T inpt;

	while (fstr >> inpt) {
		vec.push_back(inpt);
	}

	if (fstr.eof()) {
		std::cout << "Reached end of file\n";
	}
	else if (fstr.fail()) {
		std::cout << "Failed at extracting info from file " << path << " at " << fstr.tellg() << std::endl;
	}
}

template <class T>
void writeToFile(std::vector<T> vec, std::string path) {
	std::fstream fstr(path, std::ios::out | std::ios::trunc);

	if (!fstr.is_open()) {
		std::cout << "Cannot create file. Be sure that the directory exist.";
	}

	for (T v : vec) {
		fstr << v << ' ';
	}
}

void removeElements(int a, int b, std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] >= a && vec[i] <= b) {
			vec.erase(vec.begin() + i);
			i--;
		}
	}
}

template <class T>
void printVec(std::vector<T> vec) {
	for (T v : vec) {
		std::cout << v << ' ';
	}
}

int main() {
	int a, b;
	std::vector<int> vec;

	std::string inputPath = "nums.txt",
		outputPath = "output0_1.txt";

	std::cout << "Enter a and b: ";
	std::cin >> a >> b;
	std::cout << "\n\n";

	std::cout << "Reading from file " << inputPath;
	readFromFile(vec, inputPath);
	std::cout << "\n\n";

	std::cout << "Reading stoped... Showing result\n";
	printVec(vec);
	std::cout << "\n\n";

	std::cout << "Removing elements from [" << a << ", " << b << "]..";
	removeElements(a, b, vec);
	std::cout << "\n\n";

	std::cout << "Removing stoped... Showing result\n";
	printVec(vec);
	std::cout << "\n\n";

	std::cout << "Sorting elements... Showing result\n";
	std::sort(vec.begin(), vec.end(), descending<int>);
	printVec(vec);
	std::cout << "\n\n";

	std::cout << "Wrinting to file : " << outputPath;
	writeToFile(vec, outputPath);
	std::cout << "\n\n";

	std::cout << "Writing stoped... terminating program\n";
}