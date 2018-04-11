#include "stdafx.h"

void CopyString(char* string1, char* string2)
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

void CopyConstString(char* string1, const char* string2)
{
	int i = 0;
	for (; string2[i]; i++)
	{
		string1[i] = string2[i];
	}
	string1[i] = '\0';
}

int GetLength(char* string)
{
	int i = 0;
	for (; string[i]; i++);
	return i;
}

int GetLength(const char* string)
{
	int i = 0;
	for (; string[i]; i++);
	return i;
}

char* Concatenate(char* str1, char* str2)
{
	int start = GetLength(str1);
	for (int i = 0; str2[i]; i++)
	{
		str1[start + i] = str2[i];
	}
	str1[start + GetLength(str2)] = '\0';
	return str1;
}

char* Concatenate(char* str1, const char* str2)
{
	int start = GetLength(str1);
	for (int i = 0; str2[i]; i++)
	{
		str1[start + i] = str2[i];
	}
	str1[start + GetLength(str2)] = '\0';
	return str1;
}

void Lowercase(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		if ((string[i] > 64) && (string[i] < 91))
		{
			string[i] += 32;
		}
	}
}

void Uppercase(char* string)
{
	for (int i = 0; string[i]; i++)
	{
		if ((string[i] > 96) && (string[i] < 123))
		{
			string[i] -= 32;
		}
	}
}

char* GetSubstring(char* string, int startIndex, int charCount)
{
	if (startIndex < 0 || charCount < 1 || startIndex + charCount > GetLength(string))
	{
		return NULL;
	}

	char* substr = new char[charCount + 1];

	for (int i = 0; i < charCount; i++)
	{
		substr[i] = string[startIndex + i];
	}
	substr[charCount] = '\0';
	return substr;
}