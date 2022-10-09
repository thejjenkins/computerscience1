/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 28 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program is a 2D dynamic array, a 1D dynamic array, and two functions. It demonstrates how to use the 2D dynamic array such as when to allocate memory and when to delete memory and how to pass them as arguments to functions.
*/
#include <iostream>
using namespace std;
/*
Function: getGrades
Parameters: A 2D dynamic array of integers, an integer representing the number of rows, and a 1D dynamic array
Return: The function "returns" the 1D dynamic array
Description: The function ompletes the memory allocation of the columns by asking how many tests each student has taken. Each test score is recorded in a loop that iterates for the number of tests entered. The average score is calculated and then stored in the 1D dynamic array.
*/
void getGrades(int **grades, int numstudents, double *average)
{
    int numtests;
    for(int i=0; i<numstudents; ++i)
    {
        cout << "How many tests has student #" << i+1 << " taken? "; cin>>numtests;
        grades[i] = new int[numtests]; // memory allocation for the COLUMNS of the dynamic 2D array
        cout << "Enter test scores: " << endl;
        int sum = 0;
        for(int j=0; j<numtests; ++j)
        {
            cin >> grades[i][j];
            sum+=grades[i][j];
        }
        average[i]=static_cast<double>(sum)/numtests;
    }
    for(int i=0;i<numstudents;++i) // dynamic 2D array is no longer necessary, so it is deleted inside the function.
    {
        delete [] grades[i]; // Each grade must be deleted in the 2D array
    }
    delete [] grades; // then the array can be deleted
    return;
}
/*
Function: displayAverage
Parameters: A 1D dynamic array, and an integer representing the number of rows
Return: a loop of cout statements that give the average score of each student.
Description: The function reads each element of the 1D dynamic array that was created in the getGrades function and prints it to the screen.
*/
void displayAverage(double* average, int numstudents)
{
    for(int i=0; i<numstudents; ++i)
    {
        cout << "Average test score for student #" << i+1 << ": " << average[i] << endl;
    }
    return;
}

int main()
{
    int numstudents;
    int** grades;
    double* average;

    cout << "This program calculates the average test score for each student." << endl;
    cout << "How many students? "; cin >> numstudents;
    grades = new int*[numstudents]; // 2D dynamic array memory allocation for the ROWS
    average = new double[numstudents]; // memory allocation for the 1D dynamic array
    getGrades(grades, numstudents, average);
    displayAverage(average, numstudents);

    return 0;
}