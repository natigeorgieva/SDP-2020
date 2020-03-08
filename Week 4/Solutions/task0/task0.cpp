#include <iostream>
#include "src/Film.h"

int main()
{
	Film test1;
	test1.setName("Finding Nemo");
	((((test1 + 5) + 4) + 6) + 10) + 9;
	std::cout << test1;

	Film test2(test1);
	std::cout << test2;

	Film test3;
	test3.setName("Terminator");
	((((test3 + 9) + 8) + 2) + 10) + 9;
	std::cout << test3;

	test3 = test2;

	std::cout << test3;

	Film test4;
	test4 = test3;

	std::cout << test4;
	std::cout << (test4 >= test2);

}
