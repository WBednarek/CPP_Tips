#include "Person.h"


Person::Person()
{
}

Person::Person(std::string name, int age) : name(name), age(age)
{
}


Person::~Person()
{
}

std::string Person::get_name()
{
	if (name == "") error("There is no name");
	return name;
}

int Person::get_age()
{
	if (age > 120 || age <0) error("Probably wrong age");
	return age;
}

