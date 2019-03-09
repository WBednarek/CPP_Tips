
// Palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>


bool isPalindrome(std::string word)
{

	bool isWordPalindrome = true;
	for (int i = 0; i < word.length(); ++i)
	{
		if (word[i] != word[word.length() - i - 1])  isWordPalindrome = false;

	}


	return isWordPalindrome;
}


int main()
{
    
	std::cout << isPalindrome("d1otod");


	return 0;
}
