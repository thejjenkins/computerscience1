#include <iostream>
#include <string>
using namespace std;

int main ()
{
	enum Characters {Digits = 'D', Lower = 'L', Upper = 'U'};
	Characters userchoice;
	char choice;
	int numDigits = 0, numLower = 0, numUpper = 0;
	string userstring;
	
	cout << "Please type any sentence: "; getline(cin, userstring);
	
	cout << "Enter 'D' to count digits, 'L' to count lowercase, and 'U' to count uppercase: "; cin >> choice;
	userchoice = static_cast<Characters>(choice);
	switch (choice)
	{
		case Digits:
			for (int i = 0; i < userstring.size(); ++i)
			{
				if (isdigit(userstring[i]))
				{
					++numDigits;
				}
			}
			break;
		case Lower:
			for (int i = 0; i < userstring.size(); ++i)
			{
				if (islower(userstring[i]))
				{
					++numLower;
				}
			}
			break;
		case Upper:
			for (int i = 0; i < userstring.size(); ++i)
			{
				if (isupper(userstring[i]))
				{
					++numUpper;
				}
			}
			break;
		default:
			cout << "Wrong choice." << endl;
	}
	if (choice == 'D')
	{
		cout << "The total number of digits is: " << numDigits << endl;
	}
	else if (choice == 'L')
	{
		cout << "The total number of lowercase is: " << numLower << endl;
	}
	else if (choice == 'U')
	{
		cout << "The total number of uppercase is: " << numUpper << endl;
	}
	else
	{
		cout << "The total number of desired characters is: 0" << endl;
	}
	
	return 0;
}
