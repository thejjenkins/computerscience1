/* Author: James Jenkins (jamesjenkins2@my.unt.edu)
 * Date: 10 October 2021
 * Instructor: Dr. Pradhumna Shrestha
 * Description: This program allows the user to enter a 2D matrix and then display the minimum values.
*/
#include <iostream>
using namespace std;

int main ()
{
	const int ROW_SIZE=2; // number of rows
	const int COLUMN_SIZE=5; // number of columns
	int matrix[ROW_SIZE][COLUMN_SIZE]; // 2D array
	int rowmin, columnmin;
	for(int i = 0; i<ROW_SIZE; ++i)
	{
		for(int j=0; j<COLUMN_SIZE; ++j)
		{
			cout << "Enter data for row #" << i+1 << " and column #" << j+1 << ": ";
			cin >> matrix[i][j]; // read matrix elements
		}
	}
	cout << "You entered: " << endl;
	for(int i=0;i<ROW_SIZE; ++i)
	{
		for(int j=0; j<COLUMN_SIZE; ++j)
		{
			cout << matrix[i][j]<< '\t'; //outputs the matrix as a 2x5 grid
		}
		cout << endl;
	}
	for(int i = 0; i<ROW_SIZE; ++i)
	{
		rowmin = matrix[i][0]; // pick a minimum for the row
		for(int j=0; j<COLUMN_SIZE; ++j)
		{
			if (matrix[i][j]<rowmin) 
			{
				rowmin = matrix[i][j];
			}
		}
		cout << "Minimum for row #" << i+1 << ": " << rowmin << endl;
	}
	for(int i = 0; i<COLUMN_SIZE; ++i)
	{
		columnmin = matrix[0][i];
		for(int j=0; j<ROW_SIZE; ++j)
		{
			if(matrix[j][i]<columnmin)
			{
				columnmin = matrix[j][i];
			}

		}
		cout << "Minimum for column #" << i+1 << ": " << columnmin << endl;
	}


	return 0;
}
