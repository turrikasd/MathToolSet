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
	// AT&T Syntax
	int iPrint;
	asm("pushq $0x3E9;" // Push 1001, we use this to check when we're done printing
	    "movl $0x3E7, %ecx;" // Move 999 to ecx - loop counter
	    "jmp loop_start");

asm("push_to_stack:;"
	    "pushq %rcx;"
	    "subl $0x1, %ecx");

asm("loop_start:;"
	    "movl $0x3, %ebx;"
"loop_second:");

	asm("movl %ecx, %eax;" // Move the current number we want to test to eax
	    "xor %edx, %edx;" // Zero out edx
	    "div %ebx;" 
	    "cmp $0x0, %edx;" // Check for remainder. Note the constant has to be specified first
	    "je push_to_stack"); // Jump if no remainder

	asm("cmp $0x5, %ebx;" // Is this second round?
	    "je loop_end;" // true, deduct and start over
	    "movl $0x5, %ebx;" // false, do the second round with 5
	    "jmp loop_second");

	asm("loop_end:;"
	    "loop loop_start");

	// Printing code
	cout << "0 "; // Print zero, we count it as natural

	asm("xor %eax, %eax;" // Zero out eax, we need it to count the answer
 "print_loop_start:");	

	asm("popq %%rcx;"
	    "cmp $0x3E9, %%ecx;" // check if we have reached the end
	    "je exit_out;" // true, we jump to exit code
	    "addl %%ecx, %%eax;" // Add the number to answer
	    "movl %%ecx, %0;" // Move the current number to iPrint
	    "pushq %%rax;" // cout will mess up eax, so save it
		:"=m"(iPrint));
	
	cout << iPrint << " "; // Print the contents of iPrint, set in ASM

	asm("popq %%rax;" // Restore eax after cout
	    "jmp print_loop_start;"
"exit_out:;"
	    "movl %%eax, %0;"
		:"=m"(iPrint));

	cout << endl << "The answer is: " << iPrint << endl; // Finally print the answer set to iPrint in ASM
}
#endif
