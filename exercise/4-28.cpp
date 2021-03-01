#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> a;
	int i;
	while(cin>>i)
	{
		a.push_back(i);
	}
	for(vector<int>::const_iterator it = a.begin();it!=a.end();it++)
	{
		cout<<*it<<" ";
	}
	int *pa = new int[a.size()];
	for(vector<int>::const_iterator it = a.begin();it!=a.end();it++)
	{
		*pa++ = *it;
	}
	int *p = pa-a.size();
	while(p!=pa)
	{
		cout<<*p++<<" ";
	}
	return 0;
}
