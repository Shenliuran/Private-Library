#include "mylist.h"
#include "algorithm.h"
int main(void)
{
	MyList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.print_whole_list(POSTIVE);
	list.bubble_sort(list, ASC);
	list.print_whole_list(POSTIVE);
	return 0;
}