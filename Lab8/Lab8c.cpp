/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 26 October 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program uses a two dimensional array to store 6 quiz grades for 10 students. The program calls a function which determines the highest quiz grade for each student. The maximum number of grades possible to be stored is 60, and the maximum number of grades returned for the max is 10.
*/

#include "Lab8_Header.h" // A custom generated library that includes iostream, using namespace std, global constants, and function declarations

int main()
{
    float grades[ROWS][COLS];
    float maximum[ROWS];
    float array[ROWS];
    int num;
    bool repeat;

    do
    {
        cout << "How many students are in the class? "; cin >> num;
        if (num<0||num>10)
        {
            cout << "Number must be between 0 and 10. Please enter again." << endl;
            repeat = true;
        }
        else
        {
            repeat = false;
        }
    }
    while(repeat);
    cout << num << endl;
    for (int row=0; row<num; ++row)
    {
        cout << "Enter grades 1 through 6 for student #" << row+1 << ": ";
        for (int col=0; col<COLS; ++col)
        {
            cin >> grades[row][col];
        }
    }
    computeMaximum(grades, num, maximum);
    for (int row=0; row<num; ++row)
    {
        for (int col=0; col<COLS; ++col)
        {
            cout << grades[row][col] << "\t";
        }
        cout << endl;
    }
    showArray(maximum, num);
    return 0;
}