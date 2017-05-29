//display values



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

