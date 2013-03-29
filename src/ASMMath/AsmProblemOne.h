#if defined (__unix__)
	#define ASMMath_EI __attribute__ ((__visibility__("default")))
#elif defined (WIN32)
	#ifdef ASMMath_EXPORTS
		#define ASMMath_EI __declspec(dllexport)
	#else
		#define ASMMath_EI __declspec(dllimport)
	#endif
#endif

#include <iostream>

extern void ASMMath_EI AsmProblemOne();
extern void PrintOut(int num);