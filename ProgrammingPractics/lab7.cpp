#include "stdafx.h"
#include "List.h"

using namespace std;

void LaunchTask7()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);


		SetConsoleTextAttribute(hStdOut, 6);
		cout << "Введите значение от 1 до 4";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Демонстрация работы списка с переменными типа double";
		cout << "\n 2: Демонстрация работы списка с переменными типа Person*";
		cout << "\n 3: Демонстрация работы списка с переменными типа double[5]";
		cout << "\n 4: Демонстрация работы списка с переменными типа List<double>";

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
			List<double> list;

			cout << "\nДобавим пять элементов\n";

			list.Add(5.4);
			list.Add(9.8);
			list.Add(-49.2);
			list.Add(4.07);
			list.Add(-0.8);

			list.Show();
			system("pause");

			cout << "\nУдалим третий элемент\n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "\nДобавим элемент по четвертому индексу\n";

			list.InsertByIndex(50.0, 3);

			list.Show();
			system("pause");

			break;
		}

		case '2':
		{
			List<Person*> list;

			cout << "\nДобавим пять элементов\n";

			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());
			list.Add(GetRandomPerson());

			list.Show();
			system("pause");

			cout << "\nУдалим третий элемент\n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "\nДобавим элемент по четвертому индексу\n";

			list.InsertByIndex(GetRandomPerson(), 3);

			list.Show();
			system("pause");

			break;
		}

		case '3':
		{
			List<double*> list;
			
			double arr1[] = { 76.4, -9.8, -6.78, -90.1, -0.8 };
			double arr2[] = { 3.7, -94.08, 65.8, 789.01, -0.86 };
			double arr3[] = { -6.8, 9.345, 6.7, -90.1, 0.16 };
			double arr4[] = { -0.34, -9.4, -6.08, 90.1, -0.7 };
			double arr5[] = { 5.4, -0.3, -6.78, -9.1, 0.76 };
			double arr6[] = { -50.04, 9.8, 6.8, -5.1, -0.76 };

			cout << "\nДобавим пять элементов\n";

			list.Add(arr1);
			list.Add(arr2);
			list.Add(arr3);
			list.Add(arr4);
			list.Add(arr5);

			list.Show();
			system("pause");

			cout << "\nУдалим третий элемент\n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "\nДобавим элемент по четвертому индексу\n";

			list.InsertByIndex(arr6, 3);

			list.Show();
			system("pause");

			break;
		}

		case '4':
		{
			List<List<double>*> list;

			//////////////////////////////////////////////

			List<double> list1;
			list1.Add(53.4);
			list1.Add(9.8);
			list1.Add(-49.2);
			list1.Add(4.07);
			list1.Add(-0.8);

			List<double> list2;
			list2.Add(53.4);
			list2.Add(7.9);
			list2.Add(49.02);
			list2.Add(-90.7);
			list2.Add(7.048);

			List<double> list3;
			list3.Add(-3.14);
			list3.Add(5.98);
			list3.Add(9.0);
			list3.Add(34.58);
			list3.Add(-2.17);

			List<double> list4;
			list4.Add(18.999);
			list4.Add(-5.0);
			list4.Add(94.2);
			list4.Add(-4.7);
			list4.Add(1.4);

			List<double> list5;
			list5.Add(-3.2);
			list5.Add(-10.8);
			list5.Add(51.2);
			list5.Add(4.88);
			list5.Add(-0.8);

			List<double> list6;
			list6.Add(53.4);
			list6.Add(9.8);
			list6.Add(-49.2);
			list6.Add(95.07);
			list6.Add(-234.6);

			/////////////////////////////////////////////////

			cout << "\nДобавим пять элементов\n";

			list.Add(&list1);
			list.Add(&list2);
			list.Add(&list3);
			list.Add(&list4);
			list.Add(&list5);

			list.Show();
			system("pause");

			cout << "\nУдалим третий элемент\n";

			list.RemoveAt(2);

			list.Show();
			system("pause");

			cout << "\nДобавим элемент по четвертому индексу\n";

			list.InsertByIndex(&list6, 3);

			list.Show();
			system("pause");

			break;
		}
		}
	}
}