/*Question: Implement a method to perform string compression using 
the counts of repeated characters.*/
#include <iostream>
using namespace std;
/*Solution:
Go through the string and check if the current character is the
same as the previous character. And concat the output string 
depending on the comparision.
*/

string compress(string s)
{
    string output = "";
    int count = 1;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1])
        {
            ++count;
        }
        else
        {
            output += s[i - 1];
            output += to_string(count);
            count = 1;
        }
    }

    output += s[s.length() - 1];
    output += to_string(count);

    return output.length() < s.length() ? output : s;
}

int main()
{

    string s;
    cout << "Please enter a string: ";
    cin >> s;

    cout << compress(s);

    return 0;
}