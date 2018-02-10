template<typename T>
vector<T> random_vector()
{
	//In ASCII a-z letters are numerically 97-122.
	int a_ASCII = 97;
	int z_ASCII = 122;

	unsigned word_to_guess_length = 4;
	vector<T> random_vector(word_to_guess_length);

	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);
	uniform_int_distribution<int> dist(a_ASCII, z_ASCII);

	for (int i = 0; i < word_to_guess_length; ++i)
	{
		random_vector[i] = dist(generator);
	}

	return random_vector;
}
