#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node
{
private:
	template<class T>
	using Ptr = Node<T>*;
	template<class T>
	using PtrToHead = Node<T>*;
	template<class T>
	using PtrToTail = Node<T>*;
	T element;
	Ptr<T> front_ptr, next_ptr;
public:
	Node() { front_ptr = next_ptr = nullptr; }

	void set_front_ptr(const Ptr<T> const_ptr) { front_ptr = const_ptr; }
	void set_next_ptr(const Ptr<T>  const_ptr) { next_ptr = const_ptr; }
	void set_element(const T const_element) { element = const_element; }

	Ptr<T> get_front_ptr() { return front_ptr; }
	Ptr<T> get_next_ptr() { return next_ptr; }
	Ptr<T> get_current_ptr() { return this; }
	T get_element() { return element; }
};
template<class T>
using Ptr = Node<T>*;
template<class T>
using PtrToHead = Node<T>*;
template<class T>
using PtrToTail = Node<T>*;

template<class T>
class MyList
{
private:
	PtrToHead<T> head_ptr;
	PtrToTail<T> tail_ptr;
	int size;
public:
	MyList() { size = 0; head_ptr = tail_ptr = nullptr; }

	PtrToHead<T> get_head_ptr() { return head_ptr; }
	PtrToTail<T> get_tail_ptr() { return tail_ptr; }
	int get_size() { return size; }

	Node<T> pop_front();
	Node<T> pop_back();
	void push_front(const Node<T> new_node);
	void push_back(const Node<T> new_node);

	void bubble_sort();
	void bubble_sort(Ptr<T> begin_ptr, Ptr<T> end_ptr);
	void insert_sort();
	void insert_sort(Ptr<T> begin_ptr, Ptr<T> end_ptr);
	void qucik_sort();
	void qucik_sort(Ptr<T> begin_ptr, Ptr<T> end_ptr);
};