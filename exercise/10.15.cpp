#include <iostream>
using namespace std;

void add(int a)
{
	auto sum = [a](int b)->int{return a+b;};
	cout<<sum(1)<<endl;
}

int main()
{
	add(1);
	add(2);
	return 0;
}
