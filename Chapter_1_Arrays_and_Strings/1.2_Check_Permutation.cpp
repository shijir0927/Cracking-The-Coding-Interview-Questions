/*Given two strings write a method to decide if one is permutation of the other.*/
#include <iostream>
#include <algorithm>
using namespace std;
/*Solution:
Since permutations are just the same letters in a 
different order, we can sort the 2 strings and compare
each letter.*/
bool isPermutation(string s1, string s2)
{
    //Permutations has to have the same length
    if (s1.length() != s2.length())
        return false;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
            return false;
    }

    return true;
}

int main()
{

    string s1, s2;

    cout << "Please enter 2 strings: ";
    cin >> s1 >> s2;

    isPermutation(s1, s2) ? cout << "Is permutation!" : cout << "Is not permutation!";

    return 0;
}