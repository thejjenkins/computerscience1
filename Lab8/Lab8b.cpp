/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 26 October 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program uses a programmer defined function to compute the maximum value in a randomly generated array of integers.
*/

#include <iostream>
#include <ctime> // This library is necessary to generate truly random numbers
using namespace std;

const int SIZE = 10; // This is a constant GLOBAL variable meaning that it is declared OUTSIDE the scope of any and every function in order that it can be used inside any and every function's scope.

/*
Function: maxvalue
Parameters: an array of integers whose size is to remain constant
Return: The maximum value of all the 10 integers inside the array
Description: This function establishes a maximum value of the array as the first element. Then a for loop iterates through each value and compares it to the current maximum value. If the element is greater than the current maximum value then the loop declares the new maximum value to be the current element.
*/
int maxvalue(const int randomarray[]) // declaring the parameter as a const array means that its size does not change in the function. The values can change, but the size remains the same.
{
    int maxvalue = randomarray[0]; // declaring the maximum value of the array as the first element.
    for (int i=0; i<SIZE; ++i) // SIZE is the global variable. It is the size of the array.
    {
        if (randomarray[i]>maxvalue) // comparing the current element to the current max value
        {
            maxvalue = randomarray[i]; // if element is greater then it becomes the current max value
        }
    }
    return maxvalue; // function is meant to return the maximum integer value of the array
}
int main()
{
    int randomarray[SIZE]; // the size of the array is the global constant
    srand(time(NULL)); // syntax necessary to generate seeded random numbers based on the time
    for (int i=0; i<SIZE; ++i)
    {
        int randomnum = rand()%50+50; // %50 returns a number between 0-49, so adding 50 makes it return a number between 50-100. The initialization of the random number is done inside the loop so that a new random number can be generated for each iteration. A previous trial where the initialization was done before the loop revealed that every element was the same number.
        randomarray[i]=randomnum; // element i is the randomly generated number from above.
    }
    cout << "Here is an array of 10 random integers between 50 and 100:" << endl;
    for (int i=0; i<SIZE; ++i)
    {
        cout << randomarray[i] <<"\t"; // displaying the randomly generated array
    }
    cout << endl;

    cout << "The highest integer is: " << maxvalue(randomarray) << endl; // calling the function will bring the compiler up to the function definition and start running the code. The function returns the maxvalue.

    return 0;
}