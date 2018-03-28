#include "stdafx.h"
#include "PersonList.h"

using namespace std;

void LaunchTask5()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//��������� � ���������� ������
	int AsciiValue = 0;				//��� ���� ���

	PersonList list1;

	list1.Add(Person::GetRandomPerson());
	list1.Add(Person::GetRandomPerson());
	list1.Add(Person::GetRandomPerson());

	PersonList list2;

	list2.Add(Person::GetRandomPerson());
	list2.Add(Person::GetRandomPerson());
	list2.Add(Person::GetRandomPerson());


	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);
		
		cout << "������ ";
		list1.Show();
		cout << "������ ";
		list2.Show();

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "������� �������� ��� ������� ���������������� �������";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: �������� � ����� ������� ������";
		cout << "\n 2: ����������� ������� �� ������� ������ �� ������";
		cout << "\n 3: ������� ������� �� ������� ������";
		cout << "\n 4: �������� ������ ������";

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
			list1.Add(Person::GetRandomPerson());
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
		}
	}
}