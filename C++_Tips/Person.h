#include <iostream>
#include "std_lib_facilities.h"



class Person
{
	std::string name;
	int age;

public:
	Person();
	Person(std::string name, int age);
	~Person();
	std::string get_name();
	int get_age();

};
