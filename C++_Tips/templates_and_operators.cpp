/**
From: http://www.cplusplus.com/forum/general/27198/, retreived 06.04.2018
by m4ster r0shi
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
using namespace std;

template <class T>
class STLContainer
{
private:
	const T * pc;

public:
	STLContainer(const T & c) :pc(&c) {}

	friend ostream & operator<<(ostream & os, STLContainer<T> c)
	{
		typename T::const_iterator it;

		for (it = c.pc->begin(); it != c.pc->end(); it++)
			os << *it << ' ';

		return os;
	}
};

template <class T>
ostream & operator<<(ostream & os, const vector<T> & c)
{
	return os << STLContainer<vector<T> >(c);
}

template <class T>
ostream & operator<<(ostream & os, const deque<T> & c)
{
	return os << STLContainer<deque<T> >(c);
}

template <class T>
ostream & operator<<(ostream & os, const list<T> & c)
{
	return os << STLContainer<list<T> >(c);
}

template <class T>
ostream & operator<<(ostream & os, const set<T> & c)
{
	return os << STLContainer<set<T> >(c);
}

int main()
{
	vector<string> sv;
	deque<string> sd;
	list<string> sl;
	set<string> ss;

	vector<deque<list<set<string> > > > lol;

	cout << sv;
	cout << sd;
	cout << sl;
	cout << ss;

	cout << lol;

	cout << "OMG it works!..." << endl;
	cout << "hit enter to quit..." << endl;
	cin.get();
};