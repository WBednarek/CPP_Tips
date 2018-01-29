//------------------------------------------------------------------------------
/**
calculator.h

*/

//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "stdafx.h"
#include "std_lib_facilities_v2.h"

//------------------------------------------------------------------------------

class Token {
public:
	char kind;        // what kind of token
	double value;     // for numbers: a value 
	Token(char ch);    // make a Token from a char
	Token(char ch, double val);     // make a Token from a char and a double
};

class Token_stream
{
public:
	Token_stream();
	Token get();
	void putback(Token t);

private:
	bool full;
	Token buffer;

};

Token get_token();
double expression();  // read and evaluate a Expression
double term();        // read and evaluate a Term
double primary();
int wyproboj_6_9();







//------------------------------------------------------------------------------
/**
calculator.cpp

*/

//
// This is example code from Chapter 6.6 "Trying the first version" of
// "Software - Principles and Practice using C++" by Bjarne Stroustrup
//

#include "stdafx.h"
#include "caclulator.h"

/**
!!! For some reason, variable Token_stream ts has to be in the .cpp file,
not in the .h.
*/
Token_stream ts; //!!!

Token::Token(char ch)    // make a Token from a char
	:kind(ch), value(0) { }

Token::Token(char ch, double val)
	: kind(ch), value(val) {} // make a Token from a char and a double

							  //------------------------------------------------------------------------------

Token get_token()    // read a token from cin
{
	char ch;
	cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

	switch (ch) {

	case ';': case 'k':
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token(ch);        // let each character represent itself
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);         // put digit back into the input stream
		double val;
		cin >> val;              // read a floating-point number
		return Token('8', val);   // let '8' represent "a number"
	}
	default:
		error("Bad token");
	}
}

//------------------------------------------------------------------------------

double expression()
{
	double left = term();      // read and evaluate a Term
	Token t = ts.get();     // get the next token
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();    // evaluate Term and add
			t = ts.get();
			break;
		case '-':
			left -= term();    // evaluate Term and subtract
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;       // finally: no more + or -: return the answer
		}
	}
}

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	Token t = ts.get();     // get the next token

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double primary()     // read and evaluate a Primary
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':    // handle '(' expression ')'
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;
	}
	case '8':            // we use '8' to represent a number
		return t.value;  // return the number's value
	default:
		error("primary expected");
	}
}

//------------------------------------------------------------------------------

int wyproboj_6_9()
{
	try {
		cout << "Insert expression" << endl;
		double val = 0;
		while (cin)
		{
			Token t = ts.get();
			if (t.kind == 'k') break;
			if (t.kind == ';') cout << "=" << val << '\n';
			else
			{
				ts.putback(t);
				val = expression();
			}
		}

		keep_window_open("~0");
	}
	catch (exception& e) {
		cerr << e.what() << endl;
		keep_window_open("~1");
		return 1;
	}
	catch (...) {
		cerr << "exception \n";
		keep_window_open("~2");
		return 2;
	}


}

//------------------------------------------------------------------------------

Token_stream::Token_stream() :full(false), buffer(0)
{

}

void Token_stream::putback(Token t)
{
	if (full) error("Wywo³anie funkcji putback(), gdy bufor jest pe³ny");
	buffer = t;
	full = true;
}

//------------------------------------------------------------------------------

Token Token_stream::get()
{
	if (full)
	{
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;
	switch (ch)
	{
	case ';':
	case 'k':
	case '(': case ')': case '+': case '-': case '*': case '/': case '%':
	{
		return Token(ch);
	}
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5':  case '6': case '7': case '8': case '9':
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	}

	default:
		error("Nieprawid³owy token.");
	}
}






//------------------------------------------------------------------------------
/**
main.cpp

*/


// CPP_and_H_Program.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "caclulator.h"


int main()
{
	wyproboj_6_9();
    return 0;
}







//------------------------------------------------------------------------------
/**
   std_lib_facilities_v2.h
*/

