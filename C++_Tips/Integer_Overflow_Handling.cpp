/**
From: https://wiki.sei.cmu.edu/confluence/display/c/INT32-C.+Ensure+that+operations+on+signed+integers+do+not+result+in+overflow, 
accessed 03.03.2018
*/


/*
Multiplication 2 - better

!I think it may be used as well on long types!

Multiplication is between two operands of arithmetic type.

Compliant Solution 2
The following portable compliant solution can be used with any conforming implementation,
including those that do not have an integer type that is at least twice the precision of int:
*/

//Multiplication 2
#include <limits.h>

void func(signed int si_a, signed int si_b) {
	signed int result;
	if (si_a > 0) {  /* si_a is positive */
		if (si_b > 0) {  /* si_a and si_b are positive */
			if (si_a > (INT_MAX / si_b)) {
				/* Handle error */
			}
		}
		else { /* si_a positive, si_b nonpositive */
			if (si_b < (INT_MIN / si_a)) {
				/* Handle error */
			}
		} /* si_a positive, si_b nonpositive */
	}
	else { /* si_a is nonpositive */
		if (si_b > 0) { /* si_a is nonpositive, si_b is positive */
			if (si_a < (INT_MIN / si_b)) {
				/* Handle error */
			}
		}
		else { /* si_a and si_b are nonpositive */
			if ((si_a != 0) && (si_b < (INT_MAX / si_a))) {
				/* Handle error */
			}
		} /* End if si_a and si_b are nonpositive */
	} /* End if si_a is nonpositive */

	result = si_a * si_b;
}



/*
Multiplication 1

Multiplication is between two operands of arithmetic type.

Compliant Solution 1
The product of two operands can always be represented using twice the number of bits than exist in the precision of the larger of the two operands. 
This compliant solution eliminates signed overflow on systems where long long is at least twice the precision of int:
*/

//Multiplication
#include <stddef.h>
#include <assert.h>
#include <limits.h>
#include <inttypes.h>

extern size_t popcount(uintmax_t);
#define PRECISION(umax_value) popcount(umax_value)

void func(signed int si_a, signed int si_b) {
	signed int result;
	signed long long tmp;
	assert(PRECISION(ULLONG_MAX) >= 2 * PRECISION(UINT_MAX));
	tmp = (signed long long)si_a * (signed long long)si_b;

	/*
	* If the product cannot be represented as a 32-bit integer,
	* handle as an error condition.
	*/
	if ((tmp > INT_MAX) || (tmp < INT_MIN)) {
		/* Handle error */
	}
	else {
		result = (int)tmp;
	}
	/* ... */
}



/*
Addition

Addition is between two operands of arithmetic type or between a pointer to an object type and an integer type. This rule applies only to addition between two operands of arithmetic type. 
(See ARR37-C. Do not add or subtract an integer to a pointer to a non-array object and ARR30-C. Do not form or use out-of-bounds pointers or array subscripts.)
Incrementing is equivalent to adding 1.

Compliant Solution
This compliant solution ensures that the addition operation cannot overflow, regardless of representation :
*/

//Addition
#include <limits.h>

void f(signed int si_a, signed int si_b) {
	signed int sum;
	if (((si_b > 0) && (si_a > (INT_MAX - si_b))) ||
		((si_b < 0) && (si_a < (INT_MIN - si_b)))) {
		/* Handle error */
	}
	else {
		sum = si_a + si_b;
	}
	/* ... */
}



/*
Subtraction

Subtraction is between two operands of arithmetic type, two pointers to qualified or unqualified versions of compatible object types, or a pointer to an object type and an integer type. 
This rule applies only to subtraction between two operands of arithmetic type. (See ARR36-C. Do not subtract or compare two pointers that do not refer to the same array, ARR37-C. 
Do not add or subtract an integer to a pointer to a non-array object, and ARR30-C. Do not form or use out-of-bounds pointers or array subscripts for information about pointer subtraction.)
Decrementing is equivalent to subtracting 1.

Compliant Solution
This compliant solution tests the operands of the subtraction to guarantee there is no possibility of signed overflow, regardless of representation:
*/

