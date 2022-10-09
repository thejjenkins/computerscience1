#include "Lab8_Header.h"
/*
Function: computeMaximum
Parameters: A 2 dimensional array with float variables with a constant number of columns and the rows are determined by the second parameter num. The second parameter determines the number of rows which is the number of students. The third parameter is an array of float variables that will hold the highest quiz score of each student.
Return: An array that holds the highest quiz grade of each student in the 2D array.
Description: The function contains a nested for loop. The outer loop iterates through the rows and the inner loop iterates through the columns. The inner loop stores the highest value in each row, and then the outer loop goes to the next row.
*/
void computeMaximum(float grades[][COLS], int num, float maximum[])
{
    for (int row=0; row<num; ++row)
    {
        maximum[row]=grades[row][0];
        for (int col=0; col<COLS; ++col)
        {
            if (grades[row][col]>maximum[row])
            {
                maximum[row]=grades[row][col];
            }
        }
    }
}