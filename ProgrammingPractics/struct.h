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