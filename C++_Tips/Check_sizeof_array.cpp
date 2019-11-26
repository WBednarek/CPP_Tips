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

//When you are passing a C-style array as a parameter, unfortunately, you have to pass its size too, since the name of the array is only the address of its first element.
void copy(int toCopy[], int second[], int size)
{
	/*
	//IT WILL NOT WORK! YOU NEED TO PASS AN ARRAY SIZE AS PARAMETER IN FUNCTION.
	int size1 = sizeof(toCopy) / sizeof(toCopy[0]);
	int size2 = sizeof(second) / sizeof(second[0]);
	if (size1 != size2) error("Sizes of arrays mismatch!");
	*/
	for (int i = 0; i < size; ++i)
	{
		toCopy[i] = second[i];
	}
}