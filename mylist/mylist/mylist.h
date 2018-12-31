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
private:
	ElemType elem;
protected:
public:
	template<class ElemType>
	using Ptr = ListNode<ElemType>*;
	PTR ptrFront, ptrNext;
	ListNode(const ElemType constElem) { elem = constElem; ptrFront = ptrNext = nullptr; }
	void setElem(const ElemType constElem) { elem = constElem; }
	ElemType getElem() { return elem; }
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
	void push_back(const ElemType newElem);
	void push_front(const ElemType newElem);
	ElemType pop_back();
	ElemType pop_front();
	ElemType operator [](const int index);//start from index = 1
	void print_whole_list(const PrintStyle style = POSTIVE);
	void bubble_sort(const SortStype stype = ASC);
	void qucik_sort(const SortStype stype = ASC);
	void deleteNodeByIndex(const int deletedIndex);
	void deleteNodeByElem(const ElemType deletedElem);
	void insertNodeByIndex(const int index, const ElemType insertedElem);
	void reverseList();
};