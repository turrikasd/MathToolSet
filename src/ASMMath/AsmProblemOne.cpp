#include "AsmProblemOne.h"

using namespace std;

#ifdef WIN32
void AsmProblemOne()
{
	__asm
	{
		PUSH ebx; // Save EBX. We need it for DIV. Restored in the very end

		PUSH 3E9h; // We use this to check when we're done printing
		MOV ecx, 3E7h; // 999 - We don't want the 1000th
		JMP loop_start;

push_to_stack:
		PUSH ecx;
		SUB ecx, 01h;

loop_start:

		// Test if is multiple of three
		MOV ebx, 03h;
		MOV eax, ecx;
		XOR edx, edx;
		DIV ebx;
		CMP edx, 0;
		JE push_to_stack;

		// Test if is multiple of five
		MOV ebx, 05h;
		MOV eax, ecx;
		XOR edx, edx;
		DIV ebx;
		CMP edx, 0;
		JE push_to_stack;

		loop loop_start;
	}

	int iPrint;
	cout << "0 "; // We count for the zero to be natural, so print it.

	__asm XOR eax, eax; // Zero eax, we'll use it to count the answer

__asm print_all_start:

	__asm POP ebx;
	__asm CMP ebx, 3E9h; // We pushed 3E9h to the stack in the beginning, when we get it back we're done
	__asm JE exit_out;

	__asm ADD eax, ebx; // Add the value we're printing to the answer
	__asm MOV iPrint, ebx;

	__asm PUSH eax; // cout will mess up eax
	cout << iPrint << " ";
	__asm POP eax;

	__asm JMP print_all_start;

__asm exit_out:
	__asm MOV iPrint, eax; // Move the answer to iPrint
	cout << endl << "The answer is: " << iPrint << endl;

	__asm POP ebx; // Saved in the beginning
}
#else
void AsmProblemOne()
{
	// TODO
}
#endif