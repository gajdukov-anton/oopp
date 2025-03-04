// task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

int SumDigits(int i);

int main(int argc, char* argv[])
{
	for (int i = 1; i <= 1000; i++) {
		int sum = 0;
		sum = SumDigits(i);
		
		if (i % sum == 0)
		{
			printf("%d", i);
			if (i < 1000)
				printf(", ");
		}
	}
    return 0;
}

int SumDigits(int i)
{
	int sum = 0;

	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}

	return sum;
}