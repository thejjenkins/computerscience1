/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 2 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program reads some float numbers from a file and sorts them in ascending order.
*/
#include <iostream>
#include <fstream> // syntax necessary to read from files and write to files
using namespace std;

int main()
{
    ifstream fin; // ifstream is the data type and fin is the variable name (think: int x or double my_dbl)
    float numbers[20]; // array that is big enough to hold all the read numbers. 
    int i=0;
    float temp; // temp is needed for swapping elements

    fin.open("unsorted.dat"); // syntax necessary to open the file. Quotes are part of the syntax.
    if(fin.fail()) // the fail() function returns a bool variable, so if fail() returns true then the branch will execute.
    {
        cout << "Error opening file" << endl;
    }
    while (!fin.eof()) // the eof() function returns a bool variable, and the inverter ! does the oppostite of the bool variable. While not the end of file, iterate.
    {
        fin>>numbers[i]; 
        ++i;
    }
    /*
    The following nested loops are a template for swapping elements in an array.
    The temp variable is initialized to the first element in the array, and the inner loop
    begins comparing the next variable to the temp variable. The if statement swamps the
    elements. All loop iterations will return a list in ascending order.
    */
    for (int j=0; j<i; ++j)
    {
        for (int k=j+1; k<i; ++k)
        {
            if (numbers[k]<numbers[j])
            {
                temp = numbers[j];
                numbers[j]=numbers[k];
                numbers[k]=temp;
            }
        }
    }
    for (int l=0; l<i; ++l)
    {
        cout << numbers[l] << "\t"; // output sorted list to the screen
    }
    cout << endl;
    

    fin.close();

    return 0;
}