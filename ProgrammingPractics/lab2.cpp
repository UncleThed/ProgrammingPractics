#include "stdafx.h"

using namespace std;

int isCorrected()
{
	int i;
	bool good = true;
	do
	{
		cout << "Enter [i]: ";
		cin >> i;
		if (!(good = cin.good()))
			cout << "Fatal input error!" << endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	} while (!good);

	return i;
}

void PrintHelloWorld()
{
	cout << "\nHello World!!!";
}

double MakeCalculation(int value1, int value2, char operationKey)
{	
	switch (operationKey)
	{
	case '+':
		return (value1 + value2);
		break;
	case '-':
		return (value1 - value2);
		break;
	case '*':
		return (value1 * value2);
		break;
	case '/':
		return (value1 / value2);
		break;
	case '%':
		return (value1 % value2);
		break;
	}
}

int Divide(int dividend, int divisor)
{
	int result;
	result = dividend / divisor;
	return result;
}

void LaunchTask2()
{
	char key;						//��������� � ���������� ������
	int AsciiValue = 0;				//��� ���� ���

	while (AsciiValue != 27)
	{
		system("cls");

		cout << "������� �������� � ���������� ���������������";
		cout << "\n - ����� �� 1 �� 9";
		cout << "\n - �������� a, b";
		cout << "\n��� ���������� ������ ��������� ������� Esc";
		cout << "\n__________________________________________\n";

		key = _getch();
		AsciiValue = key;

		switch (AsciiValue)
		{
		case '1':
			PrintHelloWorld();
			cout << endl;
			system("pause");
			break;
		case '2':
		{
			cout << "������� ������ �����: ";
			int value1;
			value1 = isCorrected();

			cout << "������� ������ �����: ";
			int value2;
			value2 = isCorrected();

			cout << "Enter mathematic operation (+, -, *, /, %)";
			char key;
			key = _getch();
			while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
			{
				cout << "\nINCORRECT SYMBOL!!!\nPlease, enter(+, -, *, /, %):";
				key = _getch();
			}

			cout << endl << value1 << " " << key << " " << value2 << " = " << MakeCalculation(value1, value2, key) << endl;
			system("pause");
			break;
		}
		case '3':
		{
			cout << "������� ������ �����: ";
			int dividend;
			dividend = isCorrected();

			cout << "������� ������ �����: ";
			int divisor;
			divisor = isCorrected();

			int result = Divide(dividend, divisor);
			cout << endl << dividend << " / " << divisor << " = " << result << endl;
			system("pause");
			break;
		}
		}


	}
}