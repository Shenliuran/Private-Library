#include "myDictionary.h"
#include "myDictionary.cpp"
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

int main(void)
{
	clock_t start, end;
	start = clock();
	Dictionary<int, char> dic;
	dic.Entry(1, 'a');
	dic.Entry(2, 'b');
	dic.Entry(3, 'c');
	dic.Entry(1, 'd');
	cout << dic.Values(1) << endl;
	Dictionary<string, string> dic1;
	dic1.Entry("nihao", "hello");
	dic1.Entry("wode", "my");
	dic1.Entry("mingzi", "name");
	dic1.Entry("shi", "is");
	cout << dic1.Values("shi") << endl;
	end = clock();
	double consumeTime = (double)(end - start) / CLOCKS_PER_SEC;
	cout << consumeTime << endl;
	return 0;
}