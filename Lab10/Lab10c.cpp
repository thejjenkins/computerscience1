/*
Author: James Jenkins (jamesjenkins2@my.unt.edu)
Date: 9 November 2021
Instructor: Dr. Pradhumna Shrestha
Description: This program reads a data.dat file and stores the data in a struct. Then it computes the average salary of all the salaries stored in the struct.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Employees
{
    string name;
    float salary;
};

int main()
{
    Employees* emp=new Employees;
    ifstream fin;
    fin.open("data.dat");
    if (fin.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }
    float sum = 0;
    float average = 0;
    while(!fin.eof())
    {
        getline(fin, emp->name, ',');
        fin >> emp->salary;
        sum += emp->salary;
    }
    average=sum/4;
    cout << "Average salary is: " << average << endl;
    //cout << "Sum: "<<sum<<endl;
    
    

    fin.close();
    return 0;
}