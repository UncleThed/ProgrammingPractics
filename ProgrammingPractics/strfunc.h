#pragma once

void CopyString(char* string1, char* string2);
void CopyConstString(char* string1, const char* string2);

int GetLength(char* string);
int GetLength(const char* string);

char* Concatenate(char* str1, char* str2);
char* Concatenate(char* str1, const char* str2);

void Lowercase(char* string);
void Uppercase(char* string);

char* GetSubstring(char* string, int startIndex, int charCount);