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

void ParityOddness()
{
	int a;
	cout << "\nEnter value for check on even/odd: ";
	cin >> a;
	if (a % 2 == 0)
	{
		cout << "\nValue is " << a << " even!" << endl;
	}
	else
	{
		cout << "\nValue is " << a << " odd!" << endl;
	}
}

void Multiplicity()
{
	int a;
	cout << "\nEnter value for check on even/odd: ";
	cin >> a;
	if (a % 5 == 0)
	{
		cout << "\nValue " << a << " multiples 5!" << endl;
	}
	else if (a % 2 == 0)
	{
		cout << "\nValue " << a << " multiples 2!" << endl;
	}
	else
	{
		cout << "\nValue " << a << " doesn`t multiply 5 or 2!" << endl;
	}
}

void Precondition()
{
	int a = 0;
	while (a < 5)
	{
		cout << "\nValue is " << a << " now";
		a++;
	}
	cout << endl;
}

void Postcondition()
{
	int a = 0;
	do
	{
		cout << "Value is " << a << " now \n";
		a++;
	} while (a < 5);
}

void Iterative()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		cout << "\nIteration " << i;
	}
	cout << endl << endl;
	for (int i = 0; i < a; i++)
	{
		a--;
		cout << "Iteration " << i << " Value is " << a << endl;
	}
}

void EarlyCompletion()
{
	int a = 10;
	for (int i = 0; i < 10; i++)
	{
		a--;
		if (i >= a)
		{
			cout << "\nI is more or equal A! Break of cycle";
			break;
		}
	}
	cout << "\nA is " << a << endl;
}

void Converting()
{
	int a = 5;
	int b = 3;
	float z;

	z = a;
	cout << "\nValue of z is " << z;

	a = (int)z;
	cout << "\nValue of a is " << a;

	z = a / b;
	cout << "\nValue of z is " << z;
	z = ((float)a) / b;
	cout << "\nValue of z is " << z << endl;
}

void LaunchTask1()
{
	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	while (AsciiValue != 27)
	{
		system("cls");

		cout << "Введите значение с клавиатуры соответствующее";
		cout << "\n - числу от 1 до 9";
		cout << "\n - символам a, b";
		cout << "\nДля завершения работы программы нажмите Esc";
		cout << "\n__________________________________________\n";

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
		case '5':
			ParityOddness();
			cout << endl;
			system("pause");
			break;
		case '6':
			Multiplicity();
			cout << endl;
			system("pause");
			break;
		case '7':
			Precondition();
			cout << endl;
			system("pause");
			break;
		case '8':
			Postcondition();
			cout << endl;
			system("pause");
			break;
		case '9':
			Iterative();
			cout << endl;
			system("pause");
			break;
		case 'a':
			EarlyCompletion();
			cout << endl;
			system("pause");
			break;
		case 'b':
			Converting();
			cout << endl;
			system("pause");
			break;
		}
	}
}