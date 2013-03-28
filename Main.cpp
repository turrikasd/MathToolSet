#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char* argv[])
{
	float input = atof(argv[1]);
	float output = sqrt(input);

	fprintf(stdout, "The square root of %g is %g\n", input, output);

	return 0;
}