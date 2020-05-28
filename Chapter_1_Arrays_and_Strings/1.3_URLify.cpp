/*Question: Write a method to replace all spaces in a string
with "%20". Assume you have enough space and given the true lenght
of the string.
EXAMPLE:
Input: "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"*/
#include <iostream>
using namespace std;
/*Solution:
create a new string of spaces with the same size as Input
then loop through the string and copy everything except spaces.
When it's a space, replace it with %20*/
void URLify(string &str, int n)
{
    string output(str.size(), ' ');

    for (int index = 0, output_index = 0; index < n; index++, output_index++)
    {
        if (str[index] != ' ')
        {
            output[output_index] = str[index];
        }
        else
        {
            output[output_index] = '%';
            output[output_index + 1] = '2';
            output[output_index + 2] = '0';
            output_index += 2; // +1 from the loop and +2 which means +3
        }
    }

    str = output;
}
int main()
{

    string s1 = "John Smith Name    ";
    int n1 = 15;
    string s2 = "My name is Shijir      ";
    int n2 = 17;

    URLify(s1, n1);
    URLify(s2, n2);

    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}