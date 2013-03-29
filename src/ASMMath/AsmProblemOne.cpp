#include "AsmProblemOne.h"

using namespace std;

void AsmProblemOne()
{
	__asm
	{
		XOR edx, edx;
		mov ecx, 3;

loop_start:

		mov eax, ecx;
		push ecx;
		push edx;

		mov ecx, 3;
		idiv ecx;
		cmp edx, 0;

		pop ecx;
		pop edx;

		je add_print_number;
		
		loop loop_start;

add_print_number:

		add edx, ecx;
		push ecx;
		call PrintOut;
		add esp, 4;

		JMP loop_start;
	}
}

void PrintOut(int num)
{
	cout << num << " ";
}