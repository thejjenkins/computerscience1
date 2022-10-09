#include <iostream>
using namespace std;

// Outputs average of list of positive integers
// List ends with 0 (sentinel)
// ex: 10 1 6 3 0 yields (10 + 1 + 6 + 3) / 4, or 5

int main()
{
	int currValue;
	int valuesSum;
	int numValues;

	valuesSum = 0;
	numValues = 0;

	cout << "This program outputs the average of a list of positive integers. Enter any positive integers and then type \"0\" to compute the average. You can start here: ";
	cin >> currValue;

	while (currValue > 0) // Get values until 0 (or less)
	{
		valuesSum = valuesSum + currValue;
		numValues = numValues + 1;
		cin >> currValue;
	}

	cout << "Average: " << (valuesSum / numValues) << endl;

	return 0;
}
