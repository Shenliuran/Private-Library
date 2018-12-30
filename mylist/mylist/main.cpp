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
	list.bubble_sort();
	list.print_whole_list();
	cout << list[1] << endl;
	cout << list[0] << endl;
	MyList<int> list1;
	list_copy(list, list1);
	list1.print_whole_list();
	/*list.bubble_sort(DESC);
	list.print_whole_list();*/
	return 0;
}