#include "Main.h"

using namespace std;

int main(int argc, char* argv[])
{
	char* input;
	char* output;

	cout << "Usage: [A]|[C] <COMMAND> [PARAM1] [PARAM2]..." << endl;
	cout << "If no library is defined, ASM is assumed" << endl;

	cin >> input;

	if (input[0] == 'C')
		output = CppInput(input);
	else
		output = AsmInput(input);

	cout << output << endl;

	return 0;
}

char* AsmInput(char* input)
{
	return "ERROR: Not Implemented!";
}

char* CppInput(char* input)
{
	return "ERROR: Not Implemented!";
}