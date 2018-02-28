#include "stdafx.h"
using namespace std;

//Объявление глобальной переменной
int globalVariable = 7;

//Проверка корректности ввода
int EnterNumber()
{
	char number = _getch();
	while (number > '9' || number < '0')
	{
		cout << "\nНеподходящий символ!\nВыберите цифру от 0 до 9: ";
		number = _getch();
	}
	return (int)number - 48; //перевод символа в цифру
}
int EnterInteger()
{
	int value;
	bool good = true;
	do
	{
		cin >> value;
		if (!(good = cin.good()))
		{
			cout << "Ошибка ввода!" << endl;
			cout << "Введите целочисленное значение: ";
		}
		cin.clear();
		fflush(stdin);
		while (cin.get() != '\n');
	} while (!good);

	return value;
}

void PrintHelloWorld()
{
	cout << "\nHello World!!!";
}

double MakeCalculation(int value1, int value2, char operationKey)
{	
	switch (operationKey)
	{
	case '+':
		return (value1 + value2);
		break;
	case '-':
		return (value1 - value2);
		break;
	case '*':
		return (value1 * value2);
		break;
	case '/':
		return (value1 / value2);
		break;
	case '%':
		return (value1 % value2);
		break;
	}
}

int Divide(int dividend, int divisor)
{
	int result;
	result = dividend / divisor;
	return result;
}

