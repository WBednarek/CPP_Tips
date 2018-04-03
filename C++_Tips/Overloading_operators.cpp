//Overloading operators in .h and .cpp files. 
//In this example, I overload an operator for enum in class which is in the namespace.
//Only in .cpp file operator overload definition is needed.



/**
Date971.h

*/


#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9
Exercise 1 for Date class form chapter 9.7.1

*/


namespace Date971
{
	class Year
	{
		static const int min = 1800;
		static const int max = 2200;
	public:
		class Invalid { };
		Year();
		Year(int x) : y(x) { if (x < min || x > max) throw Invalid(); }
		int year() { return y; }
	private:
		int y;
	};



	class Date
	{
	public:
		enum Month
		{
			jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
		};
		Date(Year year, Month month, int d);
		void add_day(int n);
		int month() { return m; }
		int day() { return d; }
		int year() { return y.year(); }
	private:
		Year y;
		Month m;
		int d;

	};

	bool leapyear(int year);
	const int& lapyear_february_days();
	const int& february_days();
}

/**
Date971.cpp

*/

#include "stdafx.h"
#include "Date971.h"


namespace Date971
{

	Date::Month operator+(Date::Month& m, Date::Month& m1)// eg. feb + feb
	{
		Date::Month result;
		result = Date::Month(((m + m1) % 13) + 1);
		return result;
	}

	Date::Month operator+(Date::Month& m, int m1)
	{
		Date::Month result;
		result = Date::Month(((m + m1) % 13) + 1);
		return result;
	}

	Date::Month operator+=(Date::Month& m, int m1)
	{
		Date::Month result;
		result = Date::Month(((m + m1) % 13) + 1);
		return result;
	}

	Year operator+=(Year& y, int y1)
	{
		return (Year(y.year() + y1));
	}



	Year::Year() : y(2001)
	{
	}


	Date::Date(Year year, Month month, int day)
	{
		const int max_days_num = 31;
		const int max_months_num = 12;
		if (day <= 0 || day > max_days_num) error("error: days number has to be bigger than 0, or less than 32");
		if (month <= 0 || month > max_months_num) error("error: months number has to be bigger than 0, or less than 13");

		switch (month)
		{
		case apr: case jun: case sep: case nov:
		{
			if (day > 30) error("error: to much days for months: April, June, September, November");
			break;
		}
		case feb:
		{
			if (leapyear(year.year()) && day > lapyear_february_days()) error("error: to much days for month: February in lap year (maximimun 29)");
			if (!leapyear(year.year()) && day > february_days()) error("error: to much days for month: February");
			break;
		}
		default:
		{
			break;
		}

		}

		y = year;
		m = month;
		d = day;

	}



	void Date::add_day(int n)
	{
		if (n < 1) error("error: add positive mumber of day (more than 0)");
		if (leapyear(y.year()) && m == feb && d == lapyear_february_days())
		{
			m = mar;
			d = n;
			return;
		}
		if (!leapyear(y.year()) && (d == february_days() || d == 30 || d == 31))
		{
			if (m != dec)
			{
				m += 1;
				d = n;
				return;
			}
			else
			{
				y += 1;
				m = jan;
				d = n;
				return;
			}

		}

		d += n;

	}


	bool leapyear(int year)
	{
		if (year % 4 == 0) return true;
		return false;
	}

	const int& lapyear_february_days()
	{
		static int lapyear_feb_days = 29;
		return lapyear_feb_days;
	}

	const int& february_days()
	{
		static int days_in_feb = 28;
		return days_in_feb;
	}

}

