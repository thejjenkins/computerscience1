#include "Lab8_Header.h"
/*
Function: showArray
Parameters: an array that holds an undetermined number of float variables, and an integer that represents the number of students.
Return: A cout statement that prints all elements of the array.
Description: The function simply prints all elements of the array. The array comes from another function that computes the maximum values in each row of a 2 dimensional array.
*/
void showArray(float array[], int size)
{
    cout << "The maximum grades are:\n";
    for (int i=0; i<size; ++i)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}