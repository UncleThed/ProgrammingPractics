#include "stdafx.h"
#include "lab3.h"

using namespace std;

Person ReadPerson()
{
	Person person;

	cout << "Введите имя: ";
	gets_s(person.Name);
	cout << "Введите фамилию: ";
	gets_s(person.Surname);
	cout << "Выберите пол:";
	cout << "\n1 - Male";
	cout << "\n2 - Famale" << endl;

	int key;
	do
	{
		cout << "Выберите пол:";
		cout << "\n0 - Famale";
		cout << "\n1 - Male" << endl;

		key = _getch();
		key -= 48;
	} while (key != 0 && key != 1);

	person.Sex = (Sex)key;
	
	return person;
}

void PrintPerson(Person person)
{
	cout << "Имя: " << person.Name << endl;
	cout << "Фамилию: " << person.Surname << endl;
	cout << "Пол: " << person.Sex << endl;
}

void PrintString(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		cout << string[i];
	}
	cout << endl;
}

int FindSubstring(char* string, char* substring)
{
	int j = 0;
	for (int i = 0; string[i]; i++)
	{
		if (string[i] == substring[j])
		{
			while (string[++i] == substring[++j])
			{
				if (!substring[j + 1])
				{
					return i - j;
				}
			}
			i -= j;
			j = 0;
		}
	}
	return -1;
}

void SplitFilename(char* source, char* path, char* name, char* extension)
{
	int startName = 0;
	int startExtension = -1;

	for (int i = 0; source[i]; i++)
	{
		if (source[i] == '\\')
		{
			startName = i + 1;
		}
		else if (source[i] == '.')
		{
			startExtension = i;
		}
	}

	if (startExtension > startName)
	{
		if (!startName)
		{
			*path = '\0';
		}
		else
		{
			CopyString(path, GetSubstring(source, 0, startName));
		}
		CopyString(name, GetSubstring(source, startName, startExtension - startName));
		CopyString(extension, GetSubstring(source, startExtension, GetLength(source) - startExtension));
	}
	else if (startExtension == -1)
	{
		if (!startName)
		{
			*path = '\0';
		}
		else
		{
			CopyString(path, GetSubstring(source, 0, startName));
		}
		CopyString(name, GetSubstring(source, startName, GetLength(source) - startName));

		*extension = '\0';
	}
	else
	{
		*path = '\0';
		*name = '\0';
		*extension = '\0';
	}
}

char* ReplaceTabsOnSpaces(char* string)
{
	char* resultString = new char[100];
	int i = 0;
	int j = 0;

	for (; string[i]; i++)
	{
		if (string[i] == '\t')
		{
			for (; (i + j + 1) % 8 != 0; j++)
			{
				resultString[i + j] = ':';
			}
			resultString[i + j] = ':';
		}
		else
		{
			resultString[i + j] = string[i];
		}
	}
	resultString[i + j] = '\0';
	return resultString;
}

char* ReplaceSpacesOnTabs(char* string)
{
	char* resultString = new char[50];
	int tab = 8;
	int i = 0;
	int j = 0;

	for (; string[i + j]; i++)
	{
		if (string[i + j] == ':' && isNeedTab(string, i + j + 1, tab))
		{
			while ((i + j + 1) % 8 != 0)
			{
				j++;
			}
			resultString[i] = '\t';
		}
		else
		{
			resultString[i] = string[i + j];
		}
	}
	resultString[i] = '\0';
	return resultString;
}

bool isNeedTab(char* string, int i, int tab)
{
	while (i % tab != 0)
	{
		if (string[i] != ':')
		{
			return false;
		}
		i++;
	}
	return true;
}

