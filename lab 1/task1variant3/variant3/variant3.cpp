// task1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
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

	string str;
	int curStr;
	int numberStr = 1;
	int pastNumberStr = 0;
	bool Find = false;

	while (!input_file.eof())
	{
		getline(input_file, str);
		curStr = str.find(argv[2]);

		if (numberStr != pastNumberStr && curStr != -1)
		{
			cout << numberStr << " ";
			pastNumberStr = numberStr;
			Find = true;
		}
		++numberStr;
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