#pragma once
#include <iostream>

//Преименуваме си типовете, които са дълги и ще използваме често
typedef unsigned int uint;
typedef unsigned short int usint;
typedef long long int lint;

class BigInt
{
	char* str;		/// Указателя, в който ще помним адреса на заделения масив в паметта
	uint arrSize;	/// Размерта на масива
	uint currSize;  /// Използваната големина от масива
	usint base;		/// Основата на бройната система на записаното число
	bool sign;		/// Знака на числото;

	/*
		Заделя нов динамичен масив с 10 повече елемента от текущия, копира информацията
		от текущия в новия, освобождава заделената памет от текущия масив и присвоява адреса
		на новия масив в указателя
	*/
	void resize();	

	/*
		Фунцкия, която прилага deepcopy, като копира данните от bi
		в обекта, на който е приложена функцията
	*/
	void copy(const BigInt& bi);

	/*
		Фунцкия, която по даден ASCII код връща съответния char
	*/
	char toChar(usint id) const;

	/*
		Фунцкия, която по подаден символ връща стойността в десетична система
	*/
	usint toInt(char id) const;

	/*
		фунцкия, която проверява кой от обектите е с по-голямо число 
		по модул.

		1 - левия > десния
		0 - левия == десния
		-1 - левия < десния
	*/
	int cmpAbs(const BigInt& bi);

	/*
		Фунцкия, която събира две числа записани в символен низ по модул
	*/
	BigInt sumAbs(const BigInt& bi);

	/*
		фунцкия, която изважда две числа записани в символен низ по модул
	*/
	BigInt subAbs(const BigInt& bi);

	/*
		Фунцкия, която конвентира число записано в символен низ в някоя бройна 
		система, в число записано в символен низ в десетична система 
	*/
	BigInt toDec() const;

	/*
		Фунцкия, която конвентира число записано в символен низ в десетична бройна
		система, в число записано в символен низ в друга система
	*/
	BigInt toBase(usint base) const;


public:
	/*** Голямата четворка ***/

	BigInt();
	BigInt(const BigInt& bi);
	BigInt(usint n, lint num);
	BigInt& operator=(const BigInt& bi);

	/************************/



	/***     Оператори    ***/

	BigInt operator+(const BigInt& bi);
	BigInt operator+(lint num);
	friend BigInt operator+(lint num, const BigInt& bi);

	BigInt operator-(const BigInt& bi);
	BigInt operator-(lint num);
	friend BigInt operator-(lint num, const BigInt& bi);

	BigInt operator++();
	BigInt operator++(int);

	BigInt operator--();
	BigInt operator--(int);

	friend std::istream& operator>>(std::istream& is, BigInt& bi);
	friend std::ostream& operator<<(std::ostream& os, BigInt bi);

	/************************/
};

