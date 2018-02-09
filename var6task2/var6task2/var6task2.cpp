// var6task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
unsigned short int StringToInt(const char * str, bool & err);

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program shows difference in the order of the binary bits in the given number, please enter number at command line.\n");
		return 0;
	}

	bool err;
	unsigned short int  number = StringToInt(argv[1], err);
	unsigned short int elem[8];
	unsigned short int counter = 7;
	if (err)
	{
		cout << "Argumnet \"" << argv[1] << "\" is not a number.\n";
		return 1;
	}

	if (number < 0 || number > 255)
	{
		cout << "Argumnet is not included in the valid range from 0 to 255.\n";
		return 1;
	}

	uint8_t multiplier = 1 << (8 - 1);

	for (int i = 0; i <= 7; ++i)
	{
		elem[i] = number << i;
		elem[i] &= multiplier;
		elem[i] >>= counter;
		--counter;
	}

	number = 0;
	for (int i = 0; i <= 7; ++i)
	{
		number |= elem[i];
	}

	cout << number;
    return 0;
}

unsigned short int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	unsigned short number = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return number;
}
