//!!! CRUCIAL LINE if (cin.get() == '\n') 

#include "stdafx.h"
#include<iostream>

using std::cin;
using std::cout;
using std::endl;



void non_a_number()
{
	if (cin.fail())
	{
		cin.clear();
		cout << "To nie by�a liczba" << endl;
		cout << "Spr�buj ponownie" << endl;
		char ch;
		while (cin >> ch)
		{
			if (isdigit(ch))
			{
				cin.unget();
				break;
			}
			if (cin.get() == '\n') //!!! CRUCIAL LINE
			{
				cout << "Wcia� to nie jest liczba" << endl;
			}
			cin.unget();
		}
	}
}


int main()
{
	system("chcp 1250");
	cout << "Wprowad� jak�kolwiek liczb�" << endl;
	int number = -17;
	while (true)
	{
		if (cin >> number)
		{
			cout << "Wprowadziles liczb�: " << number << endl;
			cout << "Koniec programu" << endl;
			break;

		}
		non_a_number();

	}
	system("pause");

	return 0;
}