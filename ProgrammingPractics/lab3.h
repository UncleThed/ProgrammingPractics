#pragma once

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

void CopyString(char* string1, char* string2);
void PrintString(char* string);

int GetLength(char* string);
char* Concatenate(char* str1, char* str2);

char* GetSubstring(char* string, int startIndex, int charCount);
int FindSubstring(char* string, char* substring);

void Lowercase(char* string);
void Uppercase(char* string);

void SplitFilename(char* source, char* path, char* name, char* extension);

char* ReplaceTabsOnSpaces(char* string);
char* ReplaceSpacesOnTabs(char* string);
bool isNeedTab(char* string, int i, int tab);

//Лаунчер третей лабораторной работы
void LaunchTask3();