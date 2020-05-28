/*Question: Given an image represented by NxN matrix, where
each pixel in the image is 4 bytes, wirte a method to rotate
the image by 90 degrees. Do this in place.*/
#include <iostream>
using namespace std;
/*Solution:
Since it's NxN we can find the transpose of the matrix
and flip the collumns.
*/

void helper_transpose(int **matrix, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
}

void helper_reverse(int *row, int N)
{
    for (int i = 0; i < N / 2; ++i)
    {
        swap(row[i], row[N - i - 1]);
    }
}

void rotate(int **matrix, int N)
{
    //transpose matrix
    helper_transpose(matrix, N);
    // reverse each row
    for (int i = 0; i < N; ++i)
    {
        helper_reverse(matrix[i], N);
    }
}

void printMatrix(int **matrix, int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int N;

    cout << "Enter N for NxN matrix:";
    cin >> N;
    int **matrix = new int *[N];
    for (int i = 0; i < N; ++i)
    {
        matrix[i] = new int[N];
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Given matrix:" << endl;
    printMatrix(matrix, N);
    cout << "Rotated matrix:" << endl;
    rotate(matrix, N);
    printMatrix(matrix, N);

    return 0;
}