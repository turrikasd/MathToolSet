#include "CppProblemOne.h"

using namespace std;

void CppProblemOne()
{
	int out = 0;;

	for (int i = 0; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			cout << i << " ";
			out += i;
		}
	}

	cout << endl << "The answer is: " << out << endl;
}