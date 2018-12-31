#include "mylist.h"
template<class ElemType>
void MyList<ElemType>::swapNode(PTR &frontNode, PTR &backNode)
{
	PTR ptrFrontNodeFront, ptrFrontNodeNext, ptrBackNodeFront, ptrBackNodeNext;
	if (frontNode->ptrNext == backNode)
	{
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;
		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = frontNode;
		frontNode->ptrNext = ptrBackNodeNext;
		frontNode->ptrFront = backNode;
		if (ptrBackNodeNext != nullptr)
		{
			ptrBackNodeNext->ptrFront = frontNode;
		}
	}
	else if (backNode == ptrTail && frontNode->ptrNext->ptrNext != backNode)
	{
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrFrontNodeNext = frontNode->ptrNext;
		ptrBackNodeFront = backNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;

		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = ptrFrontNodeNext;
		ptrFrontNodeNext->ptrFront = backNode;
		backNode->ptrNext = ptrFrontNodeNext;
		ptrBackNodeFront->ptrNext = frontNode;
		frontNode->ptrFront = ptrBackNodeFront;
		frontNode->ptrNext = ptrBackNodeNext;
	}
	else if (frontNode->ptrNext->ptrNext == backNode)
	{
		PTR ptrBetween;
		ptrBetween = frontNode->ptrNext;
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;

		ptrBetween->ptrFront = backNode;
		ptrBetween->ptrNext = frontNode;
		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = ptrBetween;
		frontNode->ptrFront = ptrBetween;
		frontNode->ptrNext = ptrBackNodeNext;
		if (ptrBackNodeNext != nullptr)
			ptrBackNodeNext->ptrFront = frontNode;
	}
	else
	{
		ptrFrontNodeFront = frontNode->ptrFront;
		ptrFrontNodeNext = frontNode->ptrNext;
		ptrBackNodeFront = backNode->ptrFront;
		ptrBackNodeNext = backNode->ptrNext;

		ptrFrontNodeFront->ptrNext = backNode;
		backNode->ptrFront = ptrFrontNodeFront;
		backNode->ptrNext = ptrFrontNodeNext;
		ptrFrontNodeNext->ptrFront = backNode;

		ptrBackNodeFront->ptrNext = frontNode;
		frontNode->ptrFront = ptrBackNodeFront;
		frontNode->ptrNext = ptrBackNodeNext;
		if (ptrBackNodeNext != nullptr)
			ptrBackNodeNext->ptrFront = frontNode;
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::push_back(const ElemType newElem)
{
	PTR ptrNewNode = new ListNode<ElemType>(newElem);
	if (size == 0)
	{
		PTRFIRST = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		ptrTail->ptrNext = ptrNewNode;
		ptrNewNode->ptrFront = ptrTail;
		ptrTail = ptrNewNode;
	}
	size++;
}
template<class ElemType>
void MyList<ElemType>::push_front(const ElemType newElem)
{
	PTR ptrNewNode = new ListNode<ElemType>(newElem);
	if (size == 0)
	{
		PTRFIRST = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		PTR ptrOriginalFirstNode;
		ptrOriginalFirstNode = PTRFIRST;
		ptrNewNode->ptrNext = PTRFIRST;
		PTRFIRST = ptrNewNode;
		ptrOriginalFirstNode->ptrFront = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
	}
	size++;
}
template<class ElemType>
ElemType MyList<ElemType>::pop_back()
{
	PTR ptrDelete;
	ElemType record;
	if (size != 0)
	{
		record = ptrTail->getElem();
		ptrDelete = ptrTail;
		ptrTail = ptrDelete->ptrFront;
		delete ptrDelete;
		ptrTail->ptrNext = nullptr;
		size--;
		return record;
	}
	else
	{
		cout << "can not be functioned, because this is a empty list!!" << endl;
		return ElemType();
	}
}
template<class ElemType>
ElemType MyList<ElemType>::pop_front()
{
	if (size != 0)
	{
		PTR ptrDelete;
		ElemType record;
		ptrDelete = PTRFIRST;
		record = ptrDelete->getElem();
		PTRFIRST = ptrDelete->ptrNext;
		delete ptrDelete;
		size--;
		return record;
	}
	else
	{
		cout << "can not be functioned, because this is a empty list!!" << endl;
		return ElemType();
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
ElemType MyList<ElemType>::operator [](const int index)
{
	if (index > size || index < 1)
	{
		cout << "crossing!!" << endl;
		return ElemType();
	}
	else
	{
		int i = 1;
		PTR ptrNow = PTRFIRST;
		while (i != index)
		{
			ptrNow = ptrNow->ptrNext;
			i++;
		}
		return ptrNow->getElem();
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::print_whole_list(const PrintStyle style)
{
	PTR ptrFlag;
	if (style == POSTIVE)
	{
		ptrFlag = PTRFIRST;
		if (ptrFlag == nullptr)
			cout << "can not ba functioned, because this is an empty list!!" << endl;
		else
		{
			while (ptrFlag)
			{
				cout << ptrFlag->getElem();
				if (ptrFlag == nullptr)
					cout << endl;
				ptrFlag = ptrFlag->ptrNext;
			}
			cout << endl;
		}
	}
	else
	{
		ptrFlag = ptrTail;
		if (ptrFlag == nullptr)
			cout << "can not ba functioned, because this is an empty list!!" << endl;
		else
		{
			while (ptrFlag != ptrHeadNode)
			{
				cout << ptrFlag->getElem();
				if (ptrFlag == ptrHeadNode)
					cout << endl;
				ptrFlag = ptrFlag->ptrFront;
			}
			cout << endl;
		}
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void list_copy(MyList<ElemType> originalList, MyList<ElemType> &targetList)
{
	for (int i = 1; i <= originalList.getSize(); i++)
	{
		targetList.push_back(originalList[i]);
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::deleteNode(PTR &nowNode)
{
	if (nowNode->ptrNext == nullptr)
	{
		ptrTail = nowNode->ptrFront;
		delete nowNode;
		ptrTail->ptrNext = nullptr;
	}
	else
	{
		PTR ptrNowFront = nowNode->ptrFront;
		PTR ptrNowNext = nowNode->ptrNext;
		ptrNowFront->ptrNext = ptrNowNext;
		ptrNowNext->ptrFront = ptrNowFront;
		delete nowNode;
	}
	size--;
}
template<class ElemType>
void MyList<ElemType>::deleteNodeByIndex(const int deletedIndex)
{
	if (deletedIndex < 1 || deletedIndex > size)
		cout << "crossing!!" << endl;
	else
	{
		PTR ptrNow = PTRFIRST;
		int i = 1;
		while (i != deletedIndex)
		{
			ptrNow = ptrNow->ptrNext;
			i++;
		}
		deleteNode(ptrNow);
	}
}
template<class ElemType>
void MyList<ElemType>::deleteNodeByElem(const ElemType deletedElem)
{
	PTR ptrNow = PTRFIRST;
	int record = 0;
	while (ptrNow != nullptr)
	{
		PTR ptrNowNext = ptrNow->ptrNext;
		if (deletedElem == ptrNow->getElem())
		{
			deleteNode(ptrNow);
			record++;
		}
		ptrNow = ptrNowNext;
	}
	if (record == 0)
		cout << "there is no such element!!" << endl;
	else
	{
		cout << "there is " << record << " elements you have deleted yet!!" << endl;
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::insertNode(PTR &newNodeFront, PTR &newNode)
{
	if (newNodeFront->ptrNext == nullptr)
	{
		newNodeFront->ptrNext = newNode;
		newNode->ptrFront = newNodeFront;
		ptrTail = newNode;
	}
	else
	{
		PTR newNodeNext = newNodeFront->ptrNext;
		newNodeFront->ptrNext = newNode;
		newNode->ptrFront = newNodeFront;
		newNodeNext->ptrFront = newNode;
		newNode->ptrNext = newNodeNext;
	}
	size++;

}
template<class ElemType>
void MyList<ElemType>::insertNodeByIndex(const int index, const ElemType insertedElem)
{
	int recordSize = size;
	if (index < 1 || index > recordSize + 1)
	{
		cout << "crossing!!" << endl;
	}
	else
	{
		PTR newNode = new ListNode<ElemType>(insertedElem);
		if (index == 1)
			insertNode(ptrHeadNode, newNode);
		else
		{
			PTR ptrNow = ptrHeadNode->ptrNext;
			int i = 2;
			while (i != index)
			{
				ptrNow = ptrNow->ptrNext;
				i++;
			}
			insertNode(ptrNow, newNode);
		}
	}
}
/***************************/
/***************************/
/***************************/
template<class ElemType>
void MyList<ElemType>::reverseList()
{
	PTR ptrNow = PTRFIRST;
	PTR ptrOrigianlNext;
	PTR ptrMove;
	PTR ptrTailOriginalFront = ptrTail->ptrFront;
	ptrHeadNode->ptrNext = ptrTail;
	ptrOrigianlNext = ptrNow->ptrNext;
	ptrMove = ptrOrigianlNext->ptrNext;
	ptrTail->ptrFront = ptrHeadNode;
	ptrTail->ptrNext = ptrTailOriginalFront;
	ptrTail = ptrNow;
	ptrNow->ptrFront = ptrOrigianlNext;
	ptrOrigianlNext->ptrNext = ptrNow;
	ptrNow->ptrNext = nullptr;
	ptrNow = ptrOrigianlNext;
	ptrOrigianlNext = ptrMove;
	ptrOrigianlNext->ptrFront = ptrMove;
	ptrMove = ptrMove->ptrNext;
	while (ptrOrigianlNext != PTRFIRST)
	{
		ptrNow->ptrFront = ptrOrigianlNext;
		ptrOrigianlNext->ptrNext = ptrNow;
		ptrOrigianlNext->ptrFront = ptrMove;
		ptrNow = ptrOrigianlNext;
		ptrOrigianlNext = ptrMove;
		ptrMove = ptrMove->ptrNext;
	}
}