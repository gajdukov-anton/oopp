// task3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <cassert>
#include <sstream>

using namespace std;

bool ValidationData(const char * str, int & InputNumber);

int main(int argc, char* argv[])
{
	if (argc <= 1)
	{
		printf("Program displays Fibonacci number, please enter argument at command line.\n");
		return 0;
	}

	int limitNumber;
	bool err = ValidationData(argv[1], limitNumber);
	if (err)
		return 1;
	int numberOne = 1;
	int numberTwo = 1;
	int buf;
	int counter = 0;
	bool stop = false;
	cout << numberOne << ", ";
	while (numberTwo <= limitNumber && !stop)
	{
		++counter;
		cout << numberTwo << ", "; 
		buf = numberTwo;
		if (numberTwo + numberOne >= 0)
			numberTwo += numberOne;
		else
			stop = true;
		numberOne = buf;
		if (counter == 5)
		{
			cout << endl;
			counter = 0;
		}
	}
    return 0;
}

bool ValidationData(const char * str, int & InputNumber)
{
	try
	{
		InputNumber = stoi(str);
		assert(true);
	}
	catch (const std::invalid_argument & err)
	{
		cout << "Argument \"" << str << " is not a number.\n";
		return true;
	}
	catch (const std::out_of_range & err)
	{
		cout << "It is overlow.\n";
		return true;
	}

	if (InputNumber <= 0)
	{
		cout << "Your number is smaller or equal to zero, please enter number in the range from 1 to 2 147 483 647.\n";
		return true;
	}

	return false;
}