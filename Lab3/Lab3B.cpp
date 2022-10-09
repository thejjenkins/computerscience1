#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
	int x;
	srand(time(NULL)); //This makes the randomly generated number different for every second that passes.
	int y = (rand() %101 + 200); //The y integer is a random number between 200 and 300

	cout << "Enter a value for x between 200 and 300: ";
	cin >> x; //user enters a number

	if (x < 200 || x > 300) { //if x is less than 200 or greater than 300
		cout << "Invalid entry." << endl;
				}
	else {
		cout << "You entered " << x << "." << endl;
		if (y > x) { //if y is greater than x
		cout << y << " is greater than " << x << "." << endl;
			   }
		else { //if x is greater than y
		cout << x << " is greater than " << y << "." << endl;
		     }
	     }
	
	return 0;
}
