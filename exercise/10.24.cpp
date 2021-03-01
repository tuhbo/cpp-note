#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
using namespace placeholders;
bool check_size(const string &s, int sz)
{
	return sz>=s.size();
}

int main()
{
	string str;
	vector<int> vec;
	cin>>str;
	int x;
	while(cin>>x)
	{
		vec.push_back(x);
	}
	auto index = find_if(vec.begin(), vec.end(), bind(check_size, str, _1));
	cout<<*index;
	return 0; 
}
