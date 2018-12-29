#include "mylist.h"

template<class ElemType>
void MyList<ElemType>::bubble_sort(const SortStype stype)
{
	PtrInst<ElemType> ptrNow, ptrCompared;
	ptrNow = ptrHeadNode->ptrNext;
	int nowNodeLocation = 1;
	while (ptrNow)
	{
		ptrCompared = ptrNow->ptrNext;
		while (ptrCompared)
		{
			PtrInst<ElemType> ptrComparedNext = ptrCompared->ptrNext;
			if (stype == ASC && ptrNow->getElem() > ptrCompared->getElem())
				swapNode(ptrNow, ptrCompared);
			else if (stype == DESC && ptrNow->getElem() < ptrCompared->getElem())
				swapNode(ptrNow, ptrCompared);
			ptrCompared = ptrComparedNext;
			SORT_POINTER_RESET;
		}
		SORT_POINTER_RESET;
		ptrNow = ptrNow->ptrNext;
		nowNodeLocation++;
	}
}

template<class ElemType>
void MyList<ElemType>::qucik_sort(const SortStype stype)
{
}
