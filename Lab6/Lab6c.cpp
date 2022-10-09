/* Author: James Jenkins (jamesjenkins2@my.unt.edu)
 * Date: 10 October 2021
 * Instructor: Dr. Pradhumna Shrestha
 * Description: This program sorts characters. */

#include <iostream>
using namespace std;
int main()
{
	char arr[]={'b', 'f', 'a', 'z', 'm', 'g', 'q', 't'};
	for (int i = 0; i<8; ++i)
	{
		for (int j=i+1; j<8; ++j)
		{
			if (arr[i]<arr[j])
			{
				char temp = arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	for (int i=0; i<8; ++i)
	{
		cout << arr[i]<< '\t';
	}
	cout << endl;
	return 0;
}
