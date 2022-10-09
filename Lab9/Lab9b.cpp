/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 2 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program reads all characters including whitespaces and endlines from a file and outputs them to a different file.
*/
#include <iostream>
#include <fstream> // library needed for reading and writing to files
#include <cstdlib>
using namespace std;

int main()
{
    char c;
    ifstream in_s; // ifstream is the data type (like int or double) and in_s is the variable name (like int x or double my_dbl)
    ofstream out_s; // ofstream is the output file stream used to write to files. ifstream is the input file stream used to read from files.

    char input_file[15]; // character array of the name of the file
    char output_file[15];
    cout << "Enter the name of the input file: "; cin >> input_file;
    cout << "Enter the name of the output file: "; cin >> output_file;

    in_s.open(input_file); // syntax necessary to open the file
    if(in_s.fail()) // checks if the file opened or not. This is a bool variable, so if there is a failure it returns true and the if branch executes.
    {
        cout << "Unable to open input file: " << input_file << endl; // Error message
        exit(EXIT_FAILURE); // exits the program immediately
    }
    out_s.open(output_file); // syntax necessary to open the file
    if(out_s.fail()) // since the user enters the output file name this branch will never execute. This is because the user can enter any file name and when the program compiles and runs it will create the file under that name or if the file already exists it will overwrite whatever is written in the file.
    {
        cout << "Unable to open output file: " << output_file << endl;
        exit(EXIT_FAILURE);
    }

    while (!in_s.eof()) // eof is a function that returns a bool variable. If the end of file function returns true, then the loop continues to execute because of the ! (inverter).
    {
        in_s.get(c); // get(c) is a member function that gets all characters from the file including whitespaces and endlines.
        out_s.put(c); // put(c) prints each character into a file
    }
    

    in_s.close(); // all files MUST be closed at the end of program otherwise they will remain open and possibly prevent access to someone else.
    out_s.close();

    return 0;
}