//Subtraction
#include <limits.h>

void func(signed int si_a, signed int si_b) {
	signed int diff;
	if ((si_b > 0 && si_a < INT_MIN + si_b) ||
		(si_b < 0 && si_a > INT_MAX + si_b)) {
		/* Handle error */
	}
	else {
		diff = si_a - si_b;
	}

	/* ... */
}


/*
Division

Division is between two operands of arithmetic type. 
Overflow can occur during two's complement signed integer division when the dividend is equal to the minimum (negative) value for the signed integer type and the divisor is equal to −1. 
Division operations are also susceptible to divide-by-zero errors. (See INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors.)

Compliant Solution
This compliant solution eliminates the possibility of divide-by-zero errors or signed overflow:
*/

//Division
#include <limits.h>

void func(signed long s_a, signed long s_b) {
	signed long result;
	if ((s_b == 0) || ((s_a == LONG_MIN) && (s_b == -1))) {
		/* Handle error */
	}
	else {
		result = s_a / s_b;
	}
	/* ... */
}

/*
Remainder

The remainder operator provides the remainder when two operands of integer type are divided. 
Because many platforms implement remainder and division in the same instruction, the remainder operator is also susceptible to arithmetic overflow and division by zero. 
(See INT33-C. Ensure that division and remainder operations do not result in divide-by-zero errors.)

Compliant Solution
This compliant solution also tests the remainder operands to guarantee there is no possibility of an overflow:
*/

//Remainder
#include <limits.h>

void func(signed long s_a, signed long s_b) {
	signed long result;
	if ((s_b == 0) || ((s_a == LONG_MIN) && (s_b == -1))) {
		/* Handle error */
	}
	else {
		result = s_a % s_b;
	}
	/* ... */
}


/*
Left-Shift Operator

The left-shift operator takes two integer operands. The result of E1 << E2 is E1 left-shifted E2 bit positions; vacated bits are filled with zeros.
The C Standard, 6.5.7, paragraph 4 [ISO/IEC 9899:2011], states
If E1 has a signed type and nonnegative value, and E1 × 2E2 is representable in the result type, then that is the resulting value; otherwise, the behavior is undefined.
In almost every case, an attempt to shift by a negative number of bits or by more bits than exist in the operand indicates a logic error. 
These issues are covered by INT34-C. Do not shift an expression by a negative number of bits or by greater than or equal to the number of bits that exist in the operand.

Compliant Solution
This compliant solution eliminates the possibility of overflow resulting from a left-shift operation:
*/

//Left-Shift Operator
#include <limits.h>
#include <stddef.h>
#include <inttypes.h>

extern size_t popcount(uintmax_t);
#define PRECISION(umax_value) popcount(umax_value)

void func(signed long si_a, signed long si_b) {
	signed long result;
	if ((si_a < 0) || (si_b < 0) ||
		(si_b >= PRECISION(ULONG_MAX)) ||
		(si_a >(LONG_MAX >> si_b))) {
		/* Handle error */
	}
	else {
		result = si_a << si_b;
	}
	/* ... */
}



/*
Unary Negation

The unary negation operator takes an operand of arithmetic type. 
Overflow can occur during two's complement unary negation when the operand is equal to the minimum (negative) value for the signed integer type.

Compliant Solution
This compliant solution tests the negation operation to guarantee there is no possibility of signed overflow:
*/

//Unary Negation
#include <limits.h>

void func(signed long s_a) {
	signed long result;
	if (s_a == LONG_MIN) {
		/* Handle error */
	}
	else {
		result = -s_a;
	}
	/* ... */
}



/*
Komentarze
*/


