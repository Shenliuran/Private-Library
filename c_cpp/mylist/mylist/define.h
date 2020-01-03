#pragma once
#define POSTIVE 1
#define REVERSE 2
#define DESC 1
#define ASC 2
#define PTR Ptr<ElemType>
#define PTRFIRST ptrHeadNode->ptrNext
#define SORT_POINTER_RESET	ptrNow = ptrHeadNode->ptrNext;\
							int i = 1;\
							while(i != nowNodeLocation)\
							{ptrNow = ptrNow->ptrNext;i++;}
#define TAIL_POINTER_REST	PTR ptrNewTail = PTRFIRST;\
							while (ptrNewTail->ptrNext != nullptr)\
							{ptrNewTail = ptrNewTail->ptrNext;}\
							ptrTail = ptrNewTail