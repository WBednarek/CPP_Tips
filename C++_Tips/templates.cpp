//Praca_domowa.h
template<typename T>
bool vector_contains(vector<T> & input, T number);




//Praca_domowa.cpp
template<typename T>
bool vector_contains(vector<T> & input, T number)
{
	bool contains = false;
	for (int i : input)
	{
		if (i == number) contains = true;
	}
	return contains;
}
