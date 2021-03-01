#include <iostream>
#include "StrVec.h"
using namespace std;

int main()
{
	StrVec vec = {"hello", "world"}, vec2={"1", "2", "3", "4", "5"};
	cout<<vec.size()<<" "<<vec.capacity()<<endl;
	cout<<vec2.size()<<" "<<vec2.capacity()<<endl;
	vec.reserve(50); 
	cout<<vec.size()<<" "<<vec.capacity()<<endl;
	vec = vec2;
	cout<<vec.size()<<" "<<vec.capacity()<<endl;
	return 0;
}
