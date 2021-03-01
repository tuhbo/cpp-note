#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map<string, vector<string> > families;
	families["张"]; 
	families["张"].push_back("强");
	families["张"].push_back("刚");
	families["王"].push_back("五");
	families["王"];
	for(map<string, vector<string> >::iterator it = families.begin();it!=families.end();++it)
	{
		cout<<it->first<<"家的孩子：";
		for(vector<string>::iterator k = (*it).second.begin();k!=(*it).second.end();++k)
		{
			cout<<*k<<" ";
		}
		cout<<endl;
	}
	return 0;
} 
