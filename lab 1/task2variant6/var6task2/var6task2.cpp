// var6task2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;
uint8_t FlipByte(uint8_t InNumber);
bool ValidationData(const char * str, int & InputNumber);

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program shows difference in the order of the binary bits in the given number, please enter number at command line.\n");
		return 0;
	}

	int InputNumber = 0;
	bool err = ValidationData(argv[1], InputNumber);
	if (err)
		return 1;

	static_cast<uint8_t>(InputNumber);
	InputNumber = FlipByte(InputNumber);
	static_cast<int>(InputNumber);
	cout << InputNumber;
	
    return 0;
}

bool ValidationData(const char * str, int & InputNumber)
{
	try
	{
		InputNumber = stoi(str);
		assert(true);
	}
	catch (const std::invalid_argument)
	{
		cout << "Argument \"" << str << " is not a number.\n";
		return true;
	}

	if (InputNumber >= 0 && InputNumber <= 255)
		return false;
	else
	{
		cout << "Argumnet is not included in the valid range from 0 to 255.\n";
		return true;
	}
}

uint8_t FlipByte(uint8_t InNumber)
{
	uint8_t buf;
	uint8_t OutNumber = 0;
	uint8_t multiplier = 1 << (8 - 1);
	for (int i = 0; i <= 7; ++i)
	{
		buf = InNumber & multiplier;
		InNumber <<= 1;
		OutNumber >>= 1;
		OutNumber |= buf;
	}
	return OutNumber;
}