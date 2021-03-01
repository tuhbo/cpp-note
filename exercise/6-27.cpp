#include <iostream>
#include <cassert>
using namespace std; 

int main()
{
	string s;
	while (cin >> s && s != "sought") { } // empty body
	assert(cin);
	return 0;
}
