/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 9 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program uses a struct to categorize variables of a persons BMI.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Patient
{
    string name;
    float weight;
    int feet;
    int inches;
};

bool checkBMI(Patient& person)
{
    int totalheight = person.feet*12+person.inches;
    float bmi = (703*person.weight)*pow(totalheight,2);
    return (bmi>=18.5 && bmi <= 24.9);
}

int main()
{
    Patient person;
    cout << "Enter the person's name: "; getline (cin, person.name);

    cout << "Enter the person's weight in pounds: "; cin >> person.weight;

    cout << "Enter the person's height in feet and inches: "; cin >> person.feet >> person.inches;

    if (checkBMI(person))
    {
        cout << "The BMI of " << person.name << " is within range." << endl;
    }
    else
    {
        cout << "The BMI of " << person.name << " is not within range." << endl;
    }
    return 0;
}