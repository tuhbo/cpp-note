#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;

int main()
{
	vector<int> vec;
	int a;
	while(cin>>a)
	{
		vec.push_back(a);
	}
	cout<<count_if(vec.begin(), vec.end(), bind(greater<int>(), _1, 1024));
	return 0;	
} 
