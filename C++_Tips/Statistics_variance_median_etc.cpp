#include <iostream>
#include<vector>
#include<stdexcept>
#include<cmath>

using std::cout;
using std::vector;
using std::string;
using std::endl;


void error(string message)
{
	throw std::runtime_error(message);
}

int pierwiastek(int liczba)
{
	if (liczba < 0) error("Brak obs³ugi pierwiastka z liczny ujemnej");
	if (liczba == 1) return 1;

	for (int i = 0; i < (liczba / 2) + 1; ++i)
	{
		if (i*i == liczba) return i;
	}

}


template<typename T>
T pow(auto liczba, T potega)
{
	if (potega < 0) error("Nieobslugiwane petego < 0");

	T wynik = liczba;
	for (int i = 1; i < potega; ++i)
	{
		wynik *= liczba;
	}

	return wynik;
}


template<typename T>
T suma(vector<T> elems)
{
	T suma = 0;
	for (int i = 0; i < elems.size(); ++i)
	{
		suma += elems[i];

	}

	return suma;
}


template<typename T>
T srednia(vector<T> elems)
{

	return suma(elems) / elems.size();

}


template<typename T>
T wariancja(vector<T> elems)
{
	double srdna = srednia(elems);
	T wariancja = 0.0;
	for (int i = 0; i < elems.size(); ++i)
	{
		wariancja += pow((elems[i] - srdna), 2);
	}
	return wariancja / elems.size();

}

template<typename T>
double odchylenie_standardowe(vector<T> elems)
{
	return sqrt(wariancja(elems));

}



int main()
{
	vector<int> sample = { 20, 16, 28, 14, 20, 12, 9 };

	cout << wariancja(sample) << endl;
	return 0;
}
