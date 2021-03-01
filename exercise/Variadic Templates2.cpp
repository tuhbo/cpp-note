#include <iostream>
#include <initializer_list>
using namespace std;

template <typename T>
T maxnum(T n)
{
	return n;
}
template <typename T, typename ... Arg>

T maxnum(T n, Arg ...argv)
{
	return std::max(n, maxnum(argv...));
}

int main()
{
	cout<<maxnum(18, 25, 88, 24, 10);
	return 0;
}
