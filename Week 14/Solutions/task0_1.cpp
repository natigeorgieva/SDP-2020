#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>

//Функция, която връща подадения низ от началото докато не се стигне до символ различен от буква
std::string removeDelims(std::string str) {
	int pos = 0;

	while (pos < str.length() && isalpha(str[pos])) {
		pos++;
	}

	return str.substr(0, pos);
}

//Функция, която преобразува даден низ към малки букви
void toLower(std::string& str) {
	for (char& c : str) {
		c = tolower(c);
	}

}

/**
	Функция, която по подаден път към файл в дисковата система прочита текстовия файл и 
	връща map с броя срещания на всяка дума

	@param[in] path символния низ указващ пътя към файла
	@return map<string, int>
				-key	-думата срещната в текстовия файл
				-value	-броя пъти на срещанията на дадената дума
*/
std::map<std::string, int> countWords(std::string path) {
	std::map<std::string, int> 
		result;		//Резултатния map

	std::fstream fstr(path, std::ios::in);	//Отваряме си потока за четене от файл

	if (!fstr.is_open()) {
		std::cout << "Error opening file...";
		exit(1);
	}

	std::string inpt; //Низ, който да съдържа текущата извлечена неформатирана дума 

	while (fstr >> inpt) { //Докато можем да извличаме от потока без проблеми

		//Форматираме си извлечената дума
		inpt = removeDelims(inpt);
		toLower(inpt);

		//Ако съществува такава дума в map-а, т.е. ключа се среща поне един път
		//Забележка: Понеже това е map, то един ключ или няма да се среща или ще се срещне само един път!
		if (result.count(inpt)) {
			result[inpt]++;		//Увеличаваме стойността на срещанията с 1
		}
		//В противен случай тази дума още не е в map-а
		else {
			result[inpt] = 1;  //Създаване на записа в map-а и задаване стойност на 1
		}
	}

	return result;
}

//По подаден map принтираме неговите елементи
void printMap(std::map<std::string, int> mp) {
	std::map<std::string, int>::iterator itr = mp.begin(); //Взимаме си итератор към началото на map-a

	//Обхождаме структурата от начало до край
	while (itr != mp.end()) {
		//Принтираме стойностите на текущата двойка елементи
		//key = first, value = second
		std::cout << itr->first << " : " << itr->second << std::endl;
		itr++;
	}
}

/**
	По подаден map взимаме негов елемент <string, int>, разменяме стойностите му и 
	пъхаме новата наредена двойка <int, string> в multimap<int, string>. Така за 
	всеки елемент от подадения map.
*/
std::multimap<int, std::string> toMultiMap(std::map<std::string, int>& mp) {
	std::multimap<int, std::string> mmp;	//Създаваме си желания multimap

	//Използваме range-based for цикъл и така обхождаме всеки елемент от подадения map
	for (auto elem : mp) {
		mmp.insert(std::pair<int, std::string>(elem.second, elem.first));
	}

	return mmp;
}

//Функция, която принтира на екрана всички елементи на multimap
void printMMap(std::multimap<int, std::string>& mmp) {
	std::multimap<int, std::string>::reverse_iterator itr = mmp.rbegin();

	while (itr != mmp.rend()) {
		std::cout << itr->first << " : " << itr->second << std::endl;
		itr++;
	}
}

//Функция, която принтира на екрана елементите на multimap, които имат ключа key
void printMMapByVal(std::multimap<int, std::string>& mmp, int key) {
	//Създаваме този много страшен интератор :D
	std::pair <std::multimap<int, std::string>::iterator, std::multimap<int, std::string>::iterator> ret;

	//Извикваме функция, която връща итератори към първото и последното срещане
	//на елементите с дадения ключ
	ret = mmp.equal_range(key);
	
	//Принтираме си всички елементи в този диапазон
	for (std::multimap<int, std::string>::iterator itr = ret.first; itr != ret.second; ++itr) {
		std::cout << itr->first << " : " << itr->second << std::endl;
	}
}

int main() {
	std::map<std::string, int> mp = countWords("lorem.txt");
	printMap(mp);

	std::cout << "----------------------------------------------" << std::endl;

	std::multimap<int, std::string> mmp = toMultiMap(mp);
	printMMap(mmp);

	std::cout << "----------------------------------------------" << std::endl;
	int inpt;
	std::cout << "Enter number: ";
	std::cin >> inpt;
	std::cout << "The words that ocurre excatly " << inpt << " times are:\n";
	printMMapByVal(mmp, inpt);
}