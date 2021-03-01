#include <iostream>
#include <cctype> 
using namespace std;

int main()
{
	string str, prev;
	bool flag=false;
	while(cin>>str)
	{
		#ifndef NDEBUG
			cout<<"调试的单词为: "<<str<<endl;
		#endif
		if(prev==str&&isupper(str[0]))
		{
			cout<<str<<"重复出现"<<endl; 
			flag = true;
			break;
		}
		prev = str;
	}
	if(!flag)
	{
		cout<<"无重复出现的单词"<<endl; 
	}
	return 0;
} 
