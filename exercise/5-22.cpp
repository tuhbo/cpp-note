#include <iostream>
using namespace std;


int main()
{
	cout << "bool: " << sizeof(bool) <<'\n' 
		<< "char: " << sizeof(char) << '\n'
		<< "wchar_t: " << sizeof(wchar_t) <<'\n'
		<< "short: " << sizeof(short) <<'\n'
		<< "int: " << sizeof(int) <<'\n'
		<< "long: " << sizeof(long) << '\n'
		<< "float: " << sizeof(float) <<'\n'
		<< "double: " << sizeof(double) <<'\n'
		<< "long double: " << sizeof(long double) << endl;
	return 0;
}
