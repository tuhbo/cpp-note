#include <iostream>
#include <vector>
using namespace std;
typedef int (*fun)(int a, int b);

int fun1(int a, int b)
{
	return a+b;
}
int fun2(int a, int b)
{
	return a-b;
}
int fun3(int a, int b)
{
	return a*b;
}
int fun4(int a, int b)
{
	return a/b;
}
void compute(int a, int b, fun p)
{
	cout<<p(a, b)<<endl;
}
int main()
{
	int i=5, j=10;
	vector<fun > vf = {fun1, fun2, fun3, fun4};
	for(auto p:vf)
	{
		compute(i, j, p);
	}
	return 0;
}
