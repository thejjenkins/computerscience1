/* Author: James Jenkins (jamesjenkins2@my.unt.edu)
 * Date: September 28, 2021
 * Instructor: Dr. Pradhumna Shrestha
 * Description: This program gives the user a choice of multiplying, adding, or finding the absolute difference between two user-entered integers. */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	enum Operation {Multiply = 'M', Add = 'A', Difference = 'D'}; // Operation is a different variable type
	int result;
	int num1, num2, num3;
	Operation my_operation; // This is how to access the options inside of Operation
	char choice;
	bool repeat = true;
	
	cout << "Enter two integers:"; cin >> num1 >> num2;

	do
	{
		cout << "Enter M to multiply, A to add, or D to find the difference: "; cin >> choice;
		choice = toupper(choice); // Choice is initialized with = so that it becomes uppercase
		my_operation = static_cast<Operation>(choice); 
		// my_operation needs to access the options in Operation, but they are different variable types.
		// So choice must be static_cast to the variable type Operation.
		switch (my_operation) // my_operation is now static_cast to the variable type enum
		{
			case Multiply:
				num3 = num1 * num2;
				repeat = false; // Boolean must be declared false or else the do-while loop
						// will continue to repeat even after a correct choice
				cout << "Your numbers were " << num1 << " and " << num2 << " and your operation was multiplication. The result is " << num3 << "." << endl;
				break;
			case Add:
				num3 = num1 + num2;
				repeat = false;
				cout << "Your numbers were " << num1 << " and " << num2 << " and your operation was addition. The result is " << num3 << "." << endl;
				break;
			case Difference:
				num3 = abs(num1 - num2);
				repeat = false;
				cout << "Your numbers were " << num1 << " and " << num2 << " and your operation was difference. The result is " << num3 << "." << endl;
				break;
			default: 
				cout << "Wrong choice. Please try again." << endl;
		} 
	} while (repeat); // repeat is already declared as true, so it is unnecessary to write repeat = true again


	return 0;
}
