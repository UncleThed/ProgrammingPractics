#include "stdafx.h"

using namespace std;

//Проверка корректности ввода
int EnterNumber()
{
	char number = _getch();
	while (number > '9' || number < '0')
	{
		cout << "\nНеподходящий символ!\nВыберите цифру от 0 до 9: ";
		number = _getch();
	}
	return (int)number - 48; //перевод символа в цифру
}
int EnterInteger()
{
	int value;
	bool good = true;
	do
	{
		cin >> value;
		if (!(good = cin.good()))
		{
			cout << "Ошибка ввода!" << endl;
			cout << "Введите целочисленное значение: ";
		}
		cin.clear();
		while (cin.get() != '\n');
	} while (!good);

	return value;
}