#include <exception>

try
{


}
catch (std::exception & e)
{
	std::cout << "Standard exception: " << e.what() << std::endl;
}
