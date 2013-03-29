#if defined (__unix__)
	#define CPPMath_EI __attribute__ ((__visibility__("default")))
#elif defined (WIN32)
	#ifdef CPPMath_EXPORTS
		#define CPPMath_EI __declspec(dllexport)
	#else
	#define CPPMath_EI __declspec(dllimport)
	#endif
#endif

#include <iostream>

extern void CPPMath_EI CppProblemOne();