#include <iostream>
using namespace std;

void printx(){}

template <typename T, typename...type>
void printx(const  T &firstArg, const type&...args)
{
	cout<<firstArg<<" "<<sizeof...(args)<<endl;
	printx(args...);
} 
 
int main()
{
	printx(7.5, 1, 42);
	return 0;
}
