#include <iostream>
using namespace std;

int main ()
{
	int lower, upper;
	bool repeat = true;
	char answer;
	
	do
	{
		cout << "Please enter lower bound: "; cin >> lower;
		cout << "Please enter upper bound: "; cin >> upper;
		for (int i = lower; i <= upper; ++i)
		{
			if ((i!=lower) && (i!=upper) && ((i%5)!=0) && ((i%2)!=0))
			{
				cout << i << endl;
			}
		}
		cout << "Would you like use different bounds? (Y/N): "; cin >> answer;
		answer = toupper(answer);
		if (answer == 'Y')
		{
			repeat = true;
		}
		else
		{
			repeat = false;
		}
	}while(repeat);
	return 0;
}