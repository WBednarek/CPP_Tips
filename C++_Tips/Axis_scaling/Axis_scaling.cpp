//
// This is example code from Chapter 15.6.1 "Reading a file" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#include "Simple_window.h"  // get access to our window library
#include "Graph.h"          // get access to our graphics library facilities
#include "std_lib_facilities.h"

//------------------------------------------------------------------------------

class Scale {                // data value to coordinate conversion
	int cbase;               // coordinate base
	int vbase;               // base of values
	double scale;
public:
	Scale(int b, int vb, double s) :cbase(b), vbase(vb), scale(s) { }
	int operator()(int v) const { return cbase + (v - vbase)*scale; }

	/*
	Description
	For a more detailed description see the images 1.jpg, 2,jpg, book_1.jpg, book_2.jpg

	const int base_year = 1960;
	const int end_year = 2040;
	const double xscale
		= double(xlength) / (end_year - base_year); // assume for easier compuation xlength = 1000. Here (end_year - base_year) = 80, so xscale = 12,5;	
	
	base is offset starting from the right side of our window
	vbase to base_year = 1960, is the first value of x axis, the most often (in other cases) it would be 0
	scale = 12,5 so shifting by one year in our range (1960;2040) in reality we are shifting by 12,5 unit in our window



	cbase to offset od prawej strony naszego okna
	vbase to base_year = 1960, czyli pierwsza wartoœæ na osi x, najczêsciej (w innych przypadkach) by³oby to 0
	scale = 12,5 czyli przesuwaj¹c siê o 1 rok w przedziale (1960;2040) tak naprawdê przesuwamy siê 0 12,5 jednostki w namysz oknie
	*/
};	

//------------------------------------------------------------------------------

int main()
try
{
	const int xmax = 600;    // window size
	const int ymax = 400;

	const int xoffset = 100; // distance from left hand side of window to y axis
	const int yoffset = 60;  // distance from bottom of window to x axis

	const int xspace = 40;   // space beyond axis
	const int yspace = 40;

	const int xlength = xmax - xoffset - xspace;    // length of axes
	const int ylength = ymax - yoffset - yspace;

	const int base_year = 1960;
	const int end_year = 2040;

	const double xscale
		= double(xlength) / (end_year - base_year); // assume for easier compuation xlength = 1000. Here (end_year - base_year) = 80, so xscale = 12,5;
	const double yscale = double(ylength) / 100;  // scale of y values 

	Scale xs(xoffset, base_year, xscale);
	Scale ys(ymax - yoffset, 0, -yscale);

	