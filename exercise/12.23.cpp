#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	const char *s1 = "hello ";
	const char *s2 = "world";
	
	char *s = new char[strlen(s1)+strlen(s2)+2];
	strcpy(s, s1);
	strcat(s, s2);
	cout<<s<<endl;
	
	string c1="hello ", c2="world";
	strcpy(s, (c1+c2).c_str());
	cout<<s;
	return 0;
}
