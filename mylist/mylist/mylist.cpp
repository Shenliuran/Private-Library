#include "mylist.h"

template<class T>
Node<T> MyList<T>::pop_front()
{
	if (head_ptr != tail_ptr)
	{
		Node<T> record;
		Ptr<T> delete_ptr;
		record = *head_ptr;
		delete_ptr = head_ptr;
		head_ptr = head_ptr->get_next_ptr();
		head_ptr->set_front_ptr(nullptr);

		delete[] delete_ptr;
		return record;
	}
	else
	{
		cout << "this is a empty list" << endl;
		return;
	}
}

template<class T>
Node<T> MyList<T>::pop_back()
{
	if (head_ptr != tail_ptr)
	{
		Node<T> record;
		Ptr<T> delete_ptr;
		record = *tail_ptr;
		delete_ptr = tail_ptr;
		tail_ptr = tail_ptr->get_front_ptr();
		tail_ptr->set_next_ptr(nullptr);

		delete[] delete_ptr;
		return record;
	}
	else
	{
		cout << "this is empty list!!" << endl;
		return;
	}
}

template<class T>
void MyList<T>::push_front(const Node<T> new_node)
{
	Ptr<T> p;
	p = new_node.get_current_ptr();
	p->set_next_ptr(head_ptr);
	head_ptr->set_front_ptr(p);
	head_ptr = p;
}

template<class T>
void MyList<T>::push_back(const Node<T> new_node)
{
	Ptr<T> p;
	p = new_node.get_current_ptr();
	tail_ptr->set_next_ptr(p);
	p->set_front_ptr(tail_ptr);
	tail_ptr = p;
}

//void bubble_sort();
//void bubble_sort(PtrToNode<T> begin_ptr, PtrToNode<T> end_ptr);
//void insert_sort();
//void insert_sort(PtrToNode<T> begin_ptr, PtrToNode<T> end_ptr);
//void qucik_sort();
//void qucik_sort(PtrToNode<T> begin_ptr, PtrToNode<T> end_ptr);