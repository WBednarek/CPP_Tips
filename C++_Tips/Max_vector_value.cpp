int main()
{

	vector<int> testVector = { 2, 343, 2, 1, 1, 324, 1, -32 };
	auto testIterator = *max_element(testVector.begin(), testVector.end());
	//int maxElement = distance(testVector.begin(), testIterator);

	int max1 = testIterator;

	cout << "Max element in the iterator is: " << max1 << endl;
	return 0;
}