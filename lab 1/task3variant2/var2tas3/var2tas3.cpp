// var2tas3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

float FindMatrixDeterminat(float mat[3][3]);
float FindMatrixAddition(float mat[3][3], int ElemX, int ElemY);

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("You need enter argument for correct work.\n");
		return 0;
	}

	ifstream input_file(argv[1]);

	if (!input_file.is_open())
	{
		cout << "File is not find, please check your data and repeat again.\n";
		return 1;
	}

	float Matrix[3][3];
	float MatrixAddition[3][3];
	float InverseMatrix[3][3];
	float determinat;
	char buf;
	float elem;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			input_file >> Matrix[i][j];
		}

	}

	determinat = FindMatrixDeterminat(Matrix);
	if (determinat == 0)
	{
		cout << "Determinat is less then zero. Inverse Matrix is not available. \n";
		return 0;
	}

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			MatrixAddition[i][j] = FindMatrixAddition(Matrix, j , i);
	}
	
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			InverseMatrix[i][j] = MatrixAddition[j][i] / determinat;
			printf("%.3f", InverseMatrix[i][j]);
			cout << ' ';
		}
		cout << endl;
	}

	input_file.close();
    return 0;
}

float FindMatrixDeterminat(float mat[3][3])
{
	float result = 0, paramOne, paramTwo;
	paramOne = mat[0][0] * mat[1][1] * mat[2][2] + mat[0][1] * mat[1][2] * mat[2][0] + mat[0][2] * mat[1][0] * mat[2][1];
	paramTwo = mat[0][2] * mat[1][1] * mat[2][0] + mat[0][1] * mat[1][0] * mat[2][2] + mat[0][0] * mat[1][2] * mat[2][1];
	result = paramOne - paramTwo;
	return result;
}

float FindMatrixAddition(float mat[3][3], int ElemX, int ElemY)
{
	float AddMat[2][2], result = 0;
	int CounterX = 0, CounterY = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i != ElemY && j != ElemX)
			{
				AddMat[CounterY][CounterX] = mat[i][j];
				++CounterX;
			}
			if (CounterX == 2)
			{
				CounterX = 0;
				++CounterY;
			}
		}
	}
	int multiplier = 1;
	if ((ElemY + ElemX) % 2 != 0)
		multiplier = -1;
	result = multiplier * (AddMat[0][0] * AddMat[1][1] - AddMat[0][1] * AddMat[1][0]);
	return result;
}