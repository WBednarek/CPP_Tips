#include <iostream>
#include <vector>

using namespace std;

void displayVector(std::vector<int> coutVec)
{
	cout << "Vector has following values: ";
	for (std::vector<int>::const_iterator i = coutVec.begin(); i != coutVec.end(); ++i)
	{
		cout << *i << ' ';
	}

	cout << std::endl;
}


int main()
{

	int array[] = { 34,-23,53,2,53,24,32,6848 };
	vector<int> rangeVector(array, array + sizeof(array) / sizeof(int));
	displayVector(rangeVector);
	return 0;
}
