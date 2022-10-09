/*Author: James Jenkins (jamesjenkins2@my.unt.edu)
  Date: September 21, 2021
  Instructor: Dr. Pradhumna Shrestha
  Description: In this program, you will use a string function to determine whether a user selected
  sub-string is present in a larger string or not.
  */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string largerString = "In this lab we will search inside C++ strings.";
	string subString;
	int pos;

	cout << "Type anything: ";
	getline (cin, subString);
	pos = largerString.find(subString);
	
	if ((pos >= 0) && (pos <= (largerString.length())-1)) //semi-colon not needed here
	{
		cout << "Location of what you typed in the larger string is: " << pos << endl;
	}
	else
	{
	        cout << "Invalid location." << endl;
	}



	return 0;
}
