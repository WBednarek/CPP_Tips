//Wyrównywanie wyœwietlania

/*

funkcja setw() tak jak << hex lub << oct dzia³a przed wpisaniem liczby, czyli najpierw dajemy do strumienia setw(),
a potem liczbê. 
Nie jest ona trwa³a, to znaczy przed kazdym wyœwietleniem liczby jak¹ chcemy sformatowaæ trzeba to zastosowaæ setw()

Przyk³ad 
cout << 12345 << '|' << setw(4) << 12345 << '|' << setw(8) << 12345 << '|' << 12345 << "|\n";

Wyœwietla:
12345|12345|   12345|12345


Aby wyrównaæ tekst do lewej wystarczy dodaæ <<left przed <<setw() np.
cout << "|" << left << setw(14) << "Name" << "|" << setw(14) << "Surname" << "|" << setw(14) << "Phone Number" << "|" << setw(14) << "Email" << "|" << endl;
co wa¿ne left wystarczy dodaæ tylko raz!
*/


//Przyk³ad z tabel¹, przetestowany - dzia³a
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;


void display_table(const vector<string>& names_vec, const vector<string>& surnames_vec, const  vector<string>& phone_numbers_vec, const vector<string>& emails_vec);
void exercise_10();
void error(const string& s);

void exercise_10()
{
	string names[] = { "Jan", "Alicja", "Maciek", "Tomasz", "Patryk" };
	vector<string> names_vec(names, names + sizeof(names) / sizeof(names[0]));

	string surnames[] = { "Omega", "Curus", "Tomaszewski", "Jarowski", "Vege" };
	vector<string> surnames_vec(surnames, surnames + sizeof(surnames) / sizeof(surnames[0]));

	string phone_numbers[] = { "56564155", "5435342", "2463212", "52315", "63246" };
	vector<string> phone_numbers_vec(phone_numbers, phone_numbers + sizeof(phone_numbers) / sizeof(phone_numbers[0]));

	string emails[] = { "wgwegwf@wo.pl", "Alicj@wo.pl", "Maciek@wo.pl", "Tomasz@wo.pl", "Patryk@wo.pl" };
	vector<string> emails_vec(emails, emails + sizeof(emails) / sizeof(emails[0]));


	display_table(names_vec, surnames_vec, phone_numbers_vec, emails_vec);


}

void display_table(const vector<string>& names_vec, const vector<string>& surnames_vec, const  vector<string>& phone_numbers_vec, const vector<string>& emails_vec)
{
	int size1, size2, size3, size4;
	size1 = names_vec.size();
	size2 = surnames_vec.size();
	size3 = phone_numbers_vec.size();
	size4 = emails_vec.size();
	if ((size1 != size2) || (size2 != size3) || (size3 != size4))
	{
		error("Wrong sizes of inputet vectors in order to make an table");
	}
	cout << "|" << left << setw(14) << "Name" << "|" << setw(14) << "Surname" << "|" << setw(14) << "Phone Number" << "|" << setw(14) << "Email" << "|" << endl;


	for (int i = 0; i < names_vec.size(); ++i)
	{
		cout << "|" << left << setw(14) << names_vec[i] << "|" << setw(14) << surnames_vec[i] << "|" << setw(14) << phone_numbers_vec[i] << "|" << setw(14) << emails_vec[i] << "|" << endl;
	}

}

void error(const string& s)
{
	throw std::runtime_error(s);
}

int main()
{
	exercise_10();
	return 0;
}