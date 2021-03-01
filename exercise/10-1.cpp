#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef pair<string, int> PII; 

int main()
{
	string str;
	int val;
	vector<PII> vec;
	PII p;
	while(cin>>str>>val)
	{
		p = {str, val};
		vec.push_back(p);
	}
	for(vector<PII>::iterator it = vec.begin();it!=vec.end();++it)
	{
		cout<<"{"<<(*it).first<<", "<<(*it).second<<"}"<<endl;
	}
	return 0;
}
