#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 5;
enum MENU {Add = 1, Remove = 2, Display = 3, Search = 4, Results = 5, Quit = 6};
struct Student 
{
    string fname, lname;
    string id;
    int numteststaken;
    int* tests = new int[NUM_TESTS];
    double average;
};
int getNumber();
void add_student(Student& allstudents);
void remove_student(string studentid);
void display();
void search(string studentid);
//void exportResults();
//int findMinimum();