#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void
display_str(const vector < string >& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i)
	{
		cout << vec[i] << ", ";
	}
	cout << vec[vec.size() - 1];
}


vector < string > get_unique(const vector < string >& first, const vector < string >& second)
{
	vector < string > unique = first;
	for (int i = 0; i < second.size(); ++i)
	{
		unique.push_back(second[i]);
	}

	sort(unique.begin(), unique.end());

	int counter = 0;
	string tracked = unique[0];
	for (int i = 1; i < unique.size(); ++i)
	{
		if (tracked != unique[i])
		{
			tracked = unique[i];
			++counter;
			unique[counter] = tracked;
		}
	}
	unique.resize(counter + 1);


	return unique;
}


int main()
{

	vector < string > first =
	{
	"Alice", "Brook", "Jon", "Wayne", "Dayne" };

	vector < string > second =
	{
	"Alice", "Brook", "Brook", "Jon", "Dana", "Zachary", "Will", "Ben" };

	display_str(get_unique(first, second));

	return 0;
}