void LaunchTask3()
{
	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	while (AsciiValue != 27)
	{
		system("cls");

		cout << "Введите значение для запуска соответствующего задания";
		cout << "\n 1: Размер строки";
		cout << "\n 2: Объединение строк";
		cout << "\n 3: Создание подстроки";
		cout << "\n 4: Поиск подстроки";
		cout << "\n 5: Изменение регистра";
		cout << "\n 6: Разбиение имени файла";
		cout << "\n 7: Замена символов табуляции на пробелы";
		cout << "\n 8: Замена пробелов на символы табуляции";
		cout << "\n 9: Структура Person";
		cout << "\nДля завершения работы программы нажмите Esc";
		cout << "\n__________________________________________" << endl;

		key = _getch();
		AsciiValue = key;

		switch (AsciiValue)
		{
		case '1':
		{
			cout << "Длина строки\n";

			char str[50];
			cout << "\nВведите строку: ";
			gets_s(str);

			cout << "\nДлина строки: " << GetLength(str) << endl;
			system("pause");
			break;
		}
		case '2':
		{
			cout << "Объединение строк\n";

			char str1[50];
			char str2[50];
			cout << "\nВведите первую строку: ";
			gets_s(str1);
			cout << "\nВведите вторую строку: ";
			gets_s(str2);

			cout << "\nОбъединенная строка: " << Concatenate(str1, str2) << endl;
			system("pause");
			break;
		}
		case '3':
		{
			cout << "Создание подстроки\n";

			cout << "\nВведите исходную строку: ";
			char str[50];
			gets_s(str);
			cout << "Введите индекс первого элемента подстроки: ";
			int startIndex = EnterInteger();
			cout << "Введите длину подстроки: ";
			int charCount = EnterInteger();

			char* substr = GetSubstring(str, startIndex, charCount);

			if (substr)
			{
				cout << "\nПодстрока: ";
				PrintString(substr);
			}
			else
			{
				cout << "\nПодстрока: NULL" << endl;
			}
			delete[] substr;
			system("pause");
			break;
		}
		case '4':
		{
			cout << "Поиск подстроки\n";

			cout << "\nВведите исходную строку: ";
			char str[50];
			gets_s(str);
			cout << "\nВведите подстроку: ";
			char substr[50];
			gets_s(substr);
			
			int startIndex = FindSubstring(str, substr);
			if (startIndex >= 0)
			{
				cout << "Индекс первого вхождения подстроки: " << startIndex << endl;
			}
			else
			{
				cout << "Вхождение подстроки не найдено" << endl;
			}

			system("pause");
			break;
		}
		case '5':
		{
			cout << "Изменение регистра\n";

			cout << "\nВведите исходную строку: ";
			char str[50];
			gets_s(str);

			Uppercase(str);
			cout << "\nПоднятая строка: " << str << endl;
			Lowercase(str);
			cout << "\nОпущенная строка: " << str << endl;
			
			system("pause");
			break;
		}
		case '6':
		{
			cout << "Разбиение имени файла\n";

			char str[100];
			char path[50];
			char name[20];
			char extension[10];

			cout << "Введите строку : " << gets_s(str) << endl;

			SplitFilename(str, path, name, extension);
			cout << endl << "path: " << path << endl;
			cout << endl << "name: " << name << endl;
			cout << endl << "extention: " << extension << endl;

			system("pause");
			break;
		}
		case '7':
		{
			cout << "Замена символов табуляции на пробелы\n";

			char str[] = "What\t\twe\tcan\tdo\t";
			char* resultStr;

			cout << "!\t!\t!\t!\t!\t!\t!" << endl;
			cout << str << endl;
			resultStr = ReplaceTabsOnSpaces(str);
			cout << resultStr << endl;

			delete[] resultStr;

			system("pause");
			break;
		}
		case '8':
		{
			cout << "Замена пробелов на символы табуляции\n";

			//char str[] = "What::::::we::can::::::::::::do::";
			char str[] = "Cake::::is::::a:lie!";
			char* resultStr;

			cout << "!\t!\t!\t!\t!\t!\t!" << endl;
			cout << str << endl;
			resultStr = ReplaceSpacesOnTabs(str);
			cout << resultStr << endl;

			delete[] resultStr;

			system("pause");
			break;
		}
		case '9':
		{
			cout << "Структура Person\n";

			Person Human = ReadPerson();
			PrintPerson(Human);

			system("pause");
			break;
		}
		}
	}
}