/*
1

Ikona użytkownika : davearonson
Dave Aronson

The compliant solution for unsigned int addition is rather unclear.Is something wrong with "if (UINT_MAX - ui1 > ui2)" ?

No general compliant solution for signed subtraction ?

Re the general compliant solution for signed multiplication, all that nesting is rather messy, in ways that a temp var or two could help clear up.How about this :
*/

/* get easy cases over with fast, and eliminate 0 for the other part */
	if (0 == si1 || 0 == si2) result = 0;
/* could similarly shortcut 1-case and maybe a few others */
	else
	{
		signed int   limit;
		signed short sign = Sign(si1);  /* may have to write this function or macro */

		if (Sign(si2) == sign) limit = INT_MAX / si2;
		else limit = INT_MIN / si2;

		/* either way, we're checking the magnitude of s1 */
		if ((1 == sign && si1 > limit) || (-1 == sign && si1 < limit))
		{
			/* handle error */
		}

		result = si1 * si2;
	}

/*
The main problem that I think may be lurking in the above, 
is the truncation semantics of division yielding a negative quotient, 
in which case limit may have to be incremented or decremented.
I have to think on that a bit more, but this should at least serve as a clearer starting point.
*/


/*
2

Robert Seacord

The following program ran to completion using Microsoft Visual Studio 2005 Version 8.0.50727.42 and run on an IA-32 Windows XP box:
*/
	int main(void) {
		// general signed
		signed int si1, si2;

		for (si1 = 0; si1 < INT_MAX; ++si1) {
			for (si2 = 0; si2 < INT_MAX; ++si2) {

				if (((si1>0) && (si2>0) && (si1 > (INT_MAX - si2))) || ((si1<0) && (si2<0) && (si1 < (INT_MIN - si2)))) {
					if (((si1^si2) | (((si1 ^ (~(si1^si2) & (1 << (sizeof(int)*CHAR_BIT - 1)))) + si2) ^ si2)) >= 0);
					else printf("general signed error, two's complement ok for si1 = %d, si2 = %d.", si1, si2);
				}

				if (((si1^si2) | (((si1 ^ (~(si1^si2) & (1 << (sizeof(int)*CHAR_BIT - 1)))) + si2) ^ si2)) >= 0) {
					if (((si1>0) && (si2>0) && (si1 >(INT_MAX - si2))) || ((si1<0) && (si2<0) && (si1 < (INT_MIN - si2))));
					else printf("two's complement error, general signed ok for si1 = %d, si2 = %d.", si1, si2);
				}

			} // end for all values of si2

			printf("done.\n");

		} // end for all values of si1

		return 0;
	}

/* The program took a while to run, but only output "done." */



/*
3

David Svoboda

This rule may be technically correct, but it throws too heavy a burden on any programmer doing any math; even something as simple as x++.

For instance, DCL06-A has example code that computes the quadratic formula:
x = (-b + sqrt(b*b - 4*a*c)) / (2*a);

Concise and elegant, but this completely ignores overflow possibilities. 
This code can be done mostly with ints, just excepting the sqrt() function and divide operator.

This rule basically requires an if statement with a complex boolean expression and a 'handle-overflow' clause for every math operation. 
So securing this 1-line formula would mutate it into a 30-line quagmire of if statements. 
The overhead of checking for overflow would completely obscure the original formula in the code.

The ideal way to handle this would be with exceptions. In Java one could just say:
*/

try {
x = (-b + Math.sqrt((double) (b*b - 4*a*c))) / (2*a);
} catch (OverflowException exception) {
/* handle exception */
}


/*
Does C99(or POSIX) provide any exception mechanism for integer overflow ? Can we, for instance, do the math, and then check errno ?

And on top of that, the table omits the – operator! (uśmiech)

*/




