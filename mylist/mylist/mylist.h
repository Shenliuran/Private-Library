#pragma once
#define POSTIVE 1
#define REVERSE 2
#define DESC 1
#define ASC 2
#include<iostream>
using namespace std;
typedef int PrintStyle;
typedef int SortStype;
/**************************/
/**************************/
/**************************/
template<class ElemType>
class Node
{
private:
	ElemType elem;
protected:
	bool operator <(const ElemType comparedElem)
	{
		 

	}
public:
	template<class ElemType>
	using PtrInst = Node<ElemType>*;
	template<class ElemType>
	using PtrNode = Node<ElemType>*;

	PtrInst<ElemType> ptrFront, ptrNext;
	Node(const ElemType constElem) { elem = constElem; ptrFront = ptrNext = nullptr; }

	void setElem(const ElemType constElem) { elem = constElem; }
	ElemType getElem() { return elem; }
};

/***************************/
template<class ElemType>
using PtrInst = Node<ElemType>*;
template<class ElemType>
using PtrNode = Node<ElemType>*;
/***************************/
/***************************/
/***************************/
template<class ElemType>
class MyList
{
private:
	int size;
protected:
	PtrNode<ElemType> ptrHeadNode;
	PtrInst <ElemType> ptrTail;
public:
	MyList()
	{
		ptrHeadNode = new Node<ElemType>(ElemType());
		ptrHeadNode->ptrFront = ptrHeadNode;
		ptrHeadNode->ptrNext = ptrHeadNode;
		size = 0;
		ptrTail = ptrHeadNode;
	}
	int getSize() { return size; }
	void push_back(const ElemType newElem);
	void push_front(const ElemType newElem);
	ElemType pop_back();
	ElemType pop_front();
	void print_whole_list(const PrintStyle style);
	void bubble_sort(MyList<ElemType>& list, SortStype stype);
};
/***************************/
template<class ElemType>
void swapNode(PtrNode<ElemType> &frontNode, PtrNode<ElemType> &backNode)
{
	PtrInst<ElemType> ptrFrontNodeFront, ptrFrontNodeNext, ptrBackNodeFront, ptrBackNodeNext;
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
	ptrBackNodeNext->ptrFront = frontNode;
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
