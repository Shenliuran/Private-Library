#include "mylist.h"
template<class ElemType>
void MyList<ElemType>::swapNode(PtrNode<ElemType> &frontNode, PtrNode<ElemType> &backNode)
{
	PtrInst<ElemType> ptrFrontNodeFront, ptrFrontNodeNext, ptrBackNodeFront, ptrBackNodeNext;
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
		PtrInst<ElemType> ptrBetween;
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
	PtrNode<ElemType> ptrNewNode = new Node<ElemType>(newElem);
	if (size == 0)
	{
		ptrHeadNode->ptrNext = ptrNewNode;
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
	PtrNode<ElemType> ptrNewNode = new Node<ElemType>(newElem);
	if (size == 0)
	{
		ptrHeadNode->ptrNext = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
		ptrTail = ptrNewNode;
	}
	else
	{
		PtrInst<ElemType> ptrOriginalFirstNode;
		ptrOriginalFirstNode = ptrHeadNode->ptrNext;
		ptrNewNode->ptrNext = ptrHeadNode->ptrNext;
		ptrHeadNode->ptrNext = ptrNewNode;
		ptrOriginalFirstNode->ptrFront = ptrNewNode;
		ptrNewNode->ptrFront = ptrHeadNode;
	}
	size++;
}
template<class ElemType>
ElemType MyList<ElemType>::pop_back()
{
	PtrInst<ElemType> ptrDelete;
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
		PtrInst<ElemType> ptrDelete;
		ElemType record;
		ptrDelete = ptrHeadNode->ptrNext;
		record = ptrDelete->getElem();
		ptrHeadNode->ptrNext = ptrDelete->ptrNext;
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
void MyList<ElemType>::print_whole_list(const PrintStyle style)
{
	PtrInst<ElemType> ptrFlag;
	if (style == POSTIVE)
	{
		ptrFlag = ptrHeadNode->ptrNext;
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