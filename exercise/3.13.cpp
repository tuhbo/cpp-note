#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums(10);
	for(int i=0;i<nums.size();i++)
	{
		cin>>nums[i];
	}
	for(int i=0;i<nums.size();i += 2)
	{
		cout<<nums[i]+nums[i+1]<<endl;
	}
	return 0;
} 
