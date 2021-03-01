#include <iostream>
#include <vector>
using namespace std;

struct X{
	X(){
		cout<<"X()"<<endl;
	}
	X(const X&)
	{
		cout<<"X(const X&)"<<endl;
	}
	X& operator=(const X& rhs)
	{
		cout<<"拷贝赋值运算符 =(const X&)"<<endl;
		return *this;
	}
	void operator delete(void *p)
	{
		cout<<"释放对象"<<endl;
	}
};
void f1(X x)
{
	
}
void f2(X &x)
{
		
}

int main()
{
	cout<<"局部变量："<<endl;
	X x;
	cout<<endl;
	
	cout<<"非引用参数传递: "<<endl;
	f1(x);
	cout<<endl;
	cout<<"引用参数传递: "<<endl;
	f2(x);
	cout<<endl;
	
	cout<<"动态分配: "<<endl;
	X *px = new X;
	
	cout<<"添加到容器: "<<endl;
	vector<X> vx;
	vx.push_back(x);
	cout<<endl;
	
	cout<<"释放动态分配对象: "<<endl;
	delete px;
	cout<<endl;
	
	cout<<"间接初始化和赋值: "<<endl;
	X y = x;
	y = x;
	
	cout<<"程序结束"<<endl;
	return 0;
}
