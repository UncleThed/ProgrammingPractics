#include "stdafx.h"

#include <conio.h>
#include <iostream>

using namespace std;

void Initialization()
{
	cout << "\nHello, World!\n";
	
	int a;
	a = 5;
	int b = 3;
	cout << "\nVariable a equals " << a;
	cout << "\nVariable b equals " << b;
	cout << "\nSumm of a and b equal = " << a + b << endl;
}

void Division()
{
	int a = 5;
	int b = 2;
	float z = 5.0;
	float y = 3.0;
	cout << "\nFloat variables division: " << z / y;
	cout << "\nInteger variables division: " << a / b << endl;

}

void Addition()
{
	int a;
	int b;

	cout << "\n-- - Program for integer summation-- - ";
	cout << "\n\nEnter first integer value: ";
	cin >> a;
	cout << "Enter second integer value: ";
	cin >> b;
	cout << "\nSumm of " << a << " and " << b << " equals " << a + b << endl;

}

void Pointer()
{
	int value;
	int* pointer;
	int anotherValue;
	value = 5;
	pointer = &value;

	anotherValue = *pointer;

	cout << "\nValue, stored in pointer: " << anotherValue;
	cout << "\nAddress in pointer: " << pointer;
	cout << "\nValue in pointer: " << *pointer << endl;

}

void LaunchTask1()
{
	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	while (AsciiValue != 27)
	{
		system("cls");


		key = _getch();
		AsciiValue = key;

		switch (AsciiValue)
		{
		case '1':
			Initialization();
			cout << endl;
			system("pause");
			break;
		case '2':
			Division();
			cout << endl;
			system("pause");
			break;
		case '3':
			Addition();
			cout << endl;
			system("pause");
			break;
		case '4':
			Pointer();
			cout << endl;
			system("pause");
			break;
		}
	}
}