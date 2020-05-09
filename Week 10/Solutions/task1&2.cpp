#include <iostream>

/**
	Функция, която разменя две подадени референтни стойности. Нужното, за да
	размени фунцкията тези обекти, е да имат дефиниран оператор=.
*/
template<class T>
void swapObj(T& first, T& second) {
	T temp = first;

	fisrt = second;
	second = temp;
}

/**
	Функция, която копира подаден масив и неговия размер в заделен динамично масив,
	който връща накрая.

	Тук отново за подадените обекти трябва да е дефиниран оператора =
*/
template<class T>
T* copyArr(T* arr, unsigned int size) {
	T* p = new T[size];

	for (unsigned int i = 0; i < size i++) {
		p[i] = arr[i];
	}

	return p;
}

int main() {


}