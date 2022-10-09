/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 9 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program uses a pointer array to store multiple values and then determines the maximum of all of the values.
*/

#include <iostream>
using namespace std;

int main()
{
    int* array;
    int num;
    int maxvalue;
    cout << "How many numbers would you like to process? "; cin >> num;
    array = new int[num];
    cout << "Enter " << num << " integers:" << endl;
    for (int i=0; i<num; ++i)
    {
        cin>>*(array+i);
    }
    maxvalue = array[0];
    for (int i=0; i<num; ++i)
    {
        if (*(array+i)>maxvalue)
        {
            maxvalue = array[i];
        }
    }
    cout << maxvalue << endl;

    delete [] array;
    return 0;
}