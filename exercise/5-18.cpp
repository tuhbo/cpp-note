#include <iostream>
#include <vector>
using namespace std;
int main()
{
	vector<string *> str;
	string *s = new string[3];
	s[0] = "hello";
	s[1] = "world";
	s[2] = "123";
	for(int i=0;i<3;i++)
	{
		str.push_back(s+i);
	}
	for(vector<string *>::iterator it = str.begin();it != str.end();++it)
	{
		cout<<**it<<" "<<(*it)->size()<<endl;
	}
	return 0;
} 
