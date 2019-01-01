#include "mylist.h"

template<class ElemType>
void MyList<ElemType>::bubble_sort(const SortStype stype)
{
	Ptr<ElemType> ptrNow, ptrCompared;
	ptrNow = ptrHeadNode->ptrNext;
	int nowNodeLocation = 1;
	while (ptrNow)
	{
		ptrCompared = ptrNow->ptrNext;
		while (ptrCompared)
		{
			Ptr<ElemType> ptrComparedNext = ptrCompared->ptrNext;
			if (stype == ASC && ptrNow->elem > ptrCompared->elem)
				swapNode(ptrNow, ptrCompared);
			else if (stype == DESC && ptrNow->elem < ptrCompared->elem)
				swapNode(ptrNow, ptrCompared);
			ptrCompared = ptrComparedNext;
			SORT_POINTER_RESET;
		}
		SORT_POINTER_RESET;
		ptrNow = ptrNow->ptrNext;
		nowNodeLocation++;
	}
	TAIL_POINTER_REST;
}

template<class ElemType>
void MyList<ElemType>::qucik_sort(const SortStype stype)
{
	
}
/******************************/
/******************************/
/******************************/