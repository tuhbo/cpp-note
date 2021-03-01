#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;

int main()
{
	vector<string> vec;
	string a;
	while(cin>>a)
	{
		vec.push_back(a);
	}
	cout<<*find_if(vec.begin(), vec.end(), bind(not_equal_to<string>(), _1, "pooh"));
	return 0;	
} 
