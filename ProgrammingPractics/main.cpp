#include "stdafx.h"
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"

#include <clocale>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	//LaunchTask1();
	//LaunchTask2();
	//LaunchTask3();
	//LaunchTask4();
	LaunchTask5();
	//LaunchTask6();

	return 0;
}