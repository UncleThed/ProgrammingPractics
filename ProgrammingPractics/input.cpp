#include "stdafx.h"

using namespace std;

//�������� ������������ �����
int EnterNumber()
{
	char number = _getch();
	while (number > '9' || number < '0')
	{
		cout << "\n������������ ������!\n�������� ����� �� 0 �� 9: ";
		number = _getch();
	}
	return (int)number - 48; //������� ������� � �����
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
			cout << "������ �����!" << endl;
			cout << "������� ������������� ��������: ";
		}
		cin.clear();
		while (cin.get() != '\n');
	} while (!good);

	return value;
}