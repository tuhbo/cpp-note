#include "Sales_item.hpp"
#include <iostream>
using namespace std;

int main()
{
	Sales_item total, trans;
	cout<<"Enter some transactions(Ctrl + Z to end):"<<endl;
	if(total.input(cin))
	{
		while(trans.input(cin))
		{
			if(total.same_isbn(trans))
			{
				total=total.add(trans);
			}
			else
			{
				total.output(cout)<<endl;
			}
			total = trans;
		}
		total.output(cout)<<endl;
	}
	else
	{
		cout<<"No data!"<<endl;
		return -1;
	}
	return 0;
}
