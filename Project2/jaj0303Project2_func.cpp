#include "jaj0303Project2_header.h"

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
