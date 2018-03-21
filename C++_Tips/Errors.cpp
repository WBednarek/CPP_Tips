/*
std_lib_facilities.h
Stroustrup Programming: Principles and Practice using C++ (second edition) book.
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



#include<sstream> // For std::ostringstream
#include<string>
#include<stdexcept> // I don't know if it is needed for std::runtime_error(s). It's maybye like string which works without including <string>. 
//Ok as i checked on https://www.onlinegdb.com/online_c++_compiler it is needed.



// error() simply disguises throws:
inline void error(const std::string& s)
{
	throw std::runtime_error(s);
}

inline void error(const std::string& s, const std::string& s2)
{
	error(s + s2);
}

inline void error(const std::string& s, int i)
{
	std::ostringstream os;
	os << s << ": " << i;
	error(os.str());
}
