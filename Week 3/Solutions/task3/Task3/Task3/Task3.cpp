// Task3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "src/myString.h"

int main()
{
	myString test((char *)"The quick brown fox jumped over the lazy dog");
	std::cout << test.getStr()<<std::endl;

	std::cout << "Compare with 'What does the fox say' :" << test.cmp((char*)"What does the fox say")<<std::endl;
	std::cout << "Compare with 'The quick brown fox' :" << test.cmp((char*)"The quick brown fox") << std::endl;
	std::cout << "Compare with 'The quick brown fox jumped over the lazy dog' :" << test.cmp((char*)"The quick brown fox jumped over the lazy dog") << std::endl;

	std::cout << "Finding 'fox' :" << test.find((char*)"fox") << std::endl;

	std::cout << "Deleting 'fox' :";
	test.deleteSubStr((char*)"fox");
	std::cout << test.getStr() << std::endl;

	std::cout << "Concatenating front 'fox' :";
	test.concatenateFront((char*)"fox");
	std::cout << test.getStr() << std::endl;

	std::cout << "Concatenating back 'fox' :";
	test.concatenateBack((char*)"fox");
	std::cout << test.getStr() << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
