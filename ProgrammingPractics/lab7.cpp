#include "stdafx.h"
#include "PersonList.h"

using namespace std;

void LaunchTask7()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//��������� � ���������� ������
	int AsciiValue = 0;				//��� ���� ���

	PersonList list;

	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);


		list.ShowDescriptions();
		//list.Show();

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "������� �������� ��� ������� ���������������� �������";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: �������� � ������ ��������";
		cout << "\n 2: �������� � ������ ����";
		cout << "\n 3: �������� ������";

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "\n��� ���������� ������ ��������� ������� Esc";
		cout << "\n======================================================\n" << endl;

		key = _getch();
		AsciiValue = key;

		SetConsoleTextAttribute(hStdOut, 7);

		switch (AsciiValue)
		{
		case '1':
		{
			list.Add(Adult::GetRandom());
			break;
		}
		case '2':
		{
			list.Add(Child::GetRandom());
			break;
		}
		case '3':
		{
			list.Clear();
			break;
		}
		}
	}
}