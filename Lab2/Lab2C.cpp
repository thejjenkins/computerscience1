#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
	// Declaring the variables
	string name;
	double salary;
	int rate;
	double bonus;

	cout << "Please enter your full name: ";
	getline (cin, name); //getline function allows whitespace

	cout << "Please enter your salary: ";
	cin >> salary; //salary can include decimals because it is declared as a double

	cout << "Please enter the percentage rate of bonus: ";
	cin >> rate; //rate is usually a normal number, so it is saved as an int

	bonus = salary * (static_cast<double>(rate)/100);
	cout.setf(ios::fixed);      //statements necessary
	cout.setf(ios::showpoint);  //for
	cout.precision(2);          //setting precision
	cout << name << ", your bonus will be $" << bonus << endl;
	

	return 0;
}
