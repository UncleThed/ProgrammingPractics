#include "stdafx.h"
#include "lab4.h";

using namespace std;

Person MakeRandomPerson()
{
	const char* MaleNames[] = { "����", "�������", "����", "���������", "������", "�����", "�����", "������", "��������", "����������", "�������", "������" };
	const char* FamaleNames[] = { "�����", "����", "���������", "���������", "��������", "������", "�����", "������", "���������", "��������", "���������", "�����" };
	const char* MaleSurnames[] = { "�������", "�����������", "�������", "��������", "������", "�������", "��������", "������", "�������", "����������", "�������", "�������" };
	const char* FamaleSurnames[] = { "��������", "���������", "���������", "������", "������", "�������", "�������", "��������", "������", "��������", "�������", "��������" };

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

void Insert(List* list, Person person, int index)//todo ������� ���������� �� ���������
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
		cout << "������:\n";
		cout << "----------------------------------------------------\n";
		cout.width(12); cout << "������";
		cout.width(12); cout << "���";
		cout.width(12); cout << "�������";
		cout.width(12); cout << "���\n";
		
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
				cout << "�������\n";
				break;
			case 1:
				cout << "�������\n";
				break;
			}
			node = node->next;
		}
	}
	else
	{
		cout << "������ ����\n";
	}
	cout << endl;
}

//������� ��������� ������������
void LaunchTask4()
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	char key;						//��������� � ���������� ������
	int AsciiValue = 0;				//��� ���� ���

	List* list = new List;
	
	while (AsciiValue != 27)
	{
		system("cls");

		SetConsoleTextAttribute(hStdOut, 2);
		Show(list);

		SetConsoleTextAttribute(hStdOut, 6);
		cout << "������� �������� ��� ������� ���������������� �������";

		SetConsoleTextAttribute(hStdOut, 5);
		cout << "\n 1: ���������� � ����� ������";
		cout << "\n 2: ���������� �� �������";
		cout << "\n 3: ��������� �������� ������ �� �������";
		cout << "\n 4: �������� �� �������";
		cout << "\n 5: ������� ������";

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
			AddLast(list);
			break;
		}
		case '2':
		{
			cout << "���������� �� �������: ";
			int index = EnterInteger();

			Insert(list, ReadPerson(), index);

			system("pause");
			break;
		}
		case '3':
		{
			cout << "��������� �������� ������ �� �������: ";
			int index = EnterInteger();

			Person* person = Get(list, index);

			if (person)
			{
				PrintPerson(*Get(list, index));
			}
			else
			{
				cout << "�� ��������� ������� ������ �� �������" << endl;
			}

			system("pause");
			break;
		}
		case '4':
		{
			cout << "�������� �� �������: ";
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