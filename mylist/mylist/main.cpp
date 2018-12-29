#include "mylist.h"
#include "mylist.cpp"
#include "algorithm.cpp"
int main(void)
{
	MyList<int> list;
	list.push_back(1);
	list.push_back(5);
	list.push_back(3);
	list.push_back(6);
	list.push_back(4);
	list.push_back(2);

	list.print_whole_list();
	list.bubble_sort(DESC);
	list.print_whole_list();
	return 0;
}