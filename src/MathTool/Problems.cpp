#include <iostream>

#include "Problems.h"

using namespace std;

void RunTest(char test)
{
	switch (test)
	{
	case 1:
		cout << "Problem #1: Find the sum of all the multiples of 3 or 5 below 1000" << endl;
		if (RunAsAsm())
			AsmProblemOne();
		else
			CppProblemOne();
	default:
		break;
	}
}

bool RunAsAsm()
{
	bool answer = false;

	while (!answer)
	{
		cout << endl;
		cout << "Would you like the problem to be run as:" << endl;
		cout << "C++,      enter: 0" << endl;
		cout << "Assembly, enter: 1" << endl;

		char input;
		cin >> input;

		switch (input)
		{
		case '0':
			return false;
		case '1':
			return true;
		default:
			cout << "Invalid entry. Try again" << endl;
		}
	}

	return false;
}