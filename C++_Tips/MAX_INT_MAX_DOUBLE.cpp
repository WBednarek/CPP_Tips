//The lowest and the highest value, C++ style, 
//You ma need to #include <limits>
//For numeric_limits<double>::min() program doesn't work properly, for some reason the value is positive
int min = numeric_limits<int>::min();
int high = numeric_limits<int>::max(); 

double low_temp = numeric_limits<double>::min();
double high_temp = numeric_limits<double>::max();






//The lowest and the highest value, C style,
//You may need to #include <limits.h>
//#include <cfloat> for DBL_MAX and DBL_MIN
int low = INT_MAX;
int high = INT_MIN;

double low_temp = DBL_MAX;
double high_temp = DBL_MIN;






/**
See http://www.cplusplus.com/reference/climits/


Macro constants
name	expresses	value*
CHAR_BIT	Number of bits in a char object (byte)	8 or greater*
SCHAR_MIN	Minimum value for an object of type signed char	-127 (-27+1) or less*
SCHAR_MAX	Maximum value for an object of type signed char	127 (27-1) or greater*
UCHAR_MAX	Maximum value for an object of type unsigned char	255 (28-1) or greater*
CHAR_MIN	Minimum value for an object of type char	either SCHAR_MIN or 0
CHAR_MAX	Maximum value for an object of type char	either SCHAR_MAX or UCHAR_MAX
MB_LEN_MAX	Maximum number of bytes in a multibyte character, for any locale	1 or greater*
SHRT_MIN	Minimum value for an object of type short int	-32767 (-215+1) or less*
SHRT_MAX	Maximum value for an object of type short int	32767 (215-1) or greater*
USHRT_MAX	Maximum value for an object of type unsigned short int	65535 (216-1) or greater*
INT_MIN	Minimum value for an object of type int	-32767 (-215+1) or less*
INT_MAX	Maximum value for an object of type int	32767 (215-1) or greater*
UINT_MAX	Maximum value for an object of type unsigned int	65535 (216-1) or greater*
LONG_MIN	Minimum value for an object of type long int	-2147483647 (-231+1) or less*
LONG_MAX	Maximum value for an object of type long int	2147483647 (231-1) or greater*
ULONG_MAX	Maximum value for an object of type unsigned long int	4294967295 (232-1) or greater*
LLONG_MIN	Minimum value for an object of type long long int	-9223372036854775807 (-263+1) or less*
LLONG_MAX	Maximum value for an object of type long long int	9223372036854775807 (263-1) or greater*
ULLONG_MAX	Maximum value for an object of type unsigned long long int	18446744073709551615 (264-1) or greater*



Also see http://www.cplusplus.com/reference/cfloat/ for floating (and double) types



*/
