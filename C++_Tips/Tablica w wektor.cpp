 //Standardowe rozwiązanie - raczej zalecane
 string nominaly[] = {"jednogroszów", "dwugroszów", "pieciogroszow", "dziesieciogroszów", "dwudziestogroszów", "piedziesiaciogwoszów", "złotówek" };
 vector<string> nominaly_monet(nominaly, nominaly + sizeof(nominaly)/ sizeof(nominaly[0]));
 
 
 
 //Lub moja metoda
 
template<typename T>
vector<T> make_vector_from_array(int input_array_size ,T input_array[])
{
    vector<T> vector_to_make;
    for(int i = 0; i < input_array_size; ++i)
    {
        vector_to_make.push_back(input_array[i]);
    }

    return vector_to_make;
}

//i jej przykładowe wywołanie
 string disliked[] = {"grzyby", "ser żółty", "pieczarki", "jab³ko w miêsie", "œliwka w miêsie", "ma w", "œliwka"};
 int disliked_size = sizeof (disliked) / sizeof(disliked[0]);
 vector<string> disliked_meal;
 disliked_meal = make_vector_from_array<string>(disliked_size, disliked);
