#include <iostream>
using namespace std;

int main ()
{
	int a, b, c, result;

	cin >> a >> b >> c;

	result = 0;

	while (a<b) 
	{
		result = a*2;
		cout << result;
		cout << endl;

		if (result>c)
		{
			break;
		}
		a += 4;
	}
	return 0;
}
