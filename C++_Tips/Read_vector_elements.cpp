//displays values and saves it to file named output2.txt
//add #include <fstream>



void displayValues(std::vector<int> dataVec)
{

std::ofstream data("output2.txt");
if (data.is_open())
{
data << "JA has folllowing values: ";
for (std::vector<int>::const_iterator i = dataVec.begin(); i != dataVec.end(); ++i)
{
data << *i << ' ';
}

data << std::endl;

}

}


//Displays vector to the console
void displayVector(std::vector<int> coutVec)
{
	cout << "Vector has following values: ";
	for (std::vector<int>::const_iterator i = coutVec.begin(); i != coutVec.end(); ++i)
	{
		cout << *i << ' ';
	}

	cout << std::endl;
}
