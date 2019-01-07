//Doesn't work on visual studio "stdafx.h" error ocurs. 
//But code is validated in other IDE (https://www.onlinegdb.com/online_c++_compiler#) and works properly.

#include "Person.h"
#include <ostream>
#include<stdexcept>
#include<iostream>


std::ostream& operator<<(std::ostream & os, Person & p)
{
	return os << "Name: " << p.get_name() << std::endl
		<< "Age: " << p.get_age() << std::endl;
}


int main()
{
	Person goofy("Goofy", 63);
	std::cout << goofy;
	return 0;
}

