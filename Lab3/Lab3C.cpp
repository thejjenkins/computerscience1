#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int experience; //declaring variables with clear names makes code easier to read
	float salary;
	char performance;
	float bonus;
	char Y, y; //multiple declarations can be separated by commas

	printf("Please enter your salary: ");
	scanf("%f", &salary); //%f is syntax required for printf and scanf and it
			      //is for a float type variable. The "&" symbol is also
			      //required syntax for the argument of scanf.
			      //scanf("format string", variable)
	printf("Please enter your years of experience: ");
			      //printf("String includes %i", declared variable for %i)
	scanf("%i", &experience);
	printf("Please indicate your satisfactory performance: ");
	scanf(" %c", &performance); //space in front of %c to solve a compiling error 
	

	printf("Your salary is $%.2f.\n", salary);
				//%.2f means to recall the float variable and display
				//2 decimal values. %.3f would mean 3 decimal values
				//and the \n is the equivalent of endl. Must be placed
				//inside the quotations.
	printf("Your years of experience are %i.\n", experience);
	printf("You indicated %c for your satisfactory performance.\n", performance);

	if(performance == 'Y' || performance == 'y') 
		//double bars || indicate "or". Useful for combining two if statements
	{
		if(experience >= 10) //>= is greater than or equal to
		{
			bonus = 0.1*salary;
			printf("Your bonus is $%.2f.\n", bonus);
		}
		else
		{
			bonus = 0.05*salary;
			printf("Your bonus is $%.2f.\n", bonus);
		}
	}
	else
	{
		if(experience >= 10)
		{
			bonus = 0.03*salary;
			printf("Your bonus is $%.2f.\n", bonus);
		}
		else
		{
			printf("Your bonus is $0.\n");
		}
	}


	return 0;
}
