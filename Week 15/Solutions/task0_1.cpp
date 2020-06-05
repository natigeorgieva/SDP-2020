#include<iostream>
#include<fstream>
#include<set>
#include <unordered_map>
#include<iomanip>
#include<string>

typedef unsigned short int ushort;

std::unordered_map<std::string, int> table = {
	{std::string("HDD"), 0},
	{std::string("SSD"), 1},
	{std::string("RAM"), 2},
	{std::string("GHz"), 3},
	{std::string("VRAM"), 4},
	{std::string("Price"), 5}
};

struct Laptop {
	std::string name;
	float ghz;
	ushort price, ram, vram, hdd, ssd;

	Laptop() :name(""), ghz(0), price(0), ram(0), vram(0), hdd(0), ssd(0) {};
};

bool operator<(const Laptop& lhs, const Laptop& rhs) {
	return lhs.name < rhs.name;
}

std::string retValue(std::set<Laptop>::iterator lp, std::string key) {
	switch (table[key])
	{
	case 0: {
		return std::to_string(lp->hdd);
	}; break;

	case 1: {
		return std::to_string(lp->ssd);
	}; break;

	case 2: {
		return std::to_string(lp->ram);
	}; break;

	case 3: {
		return std::to_string(lp->ghz);
	}; break;

	case 4: {
		return std::to_string(lp->vram);
	}; break;

	case 5: {
		return std::to_string(lp->price);
	}; break;

	default:
		std::cout << "Something went wrong";
		break;
	}
}

void setValue(Laptop& lp, std::string key, std::string value) {
	switch (table[key])
	{
	case 0: {
		lp.hdd = std::stoi(value);
	}; break;

	case 1: {
		lp.ssd = std::stoi(value);
	}; break;

	case 2: {
		lp.ram = std::stoi(value);
	}; break;

	case 3: {
		lp.ghz = std::stof(value);
	}; break;

	case 4: {
		lp.vram = std::stoi(value);
	}; break;

	case 5: {
		lp.price = std::stoi(value);
	}; break;

	default:
		std::cout << "Something went wrong";
		break;
	}
}

void loadFile(std::string path, std::set<Laptop>& data) {
	std::fstream fstr(path, std::ios::in);

	data.clear();

	if (!fstr.is_open()) {
		std::cout << "Erorr reading from file...";
		exit(1);
	}

	bool first = true;

	std::string inpt;
	std::string type;
	unsigned int posDots;

	Laptop currLt;

	while (fstr) {
		std::getline(fstr, inpt);

		posDots = inpt.find(':');

		if (posDots == std::string::npos) {
			if (!first) {
				data.insert(currLt);
				currLt = Laptop();
			}
			else {
				first = false;
			}

			currLt.name = inpt;
			continue;
		}

		type = inpt.substr(0, posDots);
		inpt = inpt.substr(posDots + 1);

		setValue(currLt, type, inpt);

		/**
		switch (table[type])
		{
		case 0: {
			currLt.hdd = std::stoi(inpt);
		}; break;

		case 1: {
			currLt.ssd = std::stoi(inpt);
		}; break;

		case 2: {
			currLt.ram = std::stoi(inpt);
		}; break;

		case 3: {
			currLt.ghz = std::stof(inpt);
		}; break;

		case 4: {
			currLt.vram = std::stoi(inpt);
		}; break;

		case 5: {
			currLt.price = std::stoi(inpt);
		}; break;

		default:
			std::cout << "Something went wrong";
			break;
		}*/
	}
}

void printLaptopSet(std::set<Laptop> data) {
	std::set<Laptop>::iterator currRowBeg = data.begin();

	

	while (currRowBeg != data.end()) {
		std::cout << std::setw(10) << "";
		std::set<Laptop>::iterator itr = currRowBeg;
		for (int i = 0; i < 4; i++) {
			std::cout << std::setw(20) << itr->name;
			itr++;
			if (itr == data.end()) break;
		}
		std::cout << std::endl;


		std::unordered_map<std::string, int>::iterator itrTable = table.begin();

		while (itrTable != table.end()) {
			std::cout << std::setw(10) << itrTable->first;


			std::set<Laptop>::iterator itr = currRowBeg;
			for (int i = 0; i < 4; i++) {
				std::cout << std::setw(20) << retValue(itr, itrTable->first);
				itr++;
				if (itr == data.end()) break;
				
			}

			itrTable++;
			std::cout << std::endl;
		}

		std::cout << std::string(90, '=')<<std::endl;

		for (int i = 0; i < 4; i++) {
			currRowBeg++;
			if (currRowBeg == data.end())break;
		}

	}
}

void addLatop(std::set<Laptop>& data) {
	Laptop input;

	std::cout << "Enter laptop name: ";
	if (std::cin.peek() == ' ' || std::cin.peek() == '\n') {
		std::cin.ignore();
	}
	std::getline(std::cin, input.name);

	std::cout << "Enter laptop price: ";
	std::cin >> input.price;
	std::cout << "Enter laptop ram: ";
	std::cin >> input.ram;
	std::cout << "Enter laptop hdd: ";
	std::cin >> input.hdd;
	std::cout << "Enter laptop ssd: ";
	std::cin >> input.ssd;
	std::cout << "Enter laptop ghz: ";
	std::cin >> input.ghz;
	std::cout << "Enter laptop vram: ";
	std::cin >> input.vram;

	data.insert(input);
}

void removeLaptop(std::set<Laptop>& data) {
	std::set<Laptop>::iterator itr = data.begin();
	int counter = 1, choice;

	while (itr != data.end()) {
		std::cout << counter << ") " << itr->name << std::endl;
		itr++;
		counter++;
	}

	std::cout << "Choose laptop to remove: ";
	std::cin >> choice;

	itr = data.begin();

	for (int i = 1; i < choice; i++) itr++;

	data.erase(itr);
}

void setFilther(std::set<Laptop>& data, std::set<Laptop>& subdata) {
	subdata.clear();

	int lower_bound, upper_bound;
	bool ssd;


	std::cout << "Enter price range [min : max]";
	std::cin >> lower_bound >> upper_bound;

	std::cout << "Do you wish to have ssd (1, 0)";
	std::cin >> ssd;

	if (lower_bound > upper_bound) {
		std::swap(lower_bound, upper_bound);
	}

	std::set<Laptop>::iterator itr = data.begin();

	while (itr != data.end()) {
		if (itr->price >= lower_bound && itr->price <= upper_bound && (bool)itr->ssd == ssd) {
			subdata.insert(*itr);
		}
		itr++;
	}
}

int main() {
	std::set<Laptop> data, filthered_data;

	loadFile("laptops.txt", data);

	int choice;

	while (1) {
		std::cout << 
			"1) Print main set\n"
			"2) Print filtered set\n"
			"3) Add laptop to main set\n"
			"4) Remove laptop from main set\n"
			"5) Set filter\n";


		std::cin >> choice;

		std::cout << std::endl << std::endl;

		switch (choice)
		{
		case 1: printLaptopSet(data); break;
		case 2: printLaptopSet(filthered_data); break;
		case 3: addLatop(data); break;
		case 4: removeLaptop(data); break;
		case 5: setFilther(data, filthered_data); break;

		default:
			std::cout << "Not a valid option.." << std::endl;

			break;
		}
	}


}