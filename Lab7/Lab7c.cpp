/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 19 October 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program compares the ASCII sum of two strings. 
*/

#include <iostream>
#include <string>
using namespace std;

/*
Function: bool isLarger
Parameters: a string str1 and a string str2
Return: A boolean value
Description: The function uses a for loop to add up all of the ASCII values of each string and then compares the ASCII sums. If str1 has a larger ASCII sum then the bool value is true. If str2 has a larger ASCII sum then the bool value is false.
*/
bool isLarger(string str1, string str2)
{
    bool larger; // bool larger must be declared in both the function() and main()
    int str1len = str1.size(); // these integers are used to determine the bounds of the for loops
    int str2len = str2.size();
    int asciisum1=0; // initialize and declare the ASCII sum of each string to be 0.
    int asciisum2=0;

    for (int i=0; i<str1len; ++i)
    {
        asciisum1=asciisum1+str1.at(i); // Each ASCII value is added to the sum for each iteration of the loop
    }
    
    for (int i=0; i<str2len; ++i)
    {
        asciisum2=asciisum2+str2.at(i);
    }
    cout << "ASCII sum 1: " << asciisum1 << endl;
    cout << "ASCII sum 2: " << asciisum2 << endl;

    if (asciisum1>asciisum2)
    {
        larger = true;
    }
    else
    {
        larger = false;
    }
    return larger; // return the bool value
}
int main()
{
    string str1, str2;
    bool larger; // bool larger must be declared in both the function() and main()
    
    cout << "Enter string 1: "; getline(cin, str1); // getline enables spaces to be included
    cout << "Enter string 2: "; getline(cin, str2);

    larger = isLarger(str1, str2); // larger is declared as the functions return value.

    if (larger) // if the function returns true
    {
        cout << "String 1 has the greater ASCII sum." << endl;
    }
    else // if the function returns false
    {
        cout << "String 2 has the greater ASCII sum." << endl;
    }

    return 0;
}