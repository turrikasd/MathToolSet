#include "CppProblemTwo.h"

using namespace std;

void CppProblemTwo()
{
	int low = 1;
	int high = 2;
	int temp;

	int sum = 2;

	cout << "2 ";

	while (true)
	{
		// Swap the numbers and count new high
		temp = high;
		high += low;
		low = temp;

		// Stop at 4M
		if (high >= 4000000)
			break;

		// Only add if even
		if (high % 2 == 0)
		{
			sum += high;
			cout << high << " ";
		}
	}

	cout << endl << "The answer is: " << sum << endl;
}