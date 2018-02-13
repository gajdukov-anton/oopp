// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus");
	if (argc <= 2)
	{
		printf("You need enter 2 arguments for correct work.\n");
		return 0;
	}

	ifstream input_file(argv[1]);

	if (!input_file.is_open())
	{
		cout << "File is not find, please check your data and repeat again.\n";
		return 1;
	}

	char symbol = ' ';
	int numberStr = 1;
	int counter;
	int pastNumberStr = 0;
	bool Find = false;

	while (!input_file.eof())
	{
		if (symbol == '\n')
		{
			++numberStr;
		}
		input_file.get(symbol);

		counter = 0;

		while (symbol == argv[2][counter])
		{
			input_file.get(symbol);
			++counter;
			if (counter == strlen(argv[2]))
			{
				Find = true;
				if (numberStr != pastNumberStr)
				{
					cout << numberStr << " ";
					pastNumberStr = numberStr;
				}
			}
		}
	}
	if (!Find)
	{
		cout << "Text not found.\n";
		input_file.close();
		return 1;
	}
	input_file.close();
	return 0;
}