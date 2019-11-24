//----------------------------------------------------------------------------------
// .h file

#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

namespace Ex18
{

	struct X
	{
		int val;

		void out(const string& s, int nv)
		{
			cerr << this << "-->" << s << ": " << val << " (" << nv << ")\n";
		}
		X()
		{
			out("X()", 0);
			val = 0;
		}

		X(int v)
		{
			out("X(int)", v);
			val = v;
		}

		X(const X& x)
		{
			out("X(X&)", x.val);
			val = x.val;
		}

		X& operator=(const X& a)
		{
			out("X::operator=()", a.val);
			val = a.val;
			return *this;
		}

		~X()
		{
			out("~X()", 0);
		}
	};

	struct XX
	{
		X a;
		X b;
	};

	void drill_1();
	void drill_2();
}

namespace vec
{
	class vector
	{
		double* elem;
		int sz;
		void copy(const vector& v);
	public:
		vector();
		vector(int s) : sz(s), elem(new double[sz]) { }
		vector(const vector& v) : sz(v.sz), elem(new double[v.sz])
		{
			copy(v);
		}
		double& operator[](int n) { return elem[n]; }
		~vector() { delete[] elem; }
	};
}

//----------------------------------------------------------------------------------
// .cpp file

#include "stdafx.h"
#include "Exercises_18.h"

namespace Ex18
{
	X glob(2);
	X copy(X a) { return a; }
	X copy2(X a)
	{
		X aa = a;
		return aa;
	}
	X& ref_to(X& a) { return a; }

	X* make(int i)
	{
		X a(i);
		return new X(a);
	}

	void drill_1()
	{
		X loc(4);
		X loc2 = loc;
		loc = X(5);
		loc2 = copy(loc);// Two copies are made in case of assignment, one inside a copy() function and the second during an assignment operation (at least I think this is how it works) 
		loc2 = copy2(loc);
		X loc3(6);
		X& r = ref_to(loc);

		delete make(7); // Eqivalent of X* foo = make(7); delete foo;
		delete make(8);
		vector<X> v(4);
		XX loc4;
		X* p = new X(9);
		delete p;
		X* pp = new X[5];
		delete[] pp;
	}

	void drill_2()
	{
		vec::vector v(3);
		int x = v[2];
		v[1] = 5;
		cout << v[1] << endl;
	}

}

namespace vec
{
	void vector::copy(const vector& v)
	{
		for (int i = 0; i < v.sz; ++i)
		{
			elem[i] = v.elem[i];
		}

	}
}


//----------------------------------------------------------------------------------
// main()


#include "stdafx.h"
#include "std_lib_facilities_v2.h"
#include "Rozdzial_18/Exercises_18.h"


int main()
{
	try {
		system("chcp 1250");
		Ex18::drill_2();
		system("pause");
	}

	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		return 2;
	}
	return 0;

}



