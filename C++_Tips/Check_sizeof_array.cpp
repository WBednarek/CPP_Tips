#include <iostream>

using namespace std;

int main()
{
	int array[] = { 3,-23,53,2,53,24,32 };
	//For instance sizeof(int) = 4, so 7 numbers of sizeof(int) is 28. 
	//For that reason array size is 28 and when it's divided by a size of int, it gives nimber of numbers in array.
	cout << "Array elements: " << sizeof(array) / sizeof(int) << endl;
	//One number size (array[0]) has the same size as int itself.
	cout << "Second method: " << sizeof(array) / sizeof(array[0]) << endl;

	return 0;
}
