#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
	vector<int> vec = {1, 2, 2, 3, 4, 5, 5, 6};
	list<int> li;
	unique_copy(vec.cbegin(), vec.cend(), inserter(li, li.end()));
	for(auto c:li) cout<<c<<" ";
	return 0;
} 
