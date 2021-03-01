#include <iostream>
#include <functional>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string,function<int(int, int)>> bitops;
	string op;
	int a, b;
	bitops.insert({"+", [](int x, int y){return x+y;}});
	bitops.insert({"-", minus<int>()});
	bitops.insert({"*", multiplies<int>()});
	bitops.insert({"/", divides<int>()});
	bitops.insert({"%", modulus<int>()});
	while(cin>>a>>op>>b)
	{
		cout<<bitops[op](a, b)<<endl;
	}
	return 0;
} 
