#include <iostream>
#include <vector>
using namespace std;

class PrintString{
	private:
		istream &in;
	public:
		PrintString(istream &is):in(cin){}
		vector<string>  operator()(vector<string> &vec)
		{
			string str;
			while(in>>str)
			{
				vec.push_back(str);
			}
			return vec;
		}
};
int main()
{
	vector<string> vec;
	PrintString print(cin);
	print(vec);
	for(auto s:vec) cout<<s;
	return 0;
} 
