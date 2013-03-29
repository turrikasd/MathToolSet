#include "AsmProblemOne.h"

using namespace std;

#ifdef _MSC_VER
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
#elif defined __GNUC__
void AsmProblemOne()
{
	// Above code ported to AT&T Syntax
	__asm__("pushl %ebx\n\t" // save ebx

		"pushl $0x3E9\n\t" // push 1001
		"movl $0x3E7, ‰ecx\n\t" // 999 for the counter
		"jmp loop_start\n\t"

	"push_to_stack:\n\t"

		"pushl %ecx\n\t"
		"subl $0x1, %ecx\n\t"

	"loop_start:\n\t"

		// Test if multiple of three
		"movl $0x3, %ebx\n\t"
		"movl %ecx, %eax\n\t"
		"xorl %edx, %edx\n\t"
		"divl %ebx\n\t"
		"cmp %edx, $0x0\n\t"
		"je push_to_stack\n\t"

		// Test if multiple of five
		"movl $0x5, %ebx\n\t"
		"movl %ecx, %eax\n\t"
		"xorl %edx, %edx\n\t"
		"divl %ebx\n\t"
		"cmp %edx, $0x0\n\t"
		"je push_to_stack\n\t"

		"loop loop_start");

	int iPrint;
	cout << "0 "; // Zero as natural

	__asm__("xorl %eax, %eax"); // zero eax

__asm__("print_all_start:"); // as asm to avoid weird compiler errors

	__asm__("popl %ebx");
	__asm__("cmp %ebx, $0x3E9"); // 1001 we pushed earlier
	__asm__("je exit_out"); // Exit once we find 3E7h

	__asm__("adll %ebx, %eax"); // add current to accumulator
	__asm__("movl %ebx, %iPrint"); // Move ebx for printing

	__asm__("pushl %eax"); // cout will mess up eax so save it
	cout << iPrint << " ";
	__asm__("popl %eax");

	__asm__("jmp print_all_start");

__asm__("exit_out:");
	__asm__("movl %eax, %iPrint"); // Move the answer to iPrint
	cout << endl << "The answer is: " << iPrint << endl;
	
	__asm__("popl %ebx"); // Restore ebx. We saved it in the beginning
}
#endif
