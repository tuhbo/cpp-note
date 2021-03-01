#include <iostream>

using namespace std;

class Quote
{
	public:
		Quote() = default;
		Quote(const string &book, double sales_price):bookNo(book), price(sales_price){}
		string isbn() const {return bookNo;}
		virtual double net_price(size_t n) const
		{
			return n*price;
		}
		virtual ~Quote() = default;
	private:
		string bookNo;
	protected:
		double price = 0.0;
};

class Bulk_quote:public Quote
{
	public:
		Bulk_quote() = default;
		Bulk_quote(const string & book, double p, size_t qty, double disc):Quote(book, p),
			min_qty(qty), discount(disc){}
		double net_price(size_t) const override;
	private:
		size_t  min_qty=0;
		double discount = 0.0;	
};

double Bulk_quote::net_price(size_t cnt) const
{
	if(cnt>=this->min_qty)
		return cnt*(1-discount)*price;
	else
		return cnt*price;
}

int main()
{
	Quote item;
	Bulk_quote item1;
	item = item1;
	Quote &A  = item1;
	Bulk_quote &B = item; 
	return 0;
}
