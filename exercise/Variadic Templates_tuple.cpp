#include <iostream>
using namespace std;

template <typename... Values> class _tuple;
template <> class _tuple<>{};
template <typename Head, typename... Tail>
class _tuple <Head, Tail...>:private _tuple<Tail...>
{
	typedef _tuple<Tail...> inherited;
	public:
		_tuple(){}
		_tuple(Head v, Tail... vtail):m_head(v), inherited(vtail...)
		{
			
		}
		Head head()
		{
			return m_head;
		}
		inherited & tail()
		{
			return *this;
		}
	protected:
		Head m_head;
};

int main()
{
	_tuple<int, float, string> t(41, 6.3, "nico");
	cout<<sizeof(t)<<endl;
	cout<<t.head()<<endl;
	cout<<t.tail().head()<<endl;
	cout<<t.tail().tail().head()<<endl;
	return 0;
}
