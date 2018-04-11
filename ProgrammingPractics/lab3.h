#pragma once
#include "strfunc.h"

enum Sex
{
	Famale,
	Male
};

struct Person
{
	char Surname[50];
	char Name[20];
	Sex Sex;

};

Person ReadPerson();
void PrintPerson(Person person);

void PrintString(char* string);

int FindSubstring(char* string, char* substring);

void SplitFilename(char* source, char* path, char* name, char* extension);

char* ReplaceTabsOnSpaces(char* string);
char* ReplaceSpacesOnTabs(char* string);
bool isNeedTab(char* string, int i, int tab);

//Лаунчер третей лабораторной работы
void LaunchTask3();