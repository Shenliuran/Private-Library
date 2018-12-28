#include "mylist.h"

int main(void)
{
	MyList<int> list;
	list.push_back(1);
	list.push_back(2);
	list.print_whole_list(POSTIVE);
	list.print_whole_list(REVERSE);

	return 0;
}