#pragma once
#include "stdafx.h"
#include "Person.h"

Person* ReadPerson();
void ShowPerson(Person* person);
Person* GetRandomPerson();
Person* GetRandomPerson(Sex tempSex);
bool CheckName(char* name);