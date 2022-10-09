#include <iostream>
#include <ctime>
#include <string>
using namespace std;

int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	srand(time(NULL));
	bool repeat = true;
	int random1 = (rand())%1001+1000;
	int i, numproperties, choice, currentproperty=1;
	double commercialbase, residentialbase, commercialremainder, residentialremainder, basetax, remaindertax, taxexemption, totaltax = 0;
	const double TAXRATE1 = 0.035, TAXRATE2 = 0.05;
	const int ACCOUNT_LENGTH = 6;
	string nameonaccount, accountnumber;
	enum Properties {Commercial = 1, Residential = 2};
	Properties propertytype;
	
	cout << "Computer Science and Engineering" << endl;
	cout << "CSCE 1030 - Computer Science I" << endl;
	cout << "James Jenkins 11006266 jamesjenkins2@my.unt.edu" << endl << endl;
	do
	{
		cout << "Please enter the name on the account: "; getline(cin, nameonaccount);
		for (i = 0; i<nameonaccount.size(); ++i)
		{
			char char1 = nameonaccount[i];
			if ((isalpha(char1) || char1 == ' '))
			{
				repeat = false;
			}
			else
			{
				cout << "The name on the account should only contain letters and spaces. Please try again.\n";
				repeat = true;
				break;
			}
		}
	}while(repeat);
	
	do
	{
		cout << "Please enter the account number: "; cin >> accountnumber;
		for (i = 0; i<accountnumber.size(); ++i)
		{
			char char2 = accountnumber[i];
			if (accountnumber.size() == ACCOUNT_LENGTH)
			{
				if (isalnum(char2))
				{
					repeat = false;
				}
				else
				{
					cout << "The account number should only contain letters and numbers. Please try again.\n";
					repeat = true;
					break;
				}
			}
			else
			{
				cout << "The account number is 6 characters long and only contains letters and numbers. Please try again.\n";
				repeat = true;
				break;
			}
		}
	}while(repeat);

	do
	{
		cout << "How many properties would you like to process? "; cin >> numproperties;
		if (numproperties < 0)
		{
			cout << "Please enter a positive number.\n";
			repeat = true;
		}
		else
		{
			repeat = false;
		}
	}while(repeat);
	
	do
	{
		do
		{
		cout << "Processing property #" << currentproperty << ". Enter 1 if it is Commercial or 2 if it is Residential: ";
		cin >> choice;
		propertytype = static_cast<Properties>(choice);
		switch (propertytype)
		{
			case 1:
				cout << "Please enter the value of the commercial property: "; cin >> commercialbase;
				if (commercialbase < 1000000)
				{
					basetax = commercialbase*TAXRATE1;
					totaltax = totaltax + basetax;
					cout << "Taxes owed for property #" << currentproperty << ": $" << basetax << endl;
					repeat = false;
				}
				else if (commercialbase >= 1000000)
				{
					basetax = (TAXRATE1*1000000);
					commercialremainder = commercialbase - 1000000;
					remaindertax = commercialremainder*TAXRATE2;
					cout << "Taxes owed for property #" << currentproperty << ": $" << basetax + remaindertax << endl;
					totaltax = totaltax + basetax + remaindertax;
					repeat = false;
				}
				break;
			case 2:
				cout << "Please enter the value of the residential property: "; cin >> residentialbase;
				if (numproperties == 1)
				{
					if (residentialbase < 100000)
					{
						basetax = static_cast<int>(0);
						cout << "Taxes owed for property #" << currentproperty << ": $" << basetax << endl;
						totaltax = totaltax + basetax;
						repeat = false;
					}
					else if (residentialbase >= 100000)
					{
						basetax = static_cast<int>(0);
						residentialremainder = residentialbase - 100000;
						remaindertax = residentialremainder*TAXRATE1;
						totaltax = totaltax + basetax + remaindertax;
						taxexemption = (rand()%1001)+1000;
						if (taxexemption > totaltax)
						{
							totaltax = static_cast<int>(0);
							cout << "Taxes owed for property #" << currentproperty << ": $" << totaltax << endl;
							repeat = false;
						}
						else
						{
							cout << "Taxes owed for property #" << currentproperty << ": $" << remaindertax << endl;
							cout << "Tax exemption: $" << taxexemption << endl;
							totaltax = totaltax - taxexemption;
							cout << "Updated taxes owed for property #" << currentproperty << ": $" << totaltax << endl;
							repeat = false;
						}
					}
				}
				else if (residentialbase < 100000)
				{
					basetax = static_cast<int>(0);
					cout << "Taxes owed for property #" << currentproperty << ": $" << basetax << endl;
					totaltax = totaltax + basetax;
					repeat = false;
				}
				else if (residentialbase >= 100000)
				{
					basetax = static_cast<int>(0);
					residentialremainder = residentialbase - 100000;
					remaindertax = residentialremainder*TAXRATE1;
					cout << "Taxes owed for property #" << currentproperty << ": $" << remaindertax << endl;
					totaltax = totaltax + basetax + remaindertax;
					repeat = false;
				}
				break;
			default:
				cout << "Input only accepts 1 for commercial and 2 for residential." << endl;
				repeat = true;
		}
		}while(repeat);
	++currentproperty;
	}while(currentproperty <= numproperties);
	"\n";

	nameonaccount.at(0)=toupper(nameonaccount.at(0));
	for (int i=0; i<nameonaccount.size(); ++i)
	{
		if (nameonaccount[i]==' ')
		{
			nameonaccount.at(i+1)=toupper(nameonaccount.at(i+1));
		}
	}

	cout << "Name: " << nameonaccount << endl;
	cout << "Account number: " << accountnumber << endl;
	cout << "Total taxes owed: $" << totaltax << endl;
return 0;
}