/*
	simple "Programming: Principles and Practice using C++ (second edition)" course header to
	be used for the first few weeks.
	It provides the most common standard headers (in the global namespace)
	and minimal exception/error support.

	Students: please don't try to understand the details of headers just yet.
	All will be explained. This header is primarily used so that you don't have
	to understand every concept all at once.

	By Chapter 10, you don't need this file and after Chapter 21, you'll understand it

	Revised April 25, 2010: simple_error() added
	
	Revised November 25 2013: remove support for pre-C++11 compilers, use C++11: <chrono>
	Revised November 28 2013: add a few container algorithms
	Revised June 8 2014: added #ifndef to workaround Microsoft C++11 weakness
*/

#ifndef H112
#define H112 251113L


#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>

//------------------------------------------------------------------------------


//------------------------------------------------------------------------------

typedef long Unicode;

//------------------------------------------------------------------------------

using namespace std;

template<class T> string to_string(const T& t)
{
	ostringstream os;
	os << t;
	return os.str();
}

struct Range_error : out_of_range {	// enhanced vector range error reporting
	int index;
	Range_error(int i) :out_of_range("Range error: "+to_string(i)), index(i) { }
};


// trivially range-checked vector (no iterator checking):
template< class T> struct Vector : public std::vector<T> {
	using size_type = typename std::vector<T>::size_type;

#ifdef _MSC_VER
	// microsoft doesn't yet support C++11 inheriting constructors
	Vector() { }
	explicit Vector(size_type n) :std::vector<T>(n) {}
	Vector(size_type n, const T& v) :std::vector<T>(n,v) {}
	template <class I>
	Vector(I first, I last) : std::vector<T>(first, last) {}
	Vector(initializer_list<T> list) : std::vector<T>(list) {}
#else
	using std::vector<T>::vector;	// inheriting constructor
#endif

	T& operator[](unsigned int i) // rather than return at(i);
	{
		if (i<0||this->size()<=i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
	const T& operator[](unsigned int i) const
	{
		if (i<0||this->size()<=i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
};

// disgusting macro hack to get a range checked vector:
#define vector Vector

// trivially range-checked string (no iterator checking):
struct String : std::string {
	using size_type = std::string::size_type;
//	using string::string;

	char& operator[](unsigned int i) // rather than return at(i);
	{
		if (i<0||size()<=i) throw Range_error(i);
		return std::string::operator[](i);
	}

	const char& operator[](unsigned int i) const
	{
		if (i<0||size()<=i) throw Range_error(i);
		return std::string::operator[](i);
	}
};


namespace std {

    template<> struct hash<String>
    {
        size_t operator()(const String& s) const
        {
            return hash<std::string>()(s);
        }
    };

} // of namespace std


struct Exit : runtime_error {
	Exit(): runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s+s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s <<": " << i;
	error(os.str());
}


template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}


inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s=="") return;
	cin.clear();
	cin.ignore(120,'\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss!=s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}



// error function to be used (only) until error() is introduced in Chapter 5:
inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

// make std::min() and std::max() accessible on systems with antisocial macros:
#undef min
#undef max


// run-time checked narrowing cast (type conversion). See ???.
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r)!=a) error(string("info loss"));
	return r;
}

// random number generators. See 24.7.



inline int randint(int min, int max) { static default_random_engine ran; return uniform_int_distribution<>{min, max}(ran); }

inline int randint(int max) { return randint(0, max); }

//inline double sqrt(int x) { return sqrt(double(x)); }	// to match C++0x

// container algorithms. See 21.9.

template<typename C>
using Value_type = typename C::value_type;

template<typename C>
using Iterator = typename C::iterator;

template<typename C>
	// requires Container<C>()
void sort(C& c)
{
	std::sort(c.begin(), c.end());
}

template<typename C, typename Pred>
// requires Container<C>() && Binary_Predicate<Value_type<C>>()
void sort(C& c, Pred p)
{
	std::sort(c.begin(), c.end(), p);
}

template<typename C, typename Val>
	// requires Container<C>() && Equality_comparable<C,Val>()
Iterator<C> find(C& c, Val v)
{
	return std::find(c.begin(), c.end(), v);
}

template<typename C, typename Pred>
// requires Container<C>() && Predicate<Pred,Value_type<C>>()
Iterator<C> find_if(C& c, Pred p)
{
	return std::find_if(c.begin(), c.end(), p);
}

#endif //H112
