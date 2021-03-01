#include <iostream>
using namespace std;

using int_arry = int[4];
int main()
{
	int ia[3][4]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	for(int_arry &row:ia)
	{
		for(int col:row)
		{
			cout<<col<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i!=3;i++)
	{
		for(int j=0;j<4;j++)
			cout<<ia[i][j]<<" ";
		cout<<endl;
	}
	for(int_arry *p=ia;p!=ia+3;p++)
	{
		for(int *q=*p;q!=*p+4;q++)
			cout<<*q<<" ";
		cout<<endl;
	}
	return 0;
}
