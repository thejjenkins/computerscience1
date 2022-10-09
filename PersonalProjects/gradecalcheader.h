#include <iostream>
#include <string>
using namespace std;

const int WEIGHT = 6;
const int COMPLETED = 3;
const int HWGRADES = 30;
const int QUIZGRADES = 15;
const int EXAMGRADES = 4;
const int FINALGRADES = 6;
/*
int* array1;
int* array2;
*/

/*
string fullname;
double percentweight[WEIGHT];
int completed[COMPLETED];
double homeworkgrades[HWGRADES];
double quizgrades[QUIZGRADES];
double examgrades[EXAMGRADES];
double finalgrades[FINALGRADES];
*/

struct Students
{
	string fullname;
	double percentweight[WEIGHT];
	int completed[COMPLETED];
	double homeworkgrades[HWGRADES];
	double quizgrades[QUIZGRADES];
	double examgrades[EXAMGRADES];
	double finalgrades[FINALGRADES];
}students;

students getData(students& students);