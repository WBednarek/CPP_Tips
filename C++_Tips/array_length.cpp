int get_array_len(const char* arr)
{
	int length = 0;
	while (arr[length]) // eqivalent of (arr[length] != 0)
	{
		++length;
	}
	return length;
}