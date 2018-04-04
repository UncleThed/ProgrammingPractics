#include "stdafx.h"
#include "lab4.h";

using namespace std;

Person MakeRandomPerson()
{
	const char* MaleNames[] = { "Иван", "Дмитрий", "Олег", "Александр", "Андрей", "Денис", "Павел", "Сергей", "Владимир", "Константин", "Георгий", "Виктор" };
	const char* FamaleNames[] = { "Мария", "Анна", "Екатерина", "Елизавета", "Кристина", "Ксения", "Елена", "Галина", "Анастасия", "Виктория", "Валентина", "София" };
	const char* MaleSurnames[] = { "Макаров", "Достоевский", "Захаров", "Кузнецов", "Иванов", "Смирнов", "Васильев", "Петров", "Соколов", "Дубровский", "Новиков", "Борисов" };
	const char* FamaleSurnames[] = { "Дмириева", "Медведева", "Антоновна", "Жукова", "Орлова", "Козлова", "Волкова", "Морозова", "Быкова", "Миронова", "Власова", "Тихонова" };

	Person person;
	person.Sex = Sex(rand() % 2);

	if (person.Sex)
	{
		CopyConstString(person.Name, MaleNames[rand() % 12]);
		CopyConstString(person.Surname, MaleSurnames[rand() % 12]);
	}
	else
	{
		CopyConstString(person.Name, FamaleNames[rand() % 12]);
		CopyConstString(person.Surname, FamaleSurnames[rand() % 12]);
	}
	return person;
}

void AddLast(List* list)
{
	Node* newNode = new Node;
	newNode->person = MakeRandomPerson();

	if (list->tail == NULL)
		list->head = newNode;
	else
	{
		newNode->prev = list->tail;
		list->tail->next = newNode;
	}
	list->tail = newNode;
}

void Insert(List* list, Person person, int index)//todo персону передавать по указателю
{
	Node* newNode = new Node;
	newNode->person = person;

	Node* node = list->head;

	if (index >= 0 && node)
	{
		for (int i = 0; i < index; i++)
		{
			if (!node->next)
			{
				return;
			}
			node = node->next;
		}
	}
	else
	{
		return;
	}

	newNode->next = node;
	newNode->prev = node->prev;

	if (node->prev)
		node->prev->next = newNode;
	else
		list->head = newNode;
	node->prev = newNode;
}

Person* Get(List* list, int index)
{
	Node* node = list->head;

	if (index >= 0)
	{
		for (int i = 0; node; i++)
		{
			if (i == index)
			{
				return &node->person;
			}
			node = node->next;
		}
	}
	return NULL;
}

void Remove(List* list, int index)
{
	Node* node = list->head;

	if (index >= 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (!node->next)
			{
				return;
			}
			node = node->next;
		}
	}
	else
	{
		return;
	}

	if (node->prev)
		node->prev->next = node->next;
	else
		list->head = node->next;

	if (node->next)
		node->next->prev = node->prev;
	else
		list->tail = node->prev;

	delete node;
}

void Clear(List* list)
{
	Node* node = list->head;
	if (node)
	{
		while (node->next)
		{
			node = node->next;
			delete node->prev;
		}
		delete node;

		list->head = NULL;
		list->tail = NULL;
	}
}

void Show(List* list)
{
	Node* node = list->head;

	if (node)
	{
		cout << "Список:\n";
		cout << "----------------------------------------------------\n";
		cout.width(12); cout << "Индекс";
		cout.width(12); cout << "Имя";
		cout.width(12); cout << "Фамилия";
		cout.width(12); cout << "Пол\n";
		
		int index = 0;

		while (node)
		{
			cout.width(12); cout << index++;
			cout.width(12); cout << node->person.Name;
			cout.width(12); cout << node->person.Surname;
			cout.width(12);
			switch (node->person.Sex)
			{
			case 0:
				cout << "Женский\n";
				break;
			case 1:
				cout << "Мужской\n";
				break;
			}
			node = node->next;
		}
	}
	else
	{
		cout << "Список пуст\n";
	}
	cout << endl;
}

//Лаунчер четвертой лабораторной
void LaunchTask4()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	List* list = new List;
	
	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);
		Show(list);

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "Введите значение для запуска соответствующего задания";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: Добавление в конец списка";
		cout << "\n 2: Добавление по индексу";
		cout << "\n 3: Получение элемента списка по индексу";
		cout << "\n 4: Удаление по индексу";
		cout << "\n 5: Очистка списка";

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
			AddLast(list);
			break;
		}
		case '2':
		{
			cout << "Добавление по индексу: ";
			int index = EnterInteger();

			Insert(list, ReadPerson(), index);

			system("pause");
			break;
		}
		case '3':
		{
			cout << "Получение элемента списка по индексу: ";
			int index = EnterInteger();

			Person* person = Get(list, index);

			if (person)
			{
				PrintPerson(*Get(list, index));
			}
			else
			{
				cout << "По заданному индексу ничего не найдено" << endl;
			}

			system("pause");
			break;
		}
		case '4':
		{
			cout << "Удаление по индексу: ";
			int index = EnterInteger();

			Remove(list, index);
			break;
		}
		case '5':
		{
			Clear(list);
			break;
		}
		}
	}
}