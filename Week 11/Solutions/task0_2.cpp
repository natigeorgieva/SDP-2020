#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


/**
	Фунцкия, която по подаден символен низ (път във файловата система и името и разшиерението на файла)
	създава файл на това място с даденото име и разширение

	@param[int] filepath символния низ, който е пътя до директорията и името на файла
				по-надолу са описани някои забележки при работа с пътища
*/
void createFile(std::string filepath);

/**
	Фунцкия, която по подаден символен низ (път във файловата система и името и разшиерението на файла)
	отваря файл на това място с даденото име и разширение. Също така с флаг определяме дали ще добавяме
	в края на файла или не

	@param[in, out] fs обекта, към който ще свържем файла
	@param[in] filepath символния низ, който е пътя до директорията, името на файла и неговото разширение
	@param[in] append флага определящ дали ще добавяме в края или не
*/
void openFile(std::fstream& fs, std::string filepath, bool append);

/**
	Фунцкия, която по подаден обект от fstream флъшва буфера в свързания файл, прекратява връзката с него
	и освобождава потока (ако е вързан файл с него разбиар се!)

*/
void closeFile(std::fstream& fs);

/**
	Фунцкия, която по подаден обект от fstream принтира съдържанието на вързан към него файл от текущото място на четене.
	Накрая връща четенето в началото.

*/
void printFile(std::fstream& fs);



int main() {
	int choice;				///Променлива, която ще използваме, за да определим избора на потребителя
	std::string input = ""; ///Символен низ, който ще използваме при нужда за извличане/пъханена на низове от/в потоци
	std::fstream currFile;  ///Обекта от fstream, който ще използваме да пазим връзка с текущия файл


	std::cout << "Welcome to file operation example!\n\n";

	while (1) {
		///Изписваме на конзолата възможните операции на нашата програма, като форматираме изхода с фунцкии от iomanip
		std::cout << "Choose option:\n" << std::left;
		std::cout << std::setw(30) << "1)Create file by path" << std::setw(30) << "6)Set write to begining" << std::endl;
		std::cout << std::setw(30) << "2)Open file by path" << std::setw(30) << "7)Set write to the end" << std::endl;
		std::cout << std::setw(30) << "3)Close file" << std::setw(30) << "8)Move the writing with offset" << std::endl;
		std::cout << std::setw(30) << "4)Set read to begining" << std::setw(30) << "9)Write to file from current position" << std::endl;
		std::cout << std::setw(30) << "5)Set read with offset" << std::setw(30) << "10)Print whole file from current positon" << std::endl;
		std::cout << std::setw(30) << "100)EXIT" << std::endl;
		std::cin >> choice;
		///Понеже в програмта използваме cin>>(форматирано извличане от потока) и getline може да настъпят познати проблеми при четене от потока
		///За това след всяко форматирано извличане премахваме останалия не извлечен знак за край на тегленето, за да не объркаме getline, и да не
		///се притесняваме къде може да настанат грешки
		std::cin.ignore();

		///Използваме switch, за да реализираме менюто
		switch (choice)
		{
		case 1: {
			///Забележка:За файлове извън текущата директория на програмта пътя до тях съдържа знака '\', който C++ заедно със следния символ след него интерпретира като команда напр. \n - newline
			///За да използваме \ като обикновен знак, в низа трябва да го escape-нем т.е. да поставим още един \ след него
			///Напр: C:\\Documents\\User\\repo\\text.txt 
			std::cout << "Enter realitive or full path to the new file: ";
			std::cin >> input;
			std::cin.ignore();
			createFile(input);///Само извикваме фунцкия за създаването да файл, не го връзваме с никой поток
		}; break;
		case 2: {
			std::cout << "Enter realitive or full path to the new file: ";
			std::cin >> input;
			std::cin.ignore();
			bool flag;

			std::cout << "Do you wish to append (1/0): ";
			std::cin >> flag;
			std::cin.ignore();

			openFile(currFile, input, flag);
		}; break;
		case 3: {
			closeFile(currFile);
		}; break;
		case 4: {
			///Ако има вързан файл с потока, то нагласяме четенето от буфера да е в началото
			if (currFile.is_open()) {
				currFile.seekg(0, std::fstream::beg);
			}
			else {
				std::cout << "There isn't an opened file!\n";
			}
		}; break;
		case 5: {
			if (!currFile.is_open()) {
				std::cout << "There isn't an opened file!\n";
				break;
			}

			int offset;
			std::cout << "Offset : ";
			std::cin >> offset;
			std::cin.ignore();

			currFile.seekg(offset, currFile.tellg());
			if (!currFile) {
				std::cout << "Error when offsetting reading... Returning to begining..\n";
				currFile.clear();
				currFile.seekg(0, std::fstream::beg);
			}
		}; break;
		case 6: {
			if (currFile.is_open()) {
				currFile.seekp(0, std::fstream::beg);
			}
			else {
				std::cout << "There isn't an opened file!\n";
			}

		}; break;
		case 7: {
			if (currFile.is_open()) {
				currFile.seekp(0, std::fstream::end);
			}
			else {
				std::cout << "There isn't an opened file!\n";
			}
		}; break;
		case 8: {
			if (!currFile.is_open()) {
				std::cout << "There isn't an opened file!\n";
				break;
			}

			int offset;
			std::cout << "Offset : ";
			std::cin >> offset;
			std::cin.ignore();
			currFile.seekp(offset, currFile.tellp());
			if (!currFile) {
				std::cout << "Error when offsetting writing... Returning to begining..\n";
				currFile.clear();
				currFile.seekp(0, std::fstream::beg);
			}
		}; break;
		case 9: {
			std::getline(std::cin, input);
			currFile << input;
			currFile.clear();
			currFile.flush();
		}; break;
		case 10: {
			printFile(currFile);
		}; break;
		case 100: {
			return 0;
		}; break;
		default:
			break;
		}
	}
}

void createFile(std::string filepath) {
	std::fstream(filepath, std::fstream::out | std::fstream::trunc);
}

void openFile(std::fstream& fs, std::string filepath, bool append) {
	if (fs.is_open()) {
		fs.close();
	}

	if (append) {
		fs.open(filepath, std::fstream::in | std::fstream::out | std::fstream::app);
	}
	else {
		fs.open(filepath, std::fstream::in | std::fstream::out);
	}

	if (!fs) {
		std::cout << "Error when opening file...\n";
	}
}

void closeFile(std::fstream& fs) {
	if (fs.is_open()) {
		fs.close();
	}
	else {
		std::cout << "There isn't an opened file!\n";
	}
}

void printFile(std::fstream& fs) {
	if (!fs.is_open()) {
		std::cout << "There isn't an opened file!\n";
		return;
	}

	std::string input;
	while (!fs.eof()) {
		std::getline(fs, input);
		std::cout << input << '\n';
	}
	std::cout << "Reached EOF..";
	fs.clear();
	fs.seekg(0, std::fstream::beg);
}