#include <iostream>
#include <forward_list>
using namespace std; 

void test_and_insert(forward_list<string> &sflst, const string &str1, const string &str2)
{
	auto prev = sflst.before_begin();
	auto curr = sflst.begin();
	bool flag = false;
	while(curr!=sflst.end())
	{
		if(*curr==str1)
		{
			curr=sflst.insert_after(curr, str2);
			flag=true;
			break;
		}
		prev = curr;
		curr ++;
	}
	if(!flag)
	{
		sflst.insert_after(prev, str2);
	}
}
int main()
{
	forward_list<string>  sflst = {"hello", "!",  "world", "!"};
	test_and_insert(sflst, "hello", "ÄãºÃ");
	for(auto name:sflst) cout<<name<<" ";
	cout<<endl;
		test_and_insert(sflst, "!", "?");
	for(auto name:sflst) cout<<name<<" ";
	cout<<endl;
		test_and_insert(sflst, "bye", "ÔÙ¼û");
	for(auto name:sflst) cout<<name<<" ";
	cout<<endl;
}
