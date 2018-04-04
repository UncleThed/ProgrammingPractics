#include "stdafx.h"
#include "PersonList.h"
#include "PersonTools.h"

using namespace std;

void LaunchTask5()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	PersonList list1;

	list1.Add(GetRandomPerson());
	list1.Add(GetRandomPerson());
	list1.Add(GetRandomPerson());

	PersonList list2;

	list2.Add(GetRandomPerson());
	list2.Add(GetRandomPerson());
	list2.Add(GetRandomPerson());


	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);
		
		cout << "Первый ";
		list1.Show();
		cout << "Второй ";
		list2.Show();

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "Введите значение для запуска соответствующего задания";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Добавить в конец первого списка";
		cout << "\n 2: Скопировать второго из первого списка во второй";
		cout << "\n 3: Удалить второго из первого списка";
		cout << "\n 4: Очистить первый список";
		cout << "\n 5: Ввод-вывод персоны";

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
			list1.Add(GetRandomPerson());
			break;
		}
		case '2':
		{
			list2.Add(list1.Find(1));
			break;
		}
		case '3':
		{
			list1.RemoveAt(1);
			break;
		}
		case '4':
		{
			list1.Clear();
			break;
		}
		case '5':
		{
			Person* person = ReadPerson();
			ShowPerson(person);

			system("pause");
			break;
		}
		}
	}
}