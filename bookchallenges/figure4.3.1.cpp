#include <iostream>
using namespace std;

// Output GCD of user-input numA and numB using Euclid's algorithm: if numA > numB, set numA to numA - numB, else set numB to numB - numA. These steps are repeated until numA equals numB, at which point numA and numB each equal the GCD.

int main()
{
	int numA;
	int numB;

	cout << "This program finds the GCD of two positive integers. The program will return 1 if no GCD is found." << endl;
	cout << "Enter first positive integer: ";
	cin >> numA;

	cout << "Enter second positive integer: ";
	cin >> numB;

	while (numA != numB)
	{
		if (numB > numA)
		{
			numB = numB - numA;
		}
		else
		{
			numA = numA - numB;
		}
	}
	
	cout << "GCD is: " << numA << endl;

	return 0;
}
