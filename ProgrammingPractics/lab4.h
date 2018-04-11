#pragma once
#include <stdlib.h>
#include "lab3.h";


struct Node
{
	Person person;// хранить указатель на персону
	Node* next = NULL;
	Node* prev = NULL;
};

struct List
{
	Node* head = NULL;
	Node* tail = NULL;
};

Person MakeRandomPerson();

void AddLast(List* list);
void Insert(List* list, Person person, int index);
Person* Get(List* list, int index);
void Remove(List* list, int index);
void Clear(List* list);
void Show(List* list);

void LaunchTask4();