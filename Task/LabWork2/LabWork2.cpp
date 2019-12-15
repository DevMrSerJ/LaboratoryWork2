#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <math.h>

using namespace std;

void InputOneArray(int* arrA, int length)
{
	cout << "Введите элементы массива: " << endl;

	for (int i = 0; i < length; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> arrA[i];
	}
}

void InputTwoArray(int** arrA, int length1, int length2)
{
	cout << "Введите элементы массива: " << endl;

	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			cout << "a[" << i + 1 << "][" << j + 1 << "] = ";
			cin >> arrA[i][j];
		}
		cout << endl;
	}
}

void OutputTwoArray(int** arrA, int length1, int length2)
{
	for (int i = 0; i < length1; i++)
	{
		for (int j = 0; j < length2; j++)
		{
			cout << "|" << arrA[i][j] << "|\t";
		}
		cout << endl;
	}
}

void Task1()
{
	system("cls");

	cout << "\t\tЗадание №1\n\n";

	int arithMeanB = 0;
	int arithMeanA = 0;
	int number = 0;

	const int lengB = 18;
	int lengA1 = 8, lengA2 = 6;

	int **arrA = new int*[lengA1];
	for (int i = 0; i < lengA1; i++)
		arrA[i] = new int[lengA2];
	int arrB[lengB];

	InputOneArray(arrB, lengB);
	InputTwoArray(arrA, lengA1, lengA2);

	for (int i = 0; i < lengB; i++)
	{
		arithMeanB += arrB[i];
	}
	arithMeanB /= lengB;

	for (int i = 0; i < lengA1; i++)
	{
		for (int j = 0; j < lengA2; j++)
		{
			arithMeanA += arrA[i][j];
		}

		if (arithMeanA / lengA2 > arithMeanB)
			number++;
	}

	cout << "Количество строк в матрице А, среднее арифм. которых больше среднего арифм. массива В: " << number << endl;

	for (int i = 0; i < lengA1; i++) {
		delete[] arrA[i];
	}

	cout << "\nНажмите любую клавишу...";
	getchar();
	getchar();
}

void Task2()
{
	system("cls");

	cout << "\t\tЗадание №2\n\n";

	int numPermA = 0, numPermB = 0;
	int numNegTwo = 0, numNegThree = 0;

	int lengA1 = 2, lengA2 = 3;
	int lengB1 = 3, lengB2 = 3;

	int masA[3];

	int **arrA = new int*[lengA1];
	for (int i = 0; i < lengA1; i++)
		arrA[i] = new int[lengA2];

	int **arrB = new int*[lengB1];
	for (int i = 0; i < lengB1; i++)
		arrB[i] = new int[lengB2];

	InputTwoArray(arrA, lengA1, lengA2);
	InputTwoArray(arrB, lengB1, lengB2);

	int **arrACopy = new int*[lengA1];
	for (int i = 0; i < lengA1; i++)
		arrACopy[i] = new int[lengA2];

	int **arrBCopy = new int*[lengB1];
	for (int i = 0; i < lengB1; i++)
		arrBCopy[i] = new int[lengB2];

	// Формируем новый первый массив

	int k = 0;

	for (int i = 0; i < lengA2; i++)
	{
		numNegTwo = 0;

		for (int j = 0; j < lengA1; j++)
		{
			if (arrA[j][i] < 0)
				numNegTwo++;
		}

		if (numNegTwo < 2)
		{
			for (int j = 0; j < lengA1; j++)
			{
				arrACopy[j][i-k] = arrA[j][i];
			}
		}
		else
			k++;
	}

	lengA2 -= k;

	// Формируем новый второй массив

	k = 0;

	for (int i = 0; i < lengB2; i++)
	{
		numNegThree = 0;

		for (int j = 0; j < lengB1; j++)
		{
			if (arrB[j][i] < 0)
				numNegThree++;
		}

		if (numNegThree < 3)
		{
			for (int j = 0; j < lengB1; j++)
			{
				arrBCopy[j][i - k] = arrB[j][i];
			}
		}
		else
			k++;
	}

	lengB2 -= k;

	cout << "\n\n\tМассив А после удаление столбцов:" << endl;
	OutputTwoArray(arrACopy, lengA1, lengA2);
	cout << "\n\tМассив В после удаление столбцов:" << endl;
	OutputTwoArray(arrBCopy, lengB1, lengB2);
	
	cout << "\nНажмите любую клавишу...";
	getchar();
	getchar();
}

double Integral(string function, int a, int b)
{
	int n = 30;

	float dx = (double) (b - a) / n, sum = 0;

	if (function == "2x(x^2+1)")
	{
		for (int i = 1; i < n + 1; i++)
		{
			double x = a + i * dx;

			sum += 2 * x * (x * x + 1);
		}
	}

	if (function == "ln(x^2+1)")
	{
		for (int i = 1; i < n + 1; i++)
		{
			double x = a + i * dx;

			sum += log(x * x + 1);
		}
	}

	return (dx * sum);
}

void Task3()
{
	system("cls");

	cout << "\t\tЗадание №3\n\n";

	cout << "Интеграл от 2x(x^2+1) на [-1, 4] : " << Integral("2x(x^2+1)", -1, 4) << endl;
	cout << "Интеграл от ln(x^2+1) на [1, 4] : " << Integral("ln(x^2+1)", 1, 4) << endl;

	cout << "\nНажмите любую клавишу...";
	getchar();
	getchar();
}

int main()
{
	// Установка кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	while (true)
	{
		system("cls");
		cout << "Меню: " << endl;
		cout << "1 - работа с матрицами А(8х6) и В(18)" << endl;
		cout << "2 - работа с матрицами А(5х7) и В(7х7)" << endl;
		cout << "3 - вычислить интегралы с помощью метода прямоугольников" << endl;
		cout << "0 - выход из программы" << endl;
		cout << "Введите номер задания: ";
		int numLesson;
		cin >> numLesson;

		switch (numLesson)
		{
		case 1:
			Task1();
			break;
		case 2:
			Task2();
			break;
		case 3:
			Task3();
			break;
		case 0:
			exit(3);
			break;
		default:
			cout << "Такого пункта не существует! нажмите любую клавишу...";
			getchar();
			getchar();
			break;
		}
	}
	system("PAUSE");
}