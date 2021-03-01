#include <iostream>
using namespace std;

class PrintString{
	private:
		istream &in;
	public:
		PrintString(istream &is):in(cin){}
		string  operator()( string &s)
		{
			in>>s;
			if(in) return s;
			return "";
		}
};
int main()
{
	string str;
	PrintString print(cin);
	cout<<print(str);
	return 0;
} 
