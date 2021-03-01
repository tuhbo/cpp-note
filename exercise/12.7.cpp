#include <iostream>
#include <vector>
#include <memory>

using namespace std;

shared_ptr<vector<int>> new_vector()
{
	return make_shared<vector<int>>();
}

void read_vector(shared_ptr<vector<int>> p)
{
	int c;
	while(cin>>c)
	{
		p->push_back(c);
	}
}

void out_vector(shared_ptr<vector<int>> p)
{
	for(auto c:*p)
	{
		cout<<c<<" ";
	}
}

int main()
{
	auto pc = new_vector();
	read_vector(pc);
	out_vector(pc);
	return 0;
}
