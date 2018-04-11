#include "stdafx.h"
#include "List.h"

using namespace std;

template <typename T>
void List<T>::Add(T* data)
{
	ListItem* temp = new ListItem(data);
	if (!_head)
	{
		_head = temp;
	}
	else
	{
		temp->Prev = _tail;
		_tail->Next = temp;
	}
	_tail = temp;
	_count++;
}

template <typename T>
T* List<T>::Find(int index)
{
	if (index < 0)
	{
		return nullptr;
	}

	ListItem* searchedItem = _head;

	for (int i = 0; i < index; i++)
	{
		if (searchedItem->Next)
		{
			searchedItem = searchedItem->Next;
		}
	}
	return searchedItem->GetValue();
}

template <typename T>
int List<T>::IndexOf(T* data)
{
	ListItem* searchedData = _head;
	int index = 0;
	while (searchedData)
	{
		if (searchedData->GetValue() == data)
		{
			return index;
		}
		index++;
		searchedData = searchedData->Next;
	}
	return -1;
}

template <typename T>
void List<T>::Remove(T* data)
{
	ListItem* deletedItem = _head;

	if (data)
	{
		while (deletedItem->GetValue() != data)
		{
			if (!deletedItem->Next)
			{
				return;
			}
			deletedItem = deletedItem->Next;
		}
	}
	else
	{
		return;
	}

	if (deletedItem->Prev)
		deletedItem->Prev->Next = deletedItem->Next;
	else
		_head = deletedItem->Next;

	if (deletedItem->Next)
		deletedItem->Next->Prev = deletedItem->Prev;
	else
		_tail = deletedItem->Prev;

	delete deletedItem;
}

template <typename T>
void List<T>::RemoveAt(int index)
{
	ListItem* deletedItem = _head;

	if (index >= 0)
	{
		for (int i = 0; i < index; i++)
		{
			if (!deletedItem->Next)
			{
				return;
			}
			deletedItem = deletedItem->Next;
		}
	}
	else
	{
		return;
	}

	if (deletedItem->Prev)
		deletedItem->Prev->Next = deletedItem->Next;
	else
		_head = deletedItem->Next;

	if (deletedItem->Next)
		deletedItem->Next->Prev = deletedItem->Prev;
	else
		_tail = deletedItem->Prev;

	delete deletedItem;
}

template <typename T>
void List<T>::Clear()
{
	ListItem* temp = _head;
	ListItem* tempNext;
	while (temp)
	{
		tempNext = temp->Next;
		delete temp;
		temp = tempNext;
	}
	_head = nullptr;
	_tail = nullptr;
	_count = 0;
}

template <typename T>
int List<T>::GetCount()
{
	return _count;
}

template <typename T>
void List<T>::ShowDescriptions()
{
	ListItem* temp = _head;

	if (temp)
	{
		cout << "Список:\n";
		cout << "----------------------------------------------------\n";
		while (temp)
		{
			if (temp->GetValue()->GetAge() < 18)
			{
				Child* child = (Child*)temp->GetValue();
				cout << child->GetDescription() << endl;
			}
			else
			{
				Adult* adult = (Adult*)temp->GetValue();
				cout << adult->GetDescription() << endl;
			}
			temp = temp->Next;
		}
	}
	else
	{
		cout << "Список пуст\n";
	}
	cout << endl;
}

template <typename T>
void List<T>::Show()
{
	ListItem* temp = _head;

	if (temp)
	{
		cout << "Список:\n";
		cout << "----------------------------------------------------\n";
		cout.width(12); cout << "Индекс";
		cout.width(12); cout << "Имя";
		cout.width(12); cout << "Фамилия";
		cout.width(12); cout << "Пол\n";

		int index = 0;

		while (temp)
		{
			cout.width(12); cout << index++;
			cout.width(12); cout << temp->GetValue()->GetName();
			cout.width(12); cout << temp->GetValue()->GetSurname();
			cout.width(12);
			switch (temp->GetValue()->GetSex())
			{
			case 0:
				cout << "Женский\n";
				break;
			case 1:
				cout << "Мужской\n";
				break;
			}
			temp = temp->Next;
		}
	}
	else
	{
		cout << "Список пуст\n";
	}
	cout << endl;
}