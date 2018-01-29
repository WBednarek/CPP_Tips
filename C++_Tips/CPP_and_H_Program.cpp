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
!!! For some reason, variable Token_stream ts has to be in .cpp file,
not in .h.
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

