#include "Main.h"

using namespace std;

int main(int argc, char* argv[])
{
	bool exit = false;

	cout << "Choose the math routine to test" << endl;
	cout << "Enter the # of the routine" << endl;
	cout << "Type HELP for more information" << endl;

	while (!exit)
	{
		char input[128] = "";
		cin >> input;

		if (!strcmp(input, "help") | !strcmp(input, "HELP") | !strcmp(input, "Help"))
		{
			PrintHelpMessage();
			continue;
		}
		
		else if (!strcmp(input, "exit") | !strcmp(input, "EXIT") | !strcmp(input, "Exit")
			)
		{
			exit = true;
			continue;
		}

		switch (input[0])
		{
		case '1':
			RunTest(1);
			break;

		default:
			cout << "Invalid input" << endl;
			continue;
		}
	}

	return 0;
}

void PrintHelpMessage()
{
	cout << endl << endl;
	cout << "This program servers as answer to Project Euler" << endl;
	cout << "The Problems this program demonstrates can be found at:" << endl;
	cout << "http://projecteuler.net/problems" << endl;
}

void HoldExec()
{
	char c;
	cin >> c;
}