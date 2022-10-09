/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 28 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program is the C-method of using a dynamic array. It works the same way as C++, but all libraries and syntax are C instead of C++. The main difference is the realloc() function. This function allows the dynamic array to be increased during run time. In C++ this cannot be done.
*/
#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"

int main()
{
    int num=1;
    double *array=(double*)malloc(num*sizeof(double)); // dynamic array memory allocation
    double sum=0.0, average=0.0;
    bool repeat;
    int i=0;
    char ignore, answer;
    
    do
    {
        printf("Enter a number: ");
        scanf("%lf", &array[i]);
        sum+=array[i];
        average=sum/num;
        for(int j=0; j<num; ++j)
        {
            printf("You entered: %lf\n", array[j]);
        }
        printf("Updated average is: %lf\n", average);
        scanf("%c", &ignore); // used to ignore the newline character
        printf("Enter more numbers? (Y/N): ");
        scanf("%c", &answer);
        if(answer=='y'||answer=='Y')
        {
            repeat = true;
            ++num, ++i;
            array=realloc(array, sizeof(double)*num); // realloc function reallocates memory to a larger block to store more data
        }
        else
        {
            repeat = false;
        }
    }while(repeat);

    free(array); // C-method equivalent of delete [] array
    
    return 0;
}