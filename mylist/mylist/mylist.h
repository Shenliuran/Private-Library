#pragma once
#define POSTIVE 1
#define REVERSE 2
#define DESC 1
#define ASC 2
#define SORT_POINTER_RESET	ptrNow = ptrHeadNode->ptrNext;\
							int i = 1;\
							while(i != nowNodeLocation)\
							{ptrNow = ptrNow->ptrNext;i++;}
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
	void swapNode(PtrNode<ElemType> &frontNode, PtrNode<ElemType> &backNode);
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
	void print_whole_list(const PrintStyle style = POSTIVE);
	void bubble_sort(const SortStype stype = ASC);
	void qucik_sort(const SortStype stype = ASC);
};