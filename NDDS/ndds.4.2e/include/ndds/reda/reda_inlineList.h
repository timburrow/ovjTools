/*
 * @(#)reda_inlineList.h    generated by: makeheader    Mon Dec  3 23:07:54 2007
 *
 *		built from:	inlineList.ifc
 */

#ifndef reda_inlineList_h
#define reda_inlineList_h


  #ifndef reda_dll_h
    #include "reda/reda_dll.h"
  #endif

#ifdef __cplusplus
    extern "C" {
#endif

struct REDAInlineList;

struct REDAInlineListNode;

extern REDADllExport struct REDAInlineListNode *
REDAInlineList_getFirst(const struct REDAInlineList *me);

extern REDADllExport struct REDAInlineListNode *
REDAInlineList_getLast(const struct REDAInlineList *me);

extern REDADllExport
RTIBool REDAInlineList_isNodeInList(struct REDAInlineList *me,
				     struct REDAInlineListNode *node);

extern REDADllExport
void REDAInlineListNode_init(struct REDAInlineListNode *me);

extern REDADllExport
void REDAInlineList_init(struct REDAInlineList *me);

extern REDADllExport
void REDAInlineList_addNodeToFrontEA(struct REDAInlineList *me,
				     struct REDAInlineListNode *node);

extern REDADllExport
void REDAInlineList_addNodeAfterEA(struct REDAInlineList *me,
				   struct REDAInlineListNode *existingNode,
				   struct REDAInlineListNode *node);

extern REDADllExport
void REDAInlineList_addNodeToBackEA(struct REDAInlineList *me,
				     struct REDAInlineListNode *node);

extern REDADllExport
void REDAInlineList_removeNodeEA(struct REDAInlineList *me,
				 struct REDAInlineListNode *node);

extern REDADllExport
int REDAInlineList_getSize(const struct REDAInlineList *me);


#ifdef __cplusplus
    }	/* extern "C" */
#endif

/* pick up hidden performance boosting macros and optimizations */
  #include "reda/reda_inlineList_impl.h"

#endif /* reda_inlineList_h */
