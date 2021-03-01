#include <iostream>
using namespace std;

class Employee{
	private:
		string name;
		int mysn;
	public:
		Employee():name(""), mysn(sn++){}
		Employee(const string &s)
		{
			mysn = sn++;
			name = s;			
		}
		Employee(const Employee &e)
		{
			name=e.name;
			mysn = sn++;
		}
		Employee & operator =(const Employee &e)
		{
			name = e.name;
			return *this;
		}
		const string & get_name() const
		{
			return name;
		}
		int get_mysn() const
		{
			return mysn;
		}
	private:
		static int sn;
};

int Employee::sn = 0;
void f(const Employee& e)
{
	cout<<e.get_name()<<":"<<e.get_mysn()<<endl;
}
int main()
{
	Employee a("ут"), b = a, c;
	c = b;
	f(a), f(b), f(c);
	return 0;
}
