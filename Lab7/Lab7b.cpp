/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 19 October 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program uses a function to compute the bonus of an employee's base salary.
*/
#include <iostream>
using namespace std;

double compute_bonus(double base_salary, int experience); // This is the declaration of the function. The definition comes later. The definition could be included up here, but this format makes the main() function closer to the top.

int main()
{
    double base_salary;
    int experience;

    cout << "Enter base salary: "; cin >> base_salary;
    cout << "Enter years of experience: "; cin >> experience;

    cout << "Your bonus is $" << compute_bonus(base_salary, experience) << endl; // Calling the function compute_bonus tells the compiler to use the function definition below
    return 0; // end of main() function
}
/*
Function: Bonus
Parameters: A double representing the base salary and an integer representing the years of experience
Return: A double representing the bonus
Description: This function computes the bonus of a base salary based on the years of experience entered
*/
double compute_bonus(double base_salary, int experience) // function parameters are named the same as those in main, but they are not the same because the scope of the main() function and the compute_bonus() functions are different.
{
    double bonus;
    if (experience > 10)
    {
        bonus = 0.06*base_salary;
    }
    else
    {
        bonus = 0.03*base_salary;
    }
    return bonus; // The value the function returns to main() where the function was called. (line 20).
}