#include "AsmProblemTwo.h"
#include <stdio.h>

using namespace std;

#ifdef _MSC_VER
void AsmProblemTwo()
{
    int sum = 2;
    int high = 2;

    cout << "2 ";

    __asm   MOV ecx, 01h;

    __asm
    {
    loop_start:
        MOV edx, high;
        ADD high, ecx;
        MOV ecx, edx;

        CMP 03D0900h, high;
        JA exit_out;
        
        XOR edx, edx;
        MOV eax, high;
        PUSH ecx; 
    }
}

#elif defined __GNUC__
void AsmProblemTwo()
{
    int sum;
    int high; // We'll use cout to print every even high so we store it in mem

    cout << "2 ";

    asm("movl $0x1, %%ecx;" // store low in ecx
        "movl $0x2, %0;" // store 2 in sum
        "movl $0x2, %1;" // store 2 in high
    "loop_start:;"
        // Swap and count new high
        "movl %1, %%edx;" // Move high to temp location
        "addl %%ecx, %1;" // Add low to high
        "movl %%edx, %%ecx;" // move old high to low
        
        "cmp $0x3D0900, %1;" // Compare 4M and High
        "JA exit_out;" // Jump out of loop if greater
        
        "xorl %%edx, %%edx;" // Zero edx
        "movl %1, %%eax;" // move high to eax
        "pushq %%rcx;" // save ecx
        "movl $0x2, %%ecx;"
        "div %%ecx;" // Divide high by 2
        "popq %%rcx;" // restore ecx
        "cmp $0x0, %%edx;" // Compare remainder with zero
        "JE print_and_sum;" // if equal (is multiple of two)
        "JMP loop_start;"

    "print_and_sum:;"
        "addl %1, %0;" // add high to sum
      
        "JMP loop_start;"

    "exit_out:;"
            :"=r"(sum),
             "=r"(high)
             ::"%eax", "%ebx", "%ecx", "%edx");

    cout << endl << "The answer is: " << sum << endl;
}
#endif
