#include "stdafx.h"
using namespace std;

//объявление глобальной переменной
int globalVariable = 7;

int isNumber()
{
	char number = _getch();
	while (number > '9' || number < '0')
	{
		cout << "\nНеподходящий символ!\nВыберите цифру от 0 до 9: ";
		number = _getch();
	}
	return (int)number - 48; //перевод символа в цифру
}
int isCorrected()
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
	int d = b * b - 4 * a * c;
	if (d > 0)
	{
		*x1 = (-b + sqrt(d)) / (2 * a);
		*x2 = (-b - sqrt(d)) / (2 * a);
		return 2;
	}
	else if (d == 0)
	{
		*x1 = -b / (2 * a);
		return 1;
	}
	else
	{
		return 0;
	}
}
int GetRoots(int a, int b, int c, double& x1, double& x2)
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
		x1 = -b / (2 * a);
		return 1;
	}
	else
	{
		return 0;
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
	int enteredNumber = isNumber();
	cout << enteredNumber;
	int shots = 0;
	while (enteredNumber != guessNumber)
	{
		shots++;
		cout << "\nНеверно! Попробуйте снова\nВыберите цифру от 0 до 9: ";
		enteredNumber = isNumber();
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

void PrintMatrics(int** matrics, int cols, int rows)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << matrics[i][j] << ' ';
		}
		cout << endl;
	}
}

void LaunchTask2()
{
	char key;						//введенный с клавиатуры символ
	int AsciiValue = 0;				//его аски код

	while (AsciiValue != 27)
	{
		system("cls");

		cout << "Введите значение с клавиатуры соответствующее";
		cout << "\n - числу от 1 до 9";
		cout << "\n - символам a, b";
		cout << "\nДля завершения работы программы нажмите Esc";
		cout << "\n__________________________________________\n";

		key = _getch();
		AsciiValue = key;

		switch (AsciiValue)
		{
		case '1':
			PrintHelloWorld();
			cout << endl;
			system("pause");
			break;
		case '2':
		{
			cout << "Введите первое число: ";
			int value1;
			value1 = isCorrected();

			cout << "Введите второе число: ";
			int value2;
			value2 = isCorrected();

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
			cout << "Введите первое число: ";
			int dividend = isCorrected();

			cout << "Введите второе число: ";
			int divisor = isCorrected();

			int result = Divide(dividend, divisor);
			cout << endl << dividend << " / " << divisor << " = " << result << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << "Задайте целочисленные параметры квадратного уравнения\n";
			cout << "Введите значение a: ";
			int a = isCorrected();
			cout << "Введите значение b: ";
			int b = isCorrected();
			cout << "Введите значение c: ";
			int c = isCorrected();
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
			cout << "Задайте целочисленные параметры квадратного уравнения\n";
			cout << "Введите значение a: ";
			int a = isCorrected();
			cout << "Введите значение b: ";
			int b = isCorrected();
			cout << "Введите значение c: ";
			int c = isCorrected();
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
			cout << "Значение глобальной переменной: " << globalVariable << endl;
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
			cout << "Введите основание степени: ";
			int base = isCorrected();
			cout << "Введите показатель степени: ";
			int power = isCorrected();

			cout << base << " в степени " << power << " = " << GetPower(base, power) << endl;
			system("pause");
			break;
		}
		case '9':
			PlayGuessNumber();
			system("pause");
			break;
		case '0':
		{
			const int arraySize = 5;
			int integerArray[arraySize];
			int* arrayPointer = integerArray;
			cout << "Массив до сортировки:\n";
			for (int i = 0; i < arraySize; i++)
			{
				integerArray[i] = rand() % 100;
				cout << integerArray[i] << " ";
			}
			/*InsertionSort1(integerArray);*/
			//InsertionSort2(integerArray, arraySize);
			InsertionSort3(arrayPointer, arraySize);
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
			cout << "Введите количество строк первого массива: ";
			int rowsA = isCorrected();
			cout << "Введите количество столбцов первого массива: ";
			int columnsA = isCorrected();
			cout << "Введите количество строк второго массива: ";
			int rowsB = isCorrected();
			cout << "Введите количество столбцов второго массива: ";
			int columnsB = isCorrected();

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
					matrixA[i][j] = rand() % 10;

			for (int i = 0; i < rowsB; i++)
				for (int j = 0; j < columnsB; j++)
					matrixB[i][j] = rand() % 10;

			MultiplyMatrices(matrixA, rowsA, columnsA, matrixB, rowsB, columnsB, matrixResult);

			cout << "First matrics:" << endl;
			PrintMatrics(matrixA, columnsA, rowsA);
			cout << endl << "____________________________" << endl;
			cout << "Second matrics:" << endl;
			PrintMatrics(matrixB, columnsB, rowsB);
			cout << endl << "____________________________" << endl;
			cout << "Result matrics:" << endl;
			PrintMatrics(matrixResult, columnsResult, rowsResult);

			for (int i = 0; i < rowsA; i++)
				delete[] matrixA[i];
			for (int i = 0; i < rowsB; i++)
				delete[] matrixB[i];
			for (int i = 0; i < rowsResult; i++)
				delete[] matrixResult[i];
			delete[] matrixA, matrixB, matrixResult;

			cout << endl << endl << "______________________________________________________" << endl;
			cout << "---the program is complete---" << endl;
			system("pause");
		}
		}


	}
}