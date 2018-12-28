#pragma once
#include "mylist.h"
template<class ElemType>
void MyList<ElemType>::bubble_sort(MyList<ElemType> &list, SortStype stype)
{
	PtrInst<ElemType> ptrNow, ptrCompared;
	ptrNow = list.ptrHeadNode->ptrNext;
	while (ptrNow)
	{
		ptrCompared = ptrNow->ptrNext;
		while (ptrCompared)
		{
			if (stype == DESC && ptrNow->getElem() > ptrCompared->getElem())
			{
				swapNode(ptrNow, ptrCompared);
			}
			else if (stype == ASC && ptrNow->getElem() < ptrCompared->getElem())
			{
				swapNode(ptrNow, ptrCompared);
			}
			else
				ptrCompared = ptrCompared->ptrNext;
		}
		ptrNow = ptrNow->ptrNext;
	}
}
//template<class ElemType>
//void bubble_sort(MyList<ElemType> &list, const int index) {}
//template<class ElemType>
//void insert_sort(MyList<ElemType> &list) {}
//template<class ElemType>
//void insert_sort(MyList<ElemType> &list, const int index) {}
//template<class ElemType>
//void quick_sort(MyList<ElemType> &list) {}
//template<class ElemType>
//void quick_sort(MyList<ElemType> &list, const int index) {}