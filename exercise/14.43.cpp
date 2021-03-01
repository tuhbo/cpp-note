#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;

int main()
{
	vector<int> vec, vec2;
	int a, divided;
	cin>>divided;
	while(cin>>a)
	{
		vec.push_back(a);
	}
	cout<<count_if(vec.begin(), vec.end(), bind(modulus<int>(), _1, divided));
	return 0;	
} 