/*
4

Hallvard Furuseth

I think the table about overflow/not overflow is misleading, I'd split it in arithmetic, bit, assignment, and conditional operations:

All assignment operators can truncate.
Bit operations cannot overflow, but I believe they can produce a trap representation: With two's complement, INT_MIN-1 if INT_MIN == -INT_MAX. 
Other representations: negative zero if that is a trap representation.
Both << and >> have undefined behavior if the right operand is too large. Shifting a negative value (I think), 
or a positive value so it becomes negative, yields undefined behavior (C99 6.5.7p4). 
Remember that two's complement representation does not imply silent wraparound and so on, though it's a common combination.

The two's complement add/subtract solutions are broken:

An int can have fewer than sizeof(int)*CHAR_BIT value bits: Some of the bits may be padding bits. 
Rare enough that one might "fix" code depending on no padding by refusing to compile if there is padding though. 
Note, this also breaks the "compliant" solutions for shifting. Googling for "site:securecoding.cert.org sizeof CHAR_BIT" found several other examples.
As mentioned, (1 << (sign bit number) is undefined. Just use ~INT_MAX, that's what the limits.h constants are for. Except that can also break:
Even for two's complement, INT_MIN may be -INT_MAX so ~INT_MAX can be a trap representation. 
An example has been mentioned once on comp.lang.c, 
though I think the reason was poor - the implementation not bother to implement printf("%d", -INT-MAX-1) or something.

The general compliant addition/subtraction solutions are unnecessarily big. Look at what you need to catch and reduce it a bit:
*/
if (si1 - si2 > INT_MAX || si1 - si2 < INT_MIN) error; /* may overflow */
if (si1 > INT_MAX + si2 || si1 < INT_MIN + si2) error; /* may overflow */
													   /* Remove overflows: (si2 < 0 ? (above expr) : (above expr again)),
													   * removing the cases where si1 would be < INT_MIN or > INT_MAX: */
if (si2 < 0 ? si1 > INT_MAX + si2 : si1 < INT_MIN + si2) error;

/*
Similar for addition.

Another trick when you know both values are nonnegative(which is a common case) is to convert to unsigned, 
then operations are well - defined so you can test for overflow afterwards :
*/
assert(si1 >= 0 && si2 >= 0);
unsigned res = (unsigned)si1 + si2;
if (res < si1 || res > INT_MAX) { /* wrapped around or out of range */ }

/*
The general compliant multiplication solution can be reduced by first swapping si1 and si2 if si1 > si2, 
or something like that.And as big as it is, it looks like a good case for doing
*/
if (LLONG_MAX / INT_MAX > INT_MAX)
long long solution; /* or use INTMAX_MAX and intmax_t */
else
general solution;

/*
The division and modulo tests are not quite right - the point is not that LONG_MIN is a problem, 
but that a value < -LONG_MAX, if that can exist, is a problem.Also you never need to do 3 tests:
*/
if (sl2 == -1 ? sl1 < -LONG_MAX : sl2 == 0) error;

/*
The same goes for unary negation - check if si1 < -INT_MAX.Possibly this also affects the multiplication solution, 
but I got tired just looking at that.
*/

/*
	maj 01, 2008

	Ikona użytkownika : hbf
	Hallvard Furuseth

	For multiplication, this should be equivalent :
	*/
if (si1 > si2) {
	int tmp = si2; si2 = si1; si1 = tmp;
}
if (si1 > 0 ? (si2 > INT_MAX / si1) :
	(si2 != 0 && si1 < (si2 > 0 ? INT_MIN : INT_MAX) / si2)) {
	handle error;
}
result = si1 * si2; Â

/*
It helps to play around a bit with code like that(uśmiech)
However one problem with this code is that it will compile but break on C90 implementations which can round away from zero if an operand is negative.
Many implementations support part of but not all C99, so it's probably best to catch it. 
Either expand the test to handle that (just the thought makes me tired(uśmiech) 
or add something to ensure the program will not compile if it makes wrong assumptions about the implementation:
*/
#if (-1)/2 || 1/-2 || (-1)/-2
#  error "integer division rounding away from zero not supported"
#endif

/*
maj 02, 2008
*/