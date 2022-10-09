#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// Declaring the variables. PI is a const so it is in all caps.
	const float PI = 3.14159;
	float volume;
	float radius;

	cout << "Enter the radius (cm): ";
	cin >> radius; // user inputs the radius

	volume = (4/static_cast<float>(3))*PI*pow(radius, 3);
	cout << "The volume of the sphere in cm^3 is " << volume << endl;
		

	return 0;
}

