#pragma once
#include "Person.h"
#include "Adult.h"
#include "Child.h"

template <typename T>
class List
{
private:
	class ListItem
	{
	public:
		ListItem(T* data)
		{
			_value = data;
		};

		T* GetValue()
		{
			return _value;
		};

		ListItem* Next = nullptr;
		ListItem* Prev = nullptr;

	private:
		T* _value;
	};

	ListItem* _head = nullptr;
	ListItem* _tail = nullptr;
	int _count = 0;

public:
	List() {};
	void Add(T* data);
	T* Find(int index);
	int IndexOf(T* data);
	int GetCount();

	void Remove(T* data);
	void RemoveAt(int index);

	void ShowDescriptions();
	void Show();

	void Clear();

	~List()
	{
		Clear();
	};
};