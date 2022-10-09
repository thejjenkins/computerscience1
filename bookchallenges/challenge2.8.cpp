#include <iostream>
using namespace std;

int main()	{
	int shipWeightPounds;
	int shipCostCents;
	const int FLAT_FEE_CENTS = 75;
	const int CENTS_PER_POUND = 25;
	
	cout << "Enter weight (lbs): ";
	cin >> shipWeightPounds;
	shipCostCents = FLAT_FEE_CENTS + (CENTS_PER_POUND * shipWeightPounds);
	cout << "Weight (lbs): " << shipWeightPounds;
	cout << ", Flat fee (cents): " << FLAT_FEE_CENTS;
	cout << ", Cents per lb: " << CENTS_PER_POUND << endl;
	cout << "Shipping cost (cents): " << shipCostCents << endl;
		


	return 0;
}