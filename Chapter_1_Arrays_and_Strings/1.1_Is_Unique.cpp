/*Implement an algorigthm to determine if a string has all unique
charachters. What if you can't use additional data structure?*/

#include <iostream>
#include <vector>
using namespace std;
/*Solution:
Creating a vector of booleans and setting the value true for 
the characters we get. If the bool value is already true,
that means there's a duplicate character.*/
bool isUnique(string s)
{
    //there are 128 unqie ASCII characters
    if (s.length() > 128)
        return false;

    vector<bool> characters(128);

    for (int i = 0; i < s.length(); i++)
    {
        int value = s[i];

        if (characters[value])
        {
            return false;
        }

        characters[value] = true;
    }
    return true;
}

int main()
{
    string word;
    cout << "Please enter a string:";
    cin >> word;

    isUnique(word) ? cout << "Unique!" << endl : cout << "Not unique!" << endl;

    return 0;
}
