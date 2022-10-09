#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string RemoveUpper(string input)
{
    string output;
    int num = input.size();
    for (int i=0;i<num;++i)
    {
        char ch = input.at(i);
        if (islower(ch))
        {
            output=output+ch;
        }
    }
    return output;
}

int main()
{
    string input = "AhHgTgLOOp";
    string output;

    cout << input.size() << endl;

    output = RemoveUpper(input);

    cout << output << endl;

    return 0;
}