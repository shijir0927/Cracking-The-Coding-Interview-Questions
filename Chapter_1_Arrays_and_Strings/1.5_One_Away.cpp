/*Question: Write a function that determines if 2 strings are 
one edit away (insert, delete, replace).*/
#include <iostream>
using namespace std;
/*Solution:
Return false if there difference between their length is 
greater than one. Go through each string at the same time
and if there are more than one case where the s1[i] and s2[i]
are not equal then return false. Else move the shorter pointer
and then the longer pointer.*/

bool isOneAway(string s1, string s2)
{
    string a, b;
    a = s1.length() >= s2.length() ? s1 : s2;
    b = s1.length() < s2.length() ? s1 : s2;
    int len1, len2;
    len1 = a.length();
    len2 = b.length();
    if (abs(len1 - len2) > 1)
        return false;

    bool flag = false;
    for (int i = 0, j = 0; i < len1 && j < len2;)
    {
        if (a[i] != b[j])
        {
            if (flag)
                return false;

            flag = true;

            if (len1 == len2)
                i++, j++;
            else
                i++;
        }
        else
            i++, j++;
    }
    return true;
}

int main()
{

    string s, ss;
    cout << "Please enter a string: ";
    cin >> s >> ss;

    isOneAway(s, ss) ? cout << "Is one away!" : cout << "No!";

    return 0;
}