/*
 * @(#)pres_dll.h    generated by: makeheader    Mon Dec  3 23:08:14 2007
 *
 *		built from:	dll.ifc
 */

#ifndef pres_dll_h
#define pres_dll_h



#if defined(RTI_WIN32) || defined(RTI_WINCE)
  #if defined(RTI_pres_DLL_EXPORT)
    #define PRESDllExport __declspec( dllexport )
  #else
    #define PRESDllExport
  #endif /* RTI_pres_DLL_EXPORT */

  #if defined(RTI_pres_DLL_VARIABLE) 
    #if defined(RTI_pres_DLL_EXPORT)
      #define PRESDllVariable __declspec( dllexport )
    #else
      #define PRESDllVariable __declspec( dllimport )
    #endif /* RTI_pres_DLL_EXPORT */
  #else 
    #define PRESDllVariable
  #endif /* RTI_pres_DLL_VARIABLE */
#else
  #define PRESDllExport
  #define PRESDllVariable
#endif /* RTI_WIN32 || RTI_WINCE */


#endif /* pres_dll_h */
