#include "stdafx.h"
#include "lab1.h"
#include "lab2.h"

#include <clocale>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	//LaunchTask1();
	LaunchTask2();
	//LaunchTask3();

	return 0;
}