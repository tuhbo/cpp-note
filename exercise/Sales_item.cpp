#include "Sales_item.hpp"
using namespace std;
istream & Sales_item::input(istream& in)
{
	double price;
	in>>isbn>>units_sold>>price;
	if(in)
	{
		revenue = units_sold*price;
	}
	else
	{
		units_sold =0;
		revenue = 0.0;
	}
	return in;
}
double Sales_item::avg_price() const
{
	if(units_sold)
		return revenue/units_sold;
	else
		return 0;
}
ostream &Sales_item::output(ostream &out) const
{
	out<<isbn<<"\t"<<units_sold<<"\t"<<revenue<<"\t"<<avg_price();
	return out;
}
Sales_item Sales_item::add(Sales_item &other)
{
	revenue += other.revenue;
	units_sold += other.units_sold;
	return *this;
}
