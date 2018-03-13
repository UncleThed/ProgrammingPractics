#pragma once

void PrintHelloWorld();

double MakeCalculation(int value1, int value2, char operationKey);

int Divide(int dividend, int divisor);

//Решение квадратного уравнения (и не только!)
int GetRoots(int a, int b, int c, double* x1, double* x2);
int GetRoots(int a, int b, int c, double& x1, double& x2);

void SummNumbers(int a, int b);
void SummNumbers(double a, double b);
void SummNumbers(int a, double b);

//Операции с глобальной переменной
void GlobalPlusTwo();
void GlobalMultiplyThree();
void GlobalEqualsOne();

//Возведение в степень
double GetPower(int base, int power);

//Угадай число!
void PlayGuessNumber();

//Три способа передачи массива
void InsertionSort1(int integerArray[5]);
void InsertionSort2(int integerArray[], int arraySize);
void InsertionSort3(int* arrayPointer, int arraySize);

//Умножение матриц
void MultiplyMatrices(int** matrixA, int rowsA, int columnsA, int** matrixB, int rowsB, int columnsB, int** matrixResult);
void PrintMatrix(int** matrix, int columns, int rows);

//Лаунчер второй лабораторной работы
void LaunchTask2();

