/*
 * @(#)reda_sequenceNumber.h    generated by: makeheader    Mon Dec  3 23:07:54 2007
 *
 *		built from:	sequenceNumber.ifc
 */

#ifndef reda_sequenceNumber_h
#define reda_sequenceNumber_h


  #ifndef osapi_type_h
    #include "osapi/osapi_type.h"
  #endif
  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDABuffer; /* forward declare to appease compiler */

struct REDASequenceNumber {
    /*e The most significant part of the sequence number */
    RTI_INT32 high;
    /*e The least significant part of the sequence number */
    RTI_UINT32 low;
};


  #define REDA_SEQUENCE_NUMBER_HIGH_MAX ((RTI_INT32)0x7fffffff)


  #define REDA_SEQUENCE_NUMBER_LOW_MAX ((RTI_UINT32)0xffffffff)


  #define REDA_SEQUENCE_NUMBER_MAX {REDA_SEQUENCE_NUMBER_HIGH_MAX, \
                                    REDA_SEQUENCE_NUMBER_LOW_MAX}


  #define REDA_SEQUENCE_NUMBER_ZERO {0, 0}


  #define REDA_SEQUENCE_NUMBER_UNKNOWN \
    {(RTI_INT32)0xffffffff, (RTI_UINT32)0xffffffff}

extern REDADllExport
void REDASequenceNumber_print(const void *data, const char *desc, int indent);

extern REDADllExport
void REDASequenceNumber_setZero(struct REDASequenceNumber *me);

extern REDADllExport
RTIBool REDASequenceNumber_isZero(const struct REDASequenceNumber *me);

extern REDADllExport
RTIBool REDASequenceNumber_isMaximum(const struct REDASequenceNumber *me);

extern REDADllExport 
void REDASequenceNumber_setMaximum(struct REDASequenceNumber *me);

extern REDADllExport 
int REDASequenceNumber_compare(const struct REDASequenceNumber *me,
			       const struct REDASequenceNumber *sn);

extern REDADllExport 
void REDASequenceNumber_add(struct REDASequenceNumber *answer,
			    const struct REDASequenceNumber *sn1,
			    const struct REDASequenceNumber *sn2);

extern REDADllExport 
void REDASequenceNumber_subtract(struct REDASequenceNumber *answer,
				 const struct REDASequenceNumber *sn1,
				 const struct REDASequenceNumber *sn2);

extern REDADllExport 
void REDASequenceNumber_plusplus(struct REDASequenceNumber *me);

extern REDADllExport
void REDASequenceNumber_minusminus(struct REDASequenceNumber *me);

extern REDADllExport void
REDASequenceNumber_increment(struct REDASequenceNumber *me,
			     const struct REDASequenceNumber *sn);

extern REDADllExport void
REDASequenceNumber_decrement(struct REDASequenceNumber *me,
			     const struct REDASequenceNumber *sn);

extern REDADllExport void REDASequenceNumber_max(
    struct REDASequenceNumber *answer,
    const struct REDASequenceNumber *sn1,
    const struct REDASequenceNumber *sn2);

extern REDADllExport void REDASequenceNumber_min(
    struct REDASequenceNumber *answer,
    const struct REDASequenceNumber *sn1,
    const struct REDASequenceNumber *sn2);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up hidden performance boosting macros and optimizations */
  #include "reda/reda_sequenceNumber_impl.h"

#endif /* reda_sequenceNumber_h */