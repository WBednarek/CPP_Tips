//namespace has to be indicated as wel in .h and .cpp files.


/**
Date941.h
*/
#pragma once
#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

/*
Stroustrup PPP Chapter 9
Exercise 1 for Date struct form chapter 9.4.1
*/


namespace Date941
{
	struct Date
	{
		int y;
		int m;
		int d;
	};

	void init_day(Date& dd, int y, int m, int d);
	void add_day(Date& dd);
	bool leapyear(int year);
	const int& lapyear_february_days();
	const int& february_days();
}





/**
Date941.cpp
*/
#include "stdafx.h"
#include "Date941.h"


namespace Date941
{

	void init_day(Date& dd, int y, int m, int d)
	{
		const int max_days_num = 31;
		const int max_months_num = 12;
		if (d <= 0 || d > max_days_num) error("error: days number has to be bigger than 0, or less than 32");
		if (m <= 0 || m > max_months_num) error("error: months number has to be bigger than 0, or less than 13");

		switch (m)
		{
		case 4: case 6: case 9: case 11: // Hmm here I have to put everwhere case before int mumber; case 4: 6: 9: 11: doesn't work
		{
			if (d > 30) error("error: to much days for months: April, June, September, November");
			break;
		}
		case 2:
		{
			if (leapyear(y) && d > lapyear_february_days()) error("error: to much days for month: February in lap year (maximimun 29)");
			if (!leapyear(y) && d > february_days()) error("error: to much days for month: February");
			break;
		}
		default:
		{
			break;
		}

		}

		dd.y = y;
		dd.m = m;
		dd.d = d;

	}



	void add_day(Date& dd)
	{
		if (leapyear(dd.y) && dd.m == 2 && dd.d == lapyear_february_days())
		{
			dd.m = 3;
			dd.d = 1;
			return;
		}
		if (!leapyear(dd.y) && (dd.d == february_days() || dd.d == 30 || dd.d == 31))
		{
			if (dd.m != 12)
			{
				dd.m += 1;
				dd.d = 1;
				return;
			}
			else
			{
				dd.y += 1;
				dd.m = 1;
				dd.d = 1;
				return;
			}

		}

		dd.d += 1;

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