#include<sstream> 
#include<string>
#include<stdexcept> 
#include <iostream>


inline void error(const std::string& s)
{
	throw std::runtime_error(s);
}



long long fct(int n)
{
	if (n > 19) error("to big number for long long type, use number less than 20");
	int num = 1;
	for (int i = 1; i < n + 1; ++i)
	{
		num *= i;
	}


	return num;
}

int fac_Stroustrup(int n)
{
	int r = 1;
	while (n > 1)
	{
		r *= n;
		--n;
	}
	return r;
}


void fill_array_with_fct(int to_fill[], int n)
{
	if (n > 19) error("Factorial is too big");
	int fact = 1;
	to_fill[0] = fact;
	for (int i = 1; i < n; ++i)
	{
		fact *= i;
		to_fill[i] = fact;
	}
}


int main()
{
	std::cout << fct(15) << std::endl;
	std::cout << fac_Stroustrup(15) << std::endl;
}