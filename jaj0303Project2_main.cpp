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

int getNumber()
{
	ifstream fin;
	fin.open("student.dat");
	if (fin.fail())
	{
		cout<<"File error."<<endl;
		exit(1);
	}
	int count=0;
	string line;
	while(!fin.eof())
	{
		getline(fin, line);
		++count;
	}
	
	fin.close();
	return(count);
}

void add_student(Student& allstudents)
{
    cin.ignore();
    cout << "Enter first name: "; getline(cin, allstudents.fname);
    cout << "Enter last name: "; getline(cin, allstudents.lname);
    cout << "Enter student ID: "; cin >> allstudents.id;
    cout << "Enter number of tests taken: "; cin >> allstudents.numteststaken;
    for (int i=0; i<allstudents.numteststaken; ++i)
    {
        cout << "Enter score for test #" << i+1 << ": "; cin>>*(allstudents.tests+i);
    }

    ofstream dest;
    dest.open("student.dat", ios::app);
    if (dest.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }
    dest<<"\n"<<allstudents.lname<<","<<allstudents.fname<<","<<allstudents.id<<","<<allstudents.numteststaken<<",";
    for (int i=0; i<allstudents.numteststaken; ++i)
    {
        dest << *(allstudents.tests+i) <<",";
    }
    dest.close();
    delete [] allstudents.tests;
}

void remove_student(string studentid)
{
    bool found=false;
    ifstream source;
    int currentstudents = getNumber();

    cout << currentstudents << " students in file." << endl;
    Student* allstudents;
    allstudents = new Student[currentstudents];
    source.open("student.dat");

    if(source.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }
   for (int k=0; k<currentstudents; ++k) // this loop is for reading the file
    {
       getline(source, allstudents[k].lname, ',');
       getline(source, allstudents[k].fname, ',');
       getline(source, allstudents[k].id, ',');
       string temp2;
       getline(source, temp2, ',');
       allstudents[k].numteststaken = stoi(temp2);
       allstudents[k].tests = new int[allstudents[k].numteststaken];
       for (int i=0; i<allstudents[k].numteststaken; ++i)
       {
           string temp3;
           getline(source, temp3, ',');
           int value = stoi(temp3);
           allstudents[k].tests[i] = value;
       }
       string temp1 = allstudents[k].id;
       int fileid = stoi(temp1), mainid = stoi(studentid);
       if(fileid == mainid)
       {
           found = true;
       }
       else
       {
           found = false;
       }
   }
   source.close();
   if(found)
   {
       ofstream dest;
       dest.open("student.dat");
       if(dest.fail())
       {
           cout << "Error opening file." << endl;
           exit(1);
       }
       for (int k=0; k<currentstudents; ++k)
        {
            if (allstudents[k].id==studentid)
            {
                continue;
            }
            else
            {
                dest << allstudents[k].lname << "," << allstudents[k].fname << "," << allstudents[k].id << "," << allstudents[k].numteststaken << ",";
                for (int h=0; h<allstudents[k].numteststaken; ++h)
                {
                   dest << allstudents[k].tests[h] << ",";
                }
            }
            
        }
       dest.close();
    }
    else
    {
        cout << "No matching student." << endl;
    }
    for (int i=0; i<currentstudents; ++i)
    {
        delete [] allstudents[i].tests;
    }
    delete [] allstudents;
}

void display()
{
    ifstream source;
    int currentstudents = getNumber();
    Student* allstudents;
    allstudents = new Student[currentstudents];
    source.open("student.dat");
    if (source.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }
    for (int k=0; k<currentstudents; ++k) // this loop is for reading the file
    {
       getline(source, allstudents[k].lname, ',');
       getline(source, allstudents[k].fname, ',');
       getline(source, allstudents[k].id, ',');
       string temp;
       getline(source, temp, ',');
       allstudents[k].numteststaken = stoi(temp);
       allstudents[k].tests = new int[allstudents[k].numteststaken];
       cout << setw(30) << (allstudents[k].lname+","+allstudents[k].fname) << setw(15) << allstudents[k].id;
       for (int i=0; i<allstudents[k].numteststaken; ++i)
       {
           string temp1;
           getline(source, temp1, ',');
           int value = stoi(temp1);
           allstudents[k].tests[i] = value;
           cout << setw(5) << allstudents[k].tests[i];
       }
    }
    cout << endl;
    for (int i=0; i<currentstudents; ++i)
    {
        delete [] allstudents[i].tests;
    }
    delete [] allstudents;
    source.close();
}

void search(string studentid)
{
    ifstream source;
    Student* allstudents = new Student;
    bool found = false;
    int currentstudents = getNumber();
    source.open("student.dat");
    if (source.fail())
    {
        cout << "Error opening file." << endl;
        exit(1);
    }
    while(!source.eof()) // this loop is for reading the file
    {
       getline(source, allstudents->lname, ',');
       getline(source, allstudents->fname, ',');
       getline(source, allstudents->id, ',');
       string temp;
       getline(source, temp, ',');
       allstudents->numteststaken = stoi(temp);
       allstudents->tests = new int[allstudents->numteststaken];
       for (int i=0; i<allstudents->numteststaken; ++i)
       {
           string temp1;
           getline(source, temp1, ',');
           int value = stoi(temp1);
           allstudents->tests[i] = value;
       }
       if(allstudents->id==studentid)
       {
           found = true;
            cout << setw(30) << (allstudents->lname+","+allstudents->fname) << setw(15) << allstudents->id;
           for (int i=0; i<allstudents->numteststaken; ++i)
           {
               cout << setw(5) << allstudents->tests[i];
           }
           cout << endl;
           break;
       }
    }
    delete allstudents;
    delete [] allstudents->tests;
    source.close();
}

// missing exportResults() and findMinimum() functions
// display() output is not working properly. Alignment is off.
// search function works but only when a match is found. Otherwise, the program crashes. 

int main()
{
    cout << "\nComputer Science and Engineering\nCSCE1030 - Computer Science I\nJames Jenkins jaj0303 jamesjenkins2@my.unt.edu\n\n";

    bool repeat=false;
    int choice;
    string studentid;
    Student allstudents;
    
    do
    {
        cout << "1. Add\n2. Remove\n3. Display\n4. Search\n5. Results\n6. Quit\n\nEnter choice (1-6): "; cin >> choice;
        switch (choice)
        {
            case 1:
                add_student(allstudents);
                break;
            case 2:
                cout << "Enter student ID: "; cin >> studentid;
                remove_student(studentid);
                break;
            case 3:
                display();
                break;
            case 4:
                cout << "Enter student ID: "; cin >> studentid;
                search(studentid);
                break;
            case 5:
               // exportResults();
                break;
            case 6:
                cout << "Goodbye.\n";
                exit(1);
            default:
                cout << "Invalid choice. Enter 1-6." << endl << endl;
                repeat = true;
                break;
        }
        repeat = true;
    }while (repeat);


    cout << endl;
    return 0;
}