//Const za nazwą funkcji
//Ze Stroustrupa Programowanie
//Słowo kluczowe const za listą argumentów w deklaracji funkcji składowej oznacza  , że funkcję tę można wywołać na rzecz stałych obiektów, jeśli  funkcja składowa zostanie zdefiniowana jako stała kompilator będzie wymuszał na nas spełnienie obietnicy, że nie zmodyfikujemy obiektów. Na przykład:
int Date::day() const
{
++d; //  Błąd próba zmodyfikowania obiektu za pomocą stałej funkcji składowej.
return d;
}

//Const przed nazwą funkcji
const double PI(); // funkcja zwraca stałą


//Const w parametrze fucncji
string nazwa(const &str)
{
// Nie można edytować parametru str
} 
