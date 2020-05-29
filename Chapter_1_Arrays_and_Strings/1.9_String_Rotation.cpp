/*Question: Given 2 strings, s1 and s2, write code to check
if s2 is a rotation of s1 using one call to isSubstring function.*/
#include <iostream>
using namespace std;
/*Solution:
s1s1 will always contain s2 if s2 is a sub string of s1.

s1 = xy
s2 = yx
s1s1 = xyxy = xs2y
*/

bool isSubstring(string s1, string s2)
{
    return s1.find(s2) != string::npos;
}

bool isRotation(string s1, string s2)
{
    return isSubstring(s1 + s1, s2) && s1.size() == s2.size();
}

int main()
{

    string s1, s2;

    cout << "Enter 2 strings:";
    cin >> s1 >> s2;

    isRotation(s1, s2) ? cout << "Is rotation!" : cout << "Not a rotation!" << endl;

    return 0;
}