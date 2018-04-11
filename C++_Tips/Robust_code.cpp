
/**
From Stroustrup PPP Chapter 10.6-10.7 slightly modified by me


//Input integer number from low to high
//What to do when int is expected and somone inputs characters (chars or strings)
//!!! FINALLY I sooved how to call function when ENTER is presses
//!!!crucial part:
while (cin >> ch)
{
if (isdigit(ch))
{
cin.unget();
return;
}
if (cin.get() == '\n')
{
cout << "Wci¹¿ to nie by³a liczba" << endl;
}
cin.unget();

}
*/

#include"stdafx.h"
#include<iostream>
#include<stdexcept>




using std::cin;
using std::cout;
using std::endl;
using std::string;


inline void error(const string& s)
{
	throw std::runtime_error(s);
}

//MOja modyfikacja funkcji skip_to_int()
void skip_to_int()
{
	if (cin.fail())
	{
		cin.clear();
		char ch;
		while (cin >> ch)
		{
			if (isdigit(ch))
			{
				cin.unget();
				return;
			}
			if (cin.get() == '\n')
			{
				cout << "Wci¹¿ to nie by³a liczba" << endl;
			}
			cin.unget();

		}
	}
	error("skip_to_int: Stream failed");

}



int get_int()
{
	int n = 0;
	while (true)
	{
		if (cin >> n) return n;
		cout << "Niestety, to nie by³a liczba, Spróboj jeszcze raz" << endl;
		skip_to_int();
	}
}

int get_int(int low, int high)
{
	cout << "Podaj liczbê z zakresu od " << low << " do " << high << endl;

	while (true)
	{
		int n = get_int();

		if (n >= low && n <= high) return n;
		cout << "Niestety, " << n << " nie nale¿y do zakresu " << low << ',' << high
			<< "\nSpróbój jeszze raz" << endl;
	}

}






int main()
{
	system("chcp 1250");
	try {
		const int min = 1;
		const int max = 10;
		int n = get_int(min, max);
		cout << "Sukces wpisana liczba to: " << n << endl;

	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

	system("pause");
	return 0;

}



//My solution
/*
int get_int(int low, int high)
{

int number = -2;
cout << "Podaj liczbê z zakresu od " << low << " do " << high << endl;
while (true)
{
if (cin >> number)
{
if (number >= low && number <= high) return number;
cout << "Liczba spoza zakresu: " << low << " to " << high << endl;
cout << "Spróbuj ponownie" << endl;
}
else
{
skip_to_int();
}

}

return number;

}

*/
