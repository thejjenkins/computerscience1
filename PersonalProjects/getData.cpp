#include "gradecalcheader.h"

students getData(students& student)
{
	//cout << "How many homework assignments have you completed?";
	//cin >> num1;
    cout << "Enter the percentage weight of final: ";
	cin >> student.percentweight[0];
	cout << "Enter the percentage weight of midterm: ";
	cin >> student.percentweight[1];
	cout << "Enter the percentage weight of exams: ";
	cin >> student.percentweight[2];
	cout << "Enter the percentage weight of homework: ";
	cin >> student.percentweight[3];
	cout << "Enter the percent weight of quizzes: ";
	cin >> student.percentweight[4];
	cout << "Enter the percent weight of attendance:";
	cin >> student.percentweight[5];
	
	cout << "How many homework assignments have you completed? ";
	cin >> student.completed[0];
	cout << "How many quizzes have you taken? ";
	cin >> student.completed[1];
	cout << "How many ordinary exams (not midterm or final) have you completed? ";
	cin >> student.completed[2];

    return student;
}