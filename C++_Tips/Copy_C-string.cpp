//----------------------------------------------------------------------
//.h file

#include "../stdafx.h"
#include "../std_lib_facilities_v2.h"

namespace Hw18
{
	void print_array(const char* to_print);
	int get_size(const char* ch);
	char* strdup(const char*);
	void exercise_1();
}


//----------------------------------------------------------------------
//.cpp file

#include "stdafx.h"
#include "Homework_18.h"

namespace Hw18
{

	void print_array(const char* to_print)
	{
		while (*to_print)
		{
			cout << *to_print;
			++to_print;
		}
		cout << endl;
	}

	int get_size(const char* ch)
	{
		int n = 0;
		while (*ch) // while (ch[n]) ++n; //Alternatively
		{
			++n;
			++ch;
		}
		return n;
	}

	char* strdup(const char* ch)
	{
		int size = get_size(ch);
		char* to_fill = new char[size + 1]; // WARNING! DO NOT RETURN POINTER TO THE LOCAL VARIABLE, but do I have a choice here?
		int n = 0;
		while (*ch)
		{
			*to_fill = *ch;
			++to_fill;
			++ch;
		}
		*to_fill = 0;
		return to_fill - size;
	}

	void exercise_1()
	{
		char* word = "BirdMANNN PCK";
		char* copyied_word = strdup(word);
		print_array(copyied_word);
	}
}

//----------------------------------------------------------------------
//main()


#include "Rozdzial_18/Homework_18.h"


int main()
{
	try {
		system("chcp 1250");
		Hw18::exercise_1();
		system("pause");

	}

	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		return 2;
	}
	return 0;

}