int GetRoots(int a, int b, int c, double* x1, double* x2)
{
	if (a == 0 && b == 0)
	{
		return 0;
	}
	else if (a == 0)
	{
		*x1 = (double)-c / b;
		return 1;
	}
	else
	{
		int d = b * b - 4 * a * c;
		if (d > 0)
		{
			*x1 = (-b + sqrt(d)) / (2 * a);
			*x2 = (-b - sqrt(d)) / (2 * a);
			return 2;
		}
		else if (d == 0)
		{
			*x1 = (double)-b / (2 * a);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}
int GetRoots(int a, int b, int c, double& x1, double& x2)
{
	if (a == 0 && b == 0)
	{
		return 0;
	}
	else if (a == 0)
	{
		x1 = (double)-c / b;
		return 1;
	}
	else
	{
		int d = b * b - 4 * a * c;
		if (d > 0)
		{
			x1 = (-b + sqrt(d)) / (2 * a);
			x2 = (-b - sqrt(d)) / (2 * a);
			return 2;
		}
		else if (d == 0)
		{
			x1 = (double)-b / (2 * a);
			return 1;
		}
		else
		{
			return 0;
		}
	}
}

void SummNumbers(int a, int b)
{
	cout << "Сумма двух переменных типа int: " << a + b << endl;
}
void SummNumbers(double a, double b)
{
	cout << "Сумма двух переменных типа double: " << a + b << endl;
}
void SummNumbers(int a, double b)
{
	cout << "Сумма двух переменных типа int и double: " << a + b << endl;
}

void GlobalPlusTwo()
{
	globalVariable += 2;
}
void GlobalMultiplyThree()
{
	globalVariable *= 3;
}
void GlobalEqualsOne()
{
	globalVariable = 1;
}

double GetPower(int base, int power)
{
	if (power == 0)
	{
		return 1;
	}
	else if (power > 0)
	{
		return GetPower(base, power - 1) * base;
	}
	else
	{
		return GetPower(base, power + 1) / base;
	}
}

void PlayGuessNumber()
{
	int guessNumber = rand() % 10;
	cout << "Выберите цифру от 0 до 9: ";
	int enteredNumber = EnterNumber();
	cout << enteredNumber;
	int shots = 1;
	while (enteredNumber != guessNumber)
	{
		shots++;
		cout << "\nНеверно! Попробуйте снова\nВыберите цифру от 0 до 9: ";
		enteredNumber = EnterNumber();
		cout << enteredNumber;
	}
	cout << "\nВерно!!! Вы затратили " << shots << " попыток" << endl;
}

void InsertionSort1(int integerArray[5])
{
	for (int i = 1; i < 5; i++)
		for (int j = i; j > 0 && integerArray[j - 1] > integerArray[j]; j--)
			swap(integerArray[j - 1], integerArray[j]);
}
void InsertionSort2(int integerArray[], int arraySize)
{
	for (int i = 1; i < arraySize; i++)
		for (int j = i; j > 0 && integerArray[j - 1] > integerArray[j]; j--)
			swap(integerArray[j - 1], integerArray[j]);
}
void InsertionSort3(int* arrayPointer, int arraySize)
{
	for (int i = 1; i < arraySize; i++)
		for (int j = i; j > 0 && arrayPointer[j - 1] > arrayPointer[j]; j--)
		{
			swap(arrayPointer[j - 1], arrayPointer[j]);
		}
}

void MultiplyMatrices(int** matrixA, int rowsA, int columnsA, int** matrixB, int rowsB, int columnsB, int** matrixResult)
{
	for (int i = 0; i < rowsA; i++)
	{
		for (int j = 0; j < columnsB; j++)
		{
			matrixResult[i][j] = 0;
			for (int k = 0; k < columnsA; k++)
			{
				matrixResult[i][j] += (matrixA[i][k] * matrixB[k][j]);
			}
		}
	}
}

void PrintMatrix(int** matrix, int columns, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout.width(8);
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

//-----------------------------------------------------------------
//Лаунчер лабораторной работы
void LaunchTask2()
{
	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	while (AsciiValue != 27)
	{
		system("cls");

		cout << "Введите значение для запуска соответствующего задания";
		cout << "\n 1: Вывод Hello World!";
		cout << "\n 2: Калькулятор";
		cout << "\n 3: Целочисленное деление";
		cout << "\n 4: Решение квадратного уравнения (передача указателя)";
		cout << "\n 5: Решение квадратного уравнения (передача ссылки)";
		cout << "\n 6: Перегрузка функций";
		cout << "\n 7: Работа с глобальной переменной";
		cout << "\n 8: Возведение в степень (рекурсивно)";
		cout << "\n 9: Игра \"Угадай число\"";
		cout << "\n 0: Сортировка массива (три способа передачи массива)";
		cout << "\n -: Умножение матриц";
		cout << "\nДля завершения работы программы нажмите Esc";
		cout << "\n__________________________________________" << endl;

		key = _getch();
		AsciiValue = key;

		switch (AsciiValue)
		{
		case '1':
			cout << "Вывод Hello World!\n";
			PrintHelloWorld();
			cout << endl;
			system("pause");
			break;
		case '2':
		{
			cout << "Калькулятор\n";

			cout << "\nВведите первое число: ";
			int value1;
			value1 = EnterInteger();

			cout << "Введите второе число: ";
			int value2;
			value2 = EnterInteger();

			cout << "Enter mathematic operation (+, -, *, /, %)";
			char key;
			key = _getch();
			while ((key != '+') && (key != '-') && (key != '*') && (key != '/') && (key != '%'))
			{
				cout << "\nINCORRECT SYMBOL!!!\nPlease, enter(+, -, *, /, %):";
				key = _getch();
			}

			cout << endl << value1 << " " << key << " " << value2 << " = " << MakeCalculation(value1, value2, key) << endl;
			system("pause");
			break;
		}
		case '3':
		{
			cout << "Целочисленное деление\n";

			cout << "\nВведите первое число: ";
			int dividend = EnterInteger();

			cout << "Введите второе число: ";
			int divisor = EnterInteger();

			int result = Divide(dividend, divisor);
			cout << endl << dividend << " / " << divisor << " = " << result << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << "Решение квадратного уравнения (передача указателя)\n";

			cout << "\nЗадайте целочисленные параметры квадратного уравнения\n";
			cout << "Введите значение a: ";
			int a = EnterInteger();
			cout << "Введите значение b: ";
			int b = EnterInteger();
			cout << "Введите значение c: ";
			int c = EnterInteger();
			double x1, x2;			// корни уравнения
			double* x1Pointer = &x1;
			double* x2Pointer = &x2;

			int countRoots = GetRoots(a, b, c, x1Pointer, x2Pointer);

			switch (countRoots)
			{
			case 0:
				cout << "Корней нет" << endl;
				break;
			case 1:
				cout << "Уравнене имеет один корень: x = " << x1 << endl;
				break;
			case 2:
				cout << "Уравнене имеет два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
				break;
			}
			system("pause");
			break;
		}
		case '5':
		{
			cout << "Решение квадратного уравнения (передача ссылки)\n";

			cout << "\nЗадайте целочисленные параметры квадратного уравнения\n";
			cout << "Введите значение a: ";
			int a = EnterInteger();
			cout << "Введите значение b: ";
			int b = EnterInteger();
			cout << "Введите значение c: ";
			int c = EnterInteger();
			double x1, x2;			// корни уравнения

			int countRoots = GetRoots(a, b, c, x1, x2);

			switch (countRoots)
			{
			case 0:
				cout << "Корней нет" << endl;
				break;
			case 1:
				cout << "Уравнене имеет один корень: x = " << x1 << endl;
				break;
			case 2:
				cout << "Уравнене имеет два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
				break;
			}
			system("pause");
			break;
		}
		case '6':
		{
			cout << "Перегрузка функций\n\n";

			int a = 1;
			int b = 2;
			SummNumbers(a, b);
			double x = 3.0;
			double y = 4.0;
			SummNumbers(x, y);
			float m = 5.0;
			float n = 6.0;
			SummNumbers(m, n);
			system("pause");
			break;
		}
		case '7':
			cout << "Работа с глобальной переменной\n";

			cout << "\nЗначение глобальной переменной: " << globalVariable << endl;
			GlobalPlusTwo();
			cout << "Значение глобальной переменной: " << globalVariable << endl;
			GlobalMultiplyThree();
			cout << "Значение глобальной переменной: " << globalVariable << endl;
			GlobalEqualsOne();
			cout << "Значение глобальной переменной: " << globalVariable << endl;
			globalVariable = 5;
			cout << "Значение глобальной переменной: " << globalVariable << endl;
			system("pause");
			break;
		case '8':
		{
			cout << "Возведение в степень (рекурсивно)\n";

			cout << "\nВведите основание степени: ";
			int base = EnterInteger();
			cout << "Введите показатель степени: ";
			int power = EnterInteger();

			cout << base << " в степени " << power << " = " << GetPower(base, power) << endl;
			system("pause");
			break;
		}
		case '9':
			cout << "Игра \"Угадай число\"\n\n";

			PlayGuessNumber();
			system("pause");
			break;
		case '0':
		{
			cout << "Сортировка массива (три способа передачи массива)\n";

			const int arraySize = 5;
			int integerArray[arraySize];
			cout << "\nМассив до сортировки:\n";
			for (int i = 0; i < arraySize; i++)
			{
				integerArray[i] = rand() % 100;
				cout << integerArray[i] << " ";
			}
			/*InsertionSort1(integerArray);*/
			InsertionSort2(integerArray, arraySize);
			//InsertionSort3(integerArray, arraySize);
			cout << "\nМассив после сортировки:\n";
			for (int i = 0; i < arraySize; i++)
			{
				cout << integerArray[i] << " ";
			}
			cout << endl;
			system("pause");
			break;
		}
		case '-':
		{
			cout << "Умножение матриц\n";

			cout << "\nВведите количество строк первой матрицы: ";
			int rowsA = EnterInteger();
			cout << "Введите количество столбцов первой матрицы: ";
			int columnsA = EnterInteger();
			cout << "\nВведите количество строк второй матрицы: ";
			int rowsB = EnterInteger();
			cout << "Введите количество столбцов второй матрицы: ";
			int columnsB = EnterInteger();

			if (columnsA == rowsB)
			{
				int rowsResult = rowsA;
				int columnsResult = columnsB;

				int** matrixA = new int*[rowsA];
				for (int i = 0; i < rowsA; i++)
					matrixA[i] = new int[columnsA];

				int** matrixB = new int*[rowsB];
				for (int i = 0; i < rowsB; i++)
					matrixB[i] = new int[columnsB];

				int** matrixResult = new int*[rowsResult];
				for (int i = 0; i < rowsResult; i++)
					matrixResult[i] = new int[columnsResult];

				//--------------------------------------------------

				for (int i = 0; i < rowsA; i++)
					for (int j = 0; j < columnsA; j++)
						matrixA[i][j] = rand() % 100;

				for (int i = 0; i < rowsB; i++)
					for (int j = 0; j < columnsB; j++)
						matrixB[i][j] = rand() % 100;

				MultiplyMatrices(matrixA, rowsA, columnsA, matrixB, rowsB, columnsB, matrixResult);

				cout << "Первая матрица:" << endl;
				PrintMatrix(matrixA, columnsA, rowsA);
				cout << "\n____________________________" << endl;
				cout << "Вторая матрица:" << endl;
				PrintMatrix(matrixB, columnsB, rowsB);
				cout << "\n____________________________" << endl;
				cout << "Результат:" << endl;
				PrintMatrix(matrixResult, columnsResult, rowsResult);

				for (int i = 0; i < rowsA; i++)
					delete[] matrixA[i];
				for (int i = 0; i < rowsB; i++)
					delete[] matrixB[i];
				for (int i = 0; i < rowsResult; i++)
					delete[] matrixResult[i];
				delete[] matrixA, matrixB, matrixResult;

				cout << "\n______________________________________________________" << endl;
			}
			else
				cout << "\nКоличество столбцов матрицы A должно быть равно количеству строк матрицы B" << endl;
			system("pause");
			break;
		}
		}
	}
}