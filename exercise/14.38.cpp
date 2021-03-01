#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StrLens{
	private:
		int len;
	public:
		StrLens(int len):len(len){}
		bool operator ()(const string &s) {return s.length()==len;}
};

void readStr(istream &in, vector<string> &vec)
{
	string word;
	while(cin>>word)
	{
		vec.push_back(word);
	}
}

int main()
{
	vector<string> vec;
	readStr(cin, vec);
	const int minLen = 1, maxLen=10;
	for(int i=minLen;i<=maxLen;i++)
	{
		StrLens ob(i);
		cout<<"len: "<<i<<", cnt: "<<count_if(vec.begin(), vec.end(), ob)<<endl;
	}
	return 0;
}
