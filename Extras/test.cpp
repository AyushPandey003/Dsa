#include <iostream>
#include <algorithm> // Include the algorithm library for the sort function
using namespace std;

int main()
{
    int arr[] = {5, 2, 8, 1, 9}; // Example array

    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array

    sort(arr, arr + n); // Sort the array using the sort function

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
