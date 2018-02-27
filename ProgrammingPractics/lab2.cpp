#include "stdafx.h"
using namespace std;

//���������� ���������� ����������
int globalVariable = 7;

int isNumber()
{
	char number = _getch();
	while (number > '9' || number < '0')
	{
		cout << "\n������������ ������!\n�������� ����� �� 0 �� 9: ";
		number = _getch();
	}
	return (int)number - 48; //������� ������� � �����
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
			cout << "������ �����!" << endl;
			cout << "������� ������������� ��������: ";
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
	cout << "����� ���� ���������� ���� int: " << a + b << endl;
}
void SummNumbers(double a, double b)
{
	cout << "����� ���� ���������� ���� double: " << a + b << endl;
}
void SummNumbers(int a, double b)
{
	cout << "����� ���� ���������� ���� int � double: " << a + b << endl;
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
	cout << "�������� ����� �� 0 �� 9: ";
	int enteredNumber = isNumber();
	cout << enteredNumber;
	int shots = 0;
	while (enteredNumber != guessNumber)
	{
		shots++;
		cout << "\n�������! ���������� �����\n�������� ����� �� 0 �� 9: ";
		enteredNumber = isNumber();
		cout << enteredNumber;
	}
	cout << "\n�����!!! �� ��������� " << shots << " �������" << endl;
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
	char key;						//��������� � ���������� ������
	int AsciiValue = 0;				//��� ���� ���

	while (AsciiValue != 27)
	{
		system("cls");

		cout << "������� �������� � ���������� ���������������";
		cout << "\n - ����� �� 1 �� 9";
		cout << "\n - �������� a, b";
		cout << "\n��� ���������� ������ ��������� ������� Esc";
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
			cout << "������� ������ �����: ";
			int value1;
			value1 = isCorrected();

			cout << "������� ������ �����: ";
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
			cout << "������� ������ �����: ";
			int dividend = isCorrected();

			cout << "������� ������ �����: ";
			int divisor = isCorrected();

			int result = Divide(dividend, divisor);
			cout << endl << dividend << " / " << divisor << " = " << result << endl;
			system("pause");
			break;
		}
		case '4':
		{
			cout << "������� ������������� ��������� ����������� ���������\n";
			cout << "������� �������� a: ";
			int a = isCorrected();
			cout << "������� �������� b: ";
			int b = isCorrected();
			cout << "������� �������� c: ";
			int c = isCorrected();
			double x1, x2;			// ����� ���������
			double* x1Pointer = &x1;
			double* x2Pointer = &x2;

			int countRoots = GetRoots(a, b, c, x1Pointer, x2Pointer);

			switch (countRoots)
			{
			case 0:
				cout << "������ ���" << endl;
				break;
			case 1:
				cout << "�������� ����� ���� ������: x = " << x1 << endl;
				break;
			case 2:
				cout << "�������� ����� ��� �����: x1 = " << x1 << ", x2 = " << x2 << endl;
				break;
			}
			system("pause");
			break;
		}
		case '5':
		{
			cout << "������� ������������� ��������� ����������� ���������\n";
			cout << "������� �������� a: ";
			int a = isCorrected();
			cout << "������� �������� b: ";
			int b = isCorrected();
			cout << "������� �������� c: ";
			int c = isCorrected();
			double x1, x2;			// ����� ���������

			int countRoots = GetRoots(a, b, c, x1, x2);

			switch (countRoots)
			{
			case 0:
				cout << "������ ���" << endl;
				break;
			case 1:
				cout << "�������� ����� ���� ������: x = " << x1 << endl;
				break;
			case 2:
				cout << "�������� ����� ��� �����: x1 = " << x1 << ", x2 = " << x2 << endl;
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
			cout << "�������� ���������� ����������: " << globalVariable << endl;
			GlobalPlusTwo();
			cout << "�������� ���������� ����������: " << globalVariable << endl;
			GlobalMultiplyThree();
			cout << "�������� ���������� ����������: " << globalVariable << endl;
			GlobalEqualsOne();
			cout << "�������� ���������� ����������: " << globalVariable << endl;
			globalVariable = 5;
			cout << "�������� ���������� ����������: " << globalVariable << endl;
			system("pause");
			break;
		case '8':
		{
			cout << "������� ��������� �������: ";
			int base = isCorrected();
			cout << "������� ���������� �������: ";
			int power = isCorrected();

			cout << base << " � ������� " << power << " = " << GetPower(base, power) << endl;
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
			cout << "������ �� ����������:\n";
			for (int i = 0; i < arraySize; i++)
			{
				integerArray[i] = rand() % 100;
				cout << integerArray[i] << " ";
			}
			/*InsertionSort1(integerArray);*/
			//InsertionSort2(integerArray, arraySize);
			InsertionSort3(arrayPointer, arraySize);
			cout << "\n������ ����� ����������:\n";
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
			cout << "������� ���������� ����� ������� �������: ";
			int rowsA = isCorrected();
			cout << "������� ���������� �������� ������� �������: ";
			int columnsA = isCorrected();
			cout << "������� ���������� ����� ������� �������: ";
			int rowsB = isCorrected();
			cout << "������� ���������� �������� ������� �������: ";
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