#pragma once

#include "define.h"
#include<iostream>
using namespace std;
typedef int PrintStyle;
typedef int SortStype;
/**************************/
/**************************/
/**************************/
template<class ElemType>
class ListNode
{
public:
	ElemType elem;
	template<class ElemType>
	using Ptr = ListNode<ElemType>*;
	PTR ptrFront, ptrNext;
	ListNode(const ElemType constElem) { elem = constElem; ptrFront = ptrNext = nullptr; }
};
/***************************/
template<class ElemType>
using Ptr = ListNode<ElemType>*;
/***************************/
/***************************/
/***************************/
template<class ElemType>
class MyList
{
private:
	int size;
protected:
	PTR ptrHeadNode;
	PTR ptrTail;
	void swapNode(PTR &frontNode, PTR &backNode);
	void deleteNode(PTR &nowNode);
	void insertNode(PTR &newNodeFront, PTR&newNode);
public:
	MyList()
	{
		ptrHeadNode = new ListNode<ElemType>(ElemType());
		ptrHeadNode->ptrFront = ptrHeadNode;
		ptrHeadNode->ptrNext = ptrHeadNode;
		size = 0;
		ptrTail = ptrHeadNode;
	}
	int getSize() { return size; }
	ElemType getFisrtElem() { return PTRFIRST->elem }
	PTR getPtrFisrt() { return PTRFIRST; }
	ElemType getEndElem() { return ptrTail; }
	PTR getPtrEnd() { return ptrTail->elem; }
	void push_back(const ElemType newElem);
	void push_back(PTR ptrNewNode);
	void push_front(const ElemType newElem);
	void push_front(PTR ptrNewNode);
	ElemType pop_back();
	Ptr<ElemType> pop_back(PTR ptrReturn = nullptr);
	ElemType pop_front();
	Ptr<ElemType> pop_front(PTR ptrReturn = nullptr);
	ElemType operator [](const int index);//start from index = 1
	void print_whole_list(const PrintStyle style = POSTIVE);
	void bubble_sort(const SortStype stype = ASC);
	void qucik_sort(const SortStype stype = ASC);
	void deleteNodeByIndex(const int deletedIndex);
	void deleteNodeByElem(const ElemType deletedElem);
	void insertNodeByIndex(const int index, const ElemType insertedElem);
	void reverseList();
};