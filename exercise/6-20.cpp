#include <iostream>
using namespace std;

int main()
{
	string str;
	bool flag = false;
	string prev;
	while(cin>>str)
	{
		if(prev==str)
		{
			flag = true;
			break;
		}
		prev = str;
	}
	if(!flag) cout<<"there is not same words"<<endl;
	else cout<<"there is same words£º"<<str<<endl;
	return 0; 
} 
