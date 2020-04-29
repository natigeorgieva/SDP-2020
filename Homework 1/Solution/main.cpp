#include <iostream>
#include "BigInt.h";


int main() {
	BigInt X, Y;

	std::cin >> X >> Y;

	std::cout << "X = " << X << std::endl;
	std::cout << "Y = " << Y << std::endl;

	std::cout << " X + 10 =" << X + 10 << std::endl;
	std::cout << " X - 10 =" << X - 10 << std::endl;
	std::cout << " 10 + X =" << 10 + X << std::endl;
	std::cout << " 10 - X =" << 10 - X << std::endl;
	std::cout << " X + Y =" << X + Y << std::endl;
	std::cout << " Y + X =" << Y + X << std::endl;
	std::cout << " X - Y =" << X - Y << std::endl;
	std::cout << " Y - X =" << Y - X << std::endl;
	std::cout << " X++ =" << X++ << std::endl;
	std::cout << " ++X =" << ++X << std::endl;
	std::cout << " X-- =" << X-- << std::endl;
	std::cout << " --X =" << --X << std::endl;
	std::cout << " Y++ =" << Y++ << std::endl;
	std::cout << " ++Y =" << ++Y << std::endl;
	std::cout << " Y-- =" << Y-- << std::endl;
	std::cout << " --Y =" << --Y << std::endl;
}