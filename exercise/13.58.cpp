#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Foo{
	private:
		vector<int> data;
	public:
//		Foo sorted();
		Foo sorted() const ;
};

//Foo Foo::sorted()
//{
//	cout<<"右值引用版本"<<endl;
//	sort(data.begin(), data.end());
//	return *this;
//}

Foo Foo::sorted() const  
{
	cout<<"左值引用版本"<<endl;
	return *this;
}

int main()
{
	const Foo f;
	f.sorted();
	Foo().sorted(); 
	return 0;
}
