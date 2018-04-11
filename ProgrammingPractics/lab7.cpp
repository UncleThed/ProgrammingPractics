#include "stdafx.h"
#include "PersonList.h"

using namespace std;

void LaunchTask7()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	PersonList list;

	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);


		list.ShowDescriptions();
		//list.Show();

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "Введите значение для запуска соответствующего задания";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Добавить в список ветерана";
		cout << "\n 2: Добавить в список юнца";
		cout << "\n 3: Провести чистку";

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "\nДля завершения работы программы нажмите Esc";
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