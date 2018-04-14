#pragma once
#include "Person.h"
#include "PersonTools.h"

using namespace std;

template <typename T>
class List
{
private:

	template <typename TNode>
	class ListItem
	{
	public:

		ListItem()
		{
		};

		ListItem(TNode data)
		{
			_value = data;
		};

		TNode GetValue()
		{
			return _value;
		};

		ListItem<TNode>* Next = nullptr;
		ListItem<TNode>* Prev = nullptr;

	private:
		TNode _value;
	};

	ListItem<T>* _head = nullptr;
	ListItem<T>* _tail = nullptr;
	int _count = 0;

public:
	List() {};

	/*ListItem<T>* GetHead()
	{
		return _head;
	};*/

	void Add(T data)
	{
		ListItem<T>* temp = new ListItem<T>(data);
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
	};

	void InsertByIndex(T element, int index)
	{
		if (_head == nullptr || index < 0)
		{
			return;
		}

		ListItem<T>* temp = _head;
		int i = 0;
		while (i < index)
		{
			temp = temp->Next;
			i++;
			if (temp == nullptr)
			{
				Add(element);
				return;
			}
		};


		if (temp == _head)
		{
			ListItem<T>* newNode = new ListItem<T>();
			_head->Prev = newNode;
			newNode->Next = _head;

			_head = newNode;
			return;
		}

		if (temp == _tail)
		{
			ListItem<T>* newNode = new ListItem<T>(element);
			_tail->Prev->Next = newNode;
			newNode->Prev = _tail->Prev;
			newNode->Next = _tail;
			_tail->Prev = newNode;
			_tail->Next = nullptr;
			return;
		}


		if (temp != nullptr)
		{
			ListItem<T>* newNode = new ListItem<T>(element);
			temp->Prev->Next = newNode;
			newNode->Prev = temp->Prev;
			newNode->Next = temp;
			temp->Prev = newNode;
		}
		return;
	}

	T Find(int index)
	{
		if (index < 0)
		{
			return nullptr;
		}

		ListItem<T>* searchedItem = _head;

		for (int i = 0; i < index; i++)
		{
			if (searchedItem->Next)
			{
				searchedItem = searchedItem->Next;
			}
		}
		return searchedItem->GetValue();
	};

	int IndexOf(T data)
	{
		ListItem<T>* searchedData = _head;
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
	};

	int GetCount()
	{
		return _count;
	};

	void Remove(T data)
	{
		ListItem<T>* deletedItem = _head;

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
	};

	void RemoveAt(int index)
	{
		ListItem<T>* deletedItem = _head;

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
	};

	void Show()
	{
		ListItem<T>* temp = _head;

		if (temp)
		{
			cout << "Список:\n";
			cout << "----------------------------------------------------\n";

			int index = 0;

			while (temp)
			{
				cout << index++ << ":\t" << temp->GetValue() << endl;
				temp = temp->Next;
			}
		}
		else
		{
			cout << "Список пуст\n";
		}
		cout << endl;
	};

	void Clear()
	{
		ListItem<T>* temp = _head;
		ListItem<T>* tempNext;
		while (temp)
		{
			tempNext = temp->Next;
			delete temp;
			temp = tempNext;
		}
		_head = nullptr;
		_tail = nullptr;
		_count = 0;
	};

	~List()
	{
		Clear();
	};

	friend std::ostream & operator<<(std::ostream & os, List<T>* l)
	{
		ListItem<T>* temp = l->_head;
		while (temp)
		{
			os << temp->GetValue() << ' ';
			temp = temp->Next;
		}
		return os;
	}
};

ostream& operator << (ostream &os, Person* person)
{
	os << '(' << person->GetName() << ", " << person->GetSurname() << ", " << person->GetAge() << ", " << person->GetSex() << ')';
	return os;
}

ostream & operator<<(ostream & os, double* d)
{
	for (int i = 0; i < 5; i++)
	{
		os << d[i] << ' ';
	}
	return os;
}


