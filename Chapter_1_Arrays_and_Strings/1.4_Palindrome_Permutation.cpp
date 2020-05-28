/*Question: Write a function that determines if a string 
is a permutation of a palindrome.*/
#include <iostream>
using namespace std;
/*Solution:
Go throught the string and count how many of each letter there
are. And check if all the letters have a even number(even case) or all
the letters have even number except one(odd case).*/

int getCharIndex(char c)
{
    int idx = -1;
    if (c >= 'a' && c <= 'z')
    {
        idx = c - 'a';
    }
    else if (c >= 'A' && c <= 'Z')
    {
        idx = c - 'A';
    }
    return idx;
}

bool isPermutationOfPalindrome(string &s)
{
    int oddCount = 0;
    int frequency[26] = {0};
    int idx = 0;
    for (const char &c : s)
    {
        idx = getCharIndex(c);
        if (idx != -1)
        {
            ++frequency[idx];
            if (frequency[idx] % 2)
            {
                ++oddCount;
            }
            else
            {
                --oddCount;
            }
        }
    }
    return (oddCount <= 1);
}

int main()
{

    string s;
    cout << "Please enter a string: ";
    cin >> s;

    isPermutationOfPalindrome(s) ? cout << "Is permutation of palindrome!" : cout << "No!";

    return 0;
}