#ifdef ASMMath_EXPORTS
#define ASMMath_EI __declspec(dllexport)
#else
#define ASMMath_EI __declspec(dllimport)
#endif

#include <iostream>

void ASMMath_EI AsmProblemOne();