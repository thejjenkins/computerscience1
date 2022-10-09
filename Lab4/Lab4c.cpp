/*Author: James Jenkins (jamesjenkins2@my.unt.edu)
 * Date: September 21, 2021
 * Instructor: Dr. Pradhumna Shrestha
 * Description: In this program you will perform character operations. Using a suitable message, prompt
 * the user to enter a string. The user may enter multiple words so you must use the getline function.
 */

#include <iostream>
#include <string> //The string library must be included whenever you are working with strings.
using namespace std;

int main() 
{
	string userString;
	int lastIndex;
	
	cout << "Please type a string of characters: ";
	getline (cin, userString); //getline command is used to get a string that includes whitespace.
	lastIndex = (userString.length()) - 1; //this declaration MUST be made after getline(cin, userString) otherwise lastIndex is trying to find the length of a string that does not exist yet.
	//The length function starts counting from 1 whereas the index begins at 0. Therefore, the last index must be the length minus 1.

	if (isalpha(userString.at(0))) //the command for isalpha, isupper, isdigit, etc. does not work with strings. The argument of isupper, etc. is the at() command.
	{
		if (isupper(userString.at(0)))
		{
			if (userString.at(lastIndex) == '.')
			{
				cout << "This format is correct." << endl;
			}
			else
			{
				cout << "Last character must be a period." << endl;
			}
		}
		else
		{
			if (userString.at(lastIndex) == '.')
			{
				cout << "The first letter must be uppercase." << endl;
			}
			else
			{
				cout << "The first letter must be uppercase and the last character must be a period." << endl;
			}
		}
	}
	else
	{
		if (!isalpha(userString.at(0)))
		{
			cout << "The first character must be a letter." << endl;
		}
		else if ((isupper(userString.at(0))) && (userString.at(lastIndex) == '.'))
		{
			cout << "The first character must be a letter." << endl;
			
		}
		else
		{
			cout << "The first character must be an uppercase letter and the last character must be a period." << endl;
		}
	}

	return 0;
}
