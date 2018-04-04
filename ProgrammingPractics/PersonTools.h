#pragma once
#include "Person.h"

//ostream& operator << (ostream& os, Person* person);
//istream& operator >> (istream& is, Person* person);

Person* ReadPerson();
void ShowPerson(Person* person);
Person* GetRandomPerson();
bool CheckChar(char* name);