#if defined _MSC_VER
    #define ASM_TMP_DLL_IMPORT __declspec(dllimport)
    #define ASM_TMP_DLL_EXPORT __declspec(dllexport)
#else
    #if __GNUC__ >= 4
        #define ASM_TMP_DLL_IMPORT __attribute__((__visibility__("default")))
        #define ASM_TMP_DLL_EXPORT __attribute__((__visibility__("default")))
    #else
        #define ASM_TMP_DLL_IMPORT
        #define ASM_TMP_DLL_EXPORT
    #endif
#endif


#ifdef ASMMath_EXPORTS
    #define ASM_API ASM_TMP_DLL_EXPORT
#else
    #define ASM_API ASM_TMP_DLL_IMPORT
#endif
