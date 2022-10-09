/* Author: James Jenkins (jamesjenkins2@my.unt.edu)
 * Date: September 28, 2021
 * Instructor: Dr. Pradhumna Shrestha
 * Description: This program will count the number of vowels and consonants in a user entered string. */

#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string userString;
	int i;
	int vowels = 0, consonants = 0;

	cout << "Please enter a string: "; getline (cin, userString);
	for (i=0; i<userString.size(); ++i) // If i < userString.size() then it will return the last index. This is what I want. If I do <= then there will be a compilation error.
	{
		char ch = userString.at(i); // This simplifies the code. If I did not do this then I would have to write a long if else-if block to account for every vowel. 
		if (isalpha(ch)) // This checks to see if the character I just declared is an alphabet
		{
			ch = toupper(ch); // This accounts for lower and uppercase characters.
			if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			{
				++vowels;
			}
			else
			{
				++consonants;
			}
		}
	}
	cout << "The number of vowels and consonants in your string are " << vowels << " and " << consonants << ", respectively." << endl;


	return 0;
}
