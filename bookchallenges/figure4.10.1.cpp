#include <iostream>
using namespace std;

int main() {
	const int EMPANADA_COST = 3;
	const int TACO_COST     = 4;

	int usermoney, numtacos, numempanadas, mealcost, maxempanadas, maxtacos;

	mealcost = 0;

	cout << "Enter money for meal: ";
	cin >> usermoney;

	maxempanadas = usermoney / EMPANADA_COST;
	maxtacos = usermoney / TACO_COST;

	for (numtacos = 0; numtacos <= maxtacos; ++numtacos)
	{
		for (numempanadas = 0; numempanadas <= maxempanadas; ++numempanadas)
		{
			mealcost = (numempanadas * EMPANADA_COST) + (numtacos * TACO_COST);
			// Find first meal option that exactly matches user money
			if (mealcost == usermoney)
			{
				break;
			}
		}
		// If meal option exactly matching user money is found, break from outer loop as well
		if (mealcost == usermoney)
		{
			break;
		}
	}
	if (mealcost == usermoney)
	{
		cout << "$" << mealcost << " buys " << numempanadas << " empanadas and " << numtacos << " tacos without change." << endl;
	}
	else
	{
		cout << "You cannot buy a meal without having change left over." << endl;
	}

	return 0;
}
