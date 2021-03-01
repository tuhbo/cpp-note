#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &str)
{
	return str.size()>=5;
}

int main()
{
	vector<string> words;
	string word;
	while(cin>>word)
	{
		words.push_back(word);
	}
	vector<string>::iterator it = partition(words.begin(), words.end(), cmp);
	for(auto iter=words.begin();iter!=words.end();++iter)
		cout<<*iter<<" ";
	return 0;
}
