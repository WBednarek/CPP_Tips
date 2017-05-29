#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	// an array with 5 elements.
	double balance[5] = { 1000.0, 2.0, 3.4, 17.0, 50.0 };
	double *p;

	p = balance;

	int balanceLength = sizeof(balance) / sizeof(balance[0]);
	cout << "Balance size is: " << balanceLength << endl;

	// output each array element's value 
	cout << "Array values using pointer " << endl;

	for (int i = 0; i < 5; i++) {
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}

	cout << "Array values using balance as address " << endl;

	for (int i = 0; i < 5; i++) {
		cout << "*(balance + " << i << ") : ";
		cout << *(balance + i) << endl;
	}


	system("pause");
	return 0;
}