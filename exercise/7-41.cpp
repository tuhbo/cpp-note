#include <iostream>
#include <string>
using namespace std;

class Sales_data{
	friend istream &read (istream &is, Sales_data &item);
	friend ostream &print(ostream &os, const Sales_data &item);
	private:
		string bookNo;
		unsigned units_sold = 0;
		double sellingprice = 0.0;
		double sallprice = 0.0;
		double discount = 0.0;
	public:
		Sales_data(const string &book, unsigned num, double sellp, double salep):bookNo(book),
		units_sold(num), sellingprice(sellp), sallprice(salep)
		{
			if(sellingprice)
			{
				discount = sallprice / sellingprice;
				cout<<"该构造函数接受书号、销售量、原价实际售价四个信息"<<endl; 
			}
		}
		Sales_data():Sales_data("", 0, 0, 0)
		{
			cout<<"该构造函数无须接受任何信息"<<endl;
		}
		Sales_data(const string &book):Sales_data(book, 0, 0, 0)
		{
			cout<<"该构造函数接受书号的信息"<<endl;
		}
		Sales_data(istream &is):Sales_data()
		{
			read(is, *this);
			cout<<"该构造函数接受用户输入的信息"<<endl;
		} 
};

istream &read(istream &is, Sales_data &item)
{
	is>>item.bookNo>>item.units_sold>>item.sellingprice>>item.sallprice;
	return is;
}
ostream &print(ostream &os, const Sales_data &item)
{
	os<<item.bookNo<<" "<<item.units_sold<<" "<<item.sellingprice<<" "<<item.sallprice<<item.discount;
	return os;
}

int main()
{
	Sales_data first("978-7-121-15535-2", 85, 128, 109);
	Sales_data second;
	Sales_data third("978-7-121-15535-2");
	Sales_data last(cin);
	return 0;
}
