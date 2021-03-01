#include <iostream>
#include <list>
#include <deque>
using namespace std;
int main()
{
	list<int> ilst;
	deque<int> evenDq, oddDq;
	int ival;
	while(cin>>ival)
		ilst.push_back(ival);
	for(list<int>::iterator it=ilst.begin();it!=ilst.end();++ it)
	{
		if(*it%2==0) evenDq.push_back(*it);
		else oddDq.push_back(*it);
	}
	for(deque<int>::iterator it=evenDq.begin();it!=evenDq.end();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;
	for(deque<int>::iterator it=oddDq.begin();it!=oddDq.end();++it)
	{
		cout<<*it<<" ";
	}
}
