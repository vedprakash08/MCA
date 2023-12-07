#include <iostream>
#include <algorithm>
using namespace std;

/*  A. Write C++ program  to find and remove duplicate elements from an array.  */

void findDuplicates(int arr[], int n)
{
    // remove duplcates
    cout << "Duplicates are" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                if (arr[j] != -1)
                    cout << arr[j] << " ";
                arr[j] = -1;
            }
        }
    }

    // printing the updated array
    cout << endl
         << "Updated array is " << endl;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != -1)
            cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = {1, 3, 3, 5, 4, 3, 2, 2, 6};
    int n = sizeof(arr) / sizeof(int);
    findDuplicates(arr, n);
    return 0;
}