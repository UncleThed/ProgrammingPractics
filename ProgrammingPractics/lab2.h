#pragma once

void LaunchTask2();

int isCorrected();
int isNumber();

void PrintHelloWorld();

double MakeCalculation(int value1, int value2, char operationKey);

int Divide(int dividend, int divisor);

int GetRoots(int a, int b, int c, double* x1, double* x2);
int GetRoots(int a, int b, int c, double& x1, double& x2);

void SummNumbers(int a, int b);
void SummNumbers(double a, double b);
void SummNumbers(int a, double b);

void GlobalPlusTwo();
void GlobalMultiplyThree();
void GlobalEqualsOne();

double GetPower(int base, int power);

void PlayGuessNumber();

void InsertionSort1(int integerArray[5]);
void InsertionSort2(int integerArray[], int arraySize);
void InsertionSort3(int* arrayPointer, int arraySize);

void MultiplyMatrices(int** matrixA, int rowsA, int columnsA, int** matrixB, int rowsB, int columnsB, int** matrixResult);

