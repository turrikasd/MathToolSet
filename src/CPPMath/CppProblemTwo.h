#ifdef CPPMath_EXPORTS
#define CPPMath_EI __declspec(dllexport)
#else
#define CPPMath_EI __declspec(dllimport)
#endif

#include <iostream>

void CPPMath_EI CppProblemTwo();