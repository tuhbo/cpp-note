#include <iostream>
#include <vector>

using namespace std;

vector<int> *new_vector()
{
	return new(nothrow) vector<int>;
}

void read_vector(vector<int> *p)
{
	int c;
	while(cin>>c)
	{
		p->push_back(c);
	}
}

void out_vector(vector<int> *p)
{
	for(auto c:*p)
	{
		cout<<c<<" ";
	}
	delete p;
}

int main()
{
	vector<int> *pc = new_vector();
	if(pc==nullptr)
	{
		cout<<"·ÖÅäÄÚ´æÊ§°Ü"<<endl;
		return -1;
	}
	read_vector(pc);
	out_vector(pc);
	return 0;
}
