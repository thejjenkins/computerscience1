#include <iostream>
using namespace std;

int main ()
{
	int stop, result, a, b;

	cin >> stop;
	result = 0;

	for (a=0;a<3;++a)
	{
		cout << a << ": ";
		for (b=0;b<2;++b)
		{
			result += a+b;
			if (result>stop)
			{
				cout << "_ ";
				continue;
			}
			cout << result << ",";
		}
		cout << endl;
	}
	return 0;
}
