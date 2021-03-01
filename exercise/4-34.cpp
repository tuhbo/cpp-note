#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
	string s;
	vector<string> vec;
	while(cin>>s)
	{
		vec.push_back(s);
	}
	char **str = new char*[vec.size()];
	for(int i=0;i<vec.size();i++)
	{
		*str = new char[vec[i].size()];
		strcpy(*str, vec[i].c_str());
		str++;
	}
	char **p = str-vec.size();
	while(p!=str)
	{
		cout<<*p<<endl;
		p++;
	}
	return 0;
} 
