/*
This program is supposed to calculate your current grade in a class based on the weight of each assignment and how many you have completed.
Algorithm:
1. Get weight of each category
2. Get number of assignments in each
3. Input grades received for each assignment under each category.
4. Add all and divide by the number of grades entered.
5. Multiply by weight.
6. Add together for current grade.
*/
#include "gradecalcheader.h"

int main() 
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	//getData(students);

	for (int i=0; i<WEIGHT; ++i)
	{
		students.percentweight[i]*=0.01;
	}

	if(students.completed[0]>0)
	{
		double sumHW=0;
		cout << "Enter each homework grade received: ";
		for (int i = 0; i < students.completed[0]; ++i)
		{
			cin >> students.homeworkgrades[i];
			sumHW+=students.homeworkgrades[i];
		}
		students.finalgrades[0]=students.percentweight[3]*(sumHW/students.completed[0]);
	}
	if(students.completed[1]>0)
	{
		double sumQuiz=0;
		cout << "Enter each quiz grade received: ";
		for (int i=0; i<students.completed[1]; ++i)
		{
			cin >> students.quizgrades[i];
			sumQuiz+=students.quizgrades[i];
		}
		students.finalgrades[1]=students.percentweight[4]*(sumQuiz/students.completed[1]);
	}
	if(students.completed[2]>0)
	{
		double sumExams=0;
		cout << "Enter each exam grade received: ";
		for (int i=0; i<students.completed[2]; ++i)
		{
			cin >> students.examgrades[i];
			sumExams+=students.examgrades[i];
		}
		students.finalgrades[2]=students.percentweight[2]*(sumExams/students.completed[2]);
	}
	char answer;
	cout << "Have you taken the midterm exam? (Y/N): "; cin>>answer;
	answer = toupper(answer);
	if (answer == 'Y')
	{
		cout << "Enter grade received: "; cin >> students.finalgrades[3];
		students.finalgrades[3]*=students.percentweight[1];
	}
	cout << "Have you taken the final exam? (Y/N): "; cin>>answer;
	answer=toupper(answer);
	if (answer == 'Y')
	{
		cout << "Enter grade received: "; cin>>students.finalgrades[4];
		students.finalgrades[4]*=students.percentweight[0];
	}
	double sumgrades = 0;
	for (int i=0; i<WEIGHT; ++i)
	{
		sumgrades+=students.finalgrades[i];
	}
	cout << "Course grade is: " << sumgrades << endl; // FIXME: not a percentage. just the sum of all weighted scores.

	return 0;
}
