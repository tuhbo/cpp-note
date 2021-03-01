#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using namespace placeholders;

int main()
{
	vector<int> vec, vec2;
	int a;
	while(cin>>a)
	{
		vec.push_back(a);
	}
	transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), _1, 2));
	for(auto k:vec) cout<<k<<" ";
	return 0;	
} 
