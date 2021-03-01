#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s;
	vector<string> word;
	while(cin>>s)
	{
		for(string::size_type i=0;i<s.size();i++)
		{
			s[i] = toupper(s[i]);
		}
		word.push_back(s);
	}
	for(vector<string>::size_type i=0;i<word.size();i++)
	{
		cout<<word[i]<<" ";
		if(i%7==0)
		{
			cout<<endl;
		}
	}
	return 0;
}
