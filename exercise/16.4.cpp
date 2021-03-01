#include <iostream>
#include <vector>
#include <list>

using namespace std;

template <typename I, typename T>

I find(I b, I e, const T &v)
{
	while(b!=e&&*b!=v)
	{
		b ++;
	}
	return b;
}

int main()
{
	vector<int> vi = {0, 1, 2, 3, 4, 5, 6};
	list<string> ls = {"hello", "world", "!"};
	auto iter1 = find(vi.begin(), vi.end(), 6);
	if(iter1==vi.end()) 
	{
		cout<<"cannot find"<<endl;
	}
	else
	{
		cout<<"find the position is "<<iter1-vi.begin()<<endl;
	}
	auto iter2 = find(ls.begin(), ls.end(), "hello");
	if(iter2==ls.end()) 
	{
		cout<<"cannot find"<<endl;
	}
	else
	{
		cout<<"find the position"<<endl;
	}
	return 0;
}
