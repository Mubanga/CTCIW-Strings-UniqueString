// UniqueStrings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*	Question Unique Strings
 Implement an algorithm to determine if a string has all unique characters. 
 What if you cannot use additional data structures 

 #1 Assume string only contains standard ASCII character set.
 #2 Assume string contains extended ASCII character set.
 
*/

#include "pch.h"
#include <iostream>
#include <assert.h>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

string removeSpacesInString(string TestString)
{
	stringstream check_1(TestString);
	string tokenizedstring;
	string splitstrings;
	while (getline(check_1, splitstrings, ' '))
	{
		if (tokenizedstring.empty())
		{
			tokenizedstring = splitstrings;
		}
		else
		{
			tokenizedstring.append(splitstrings);
		}
	}
	return tokenizedstring;
}

string removeSpacesInString2(string TestString)
{
	int POS_First_Space = TestString.find(" ");
	while (POS_First_Space != string::npos)
	{
		TestString = TestString.erase(POS_First_Space,1);
		POS_First_Space = TestString.find(" ");
	}
	return TestString;
}

bool isUniqueCharacterString(string TestString)
{
	if (TestString.length() > 0)
	{
		TestString = removeSpacesInString2(TestString);
		map<char, bool> individualCharacterList;
		for (int x = 0; x < TestString.length(); x++)
		{
			// You can only insert unique key value pairs into a map, so if we can't insert a character the string is not unique.
			individualCharacterList.insert(pair<char, bool>(TestString[x], true));
		}
		if (individualCharacterList.size() == TestString.length())
		{
			cout << " String Is Unique " << endl;
			return true;
		}
		else
		{
			cout << " String Is Not Unique " << endl;
			return false;
		}
		
	}
	else
	{
		return false;
	}
	//if (teststring.length() > 0)
	//{
	//	teststring = removespacesinstring2(teststring);
	//	cout << " teststring now is = " << teststring << endl;
	//  char firstcharacter = teststring[0];
	//  for (int x = 1; x < teststring.length()-1; x++)
	//  {
	//	  char currentcharacter = teststring[x];
	//	  cout << " firstcharacter = " << firstcharacter << " current character = " << currentcharacter << endl;
	//	  if (firstcharacter == currentcharacter)
	//	  {
	//		  // the string is not unique time to return false
	//		  return false;
	//	  }
	//  }
	//  return true;
	//}
	//else
	//{
	//	return false;
	//}
}

int main()
{
	bool uniqueString = false;
	bool notuniqueString = false;
	string TestString1 = "The quick brown fox jumps over the lazy dog";
	string TestString2 = "Isabelle watches me from far away I'd give anything";
	string TestString3 = "Dog meat's";
	uniqueString = isUniqueCharacterString(TestString1);
	notuniqueString = isUniqueCharacterString(TestString2);
	if (isUniqueCharacterString(TestString3))
	{
		cout << " Yep this is a unique string " << endl;
	}

    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
