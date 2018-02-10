//Method 1
void displayVector(std::vector<int> coutVec)
{
	cout << "Vector has following values: ";
	for (std::vector<int>::const_iterator i = coutVec.begin(); i != coutVec.end(); ++i)
	{
		cout << *i << ' ';
	}

	cout << std::endl;
}


//Method 2
template<typename T>
void display_vector(vector<T> & to_disp)
{
	for (T disp : to_disp)
	{
		cout << disp << " ";
	}
}


//Method 3
/**
@brief Overloaded operator << in order to display vector in cout

@param Output stream which  represents  all vector's elements to display
@param Input vector that meant to be displayed

@return Output stream which represents all vector's elements to display
*/
template<typename T>
ostream & operator<< (ostream & output, vector<T> & to_disp)
{
	for (T disp : to_disp)
	{
		output << disp << " ";
	}
	return output;
}