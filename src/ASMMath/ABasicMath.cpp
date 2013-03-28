#include "ABasicMath.h"

float AAdd(float a, float b)
{
	__asm
	{
		MOV eax, a;
		ADD eax, b;
	}
}

float ASub(float a, float b)
{
	__asm
	{
		MOV eax, a;
		SUB eax, b;
	}
}