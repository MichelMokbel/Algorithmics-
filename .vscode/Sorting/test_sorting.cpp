#include <iostream>
#include "sorting.cpp"

using namespace std;

int main()
{
    // // Test selection sort
    sorting<int> s(5);
    int arr1[5] = {3, 1, 4, 2, 5};
    // s.selectionSort(arr1, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout << endl;

    // // Test insertion sort
    // int arr2[5] = {3, 1, 4, 2, 5};
    // s.insertionSort(arr2, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;

    // // Test bubble sort
    // int arr3[5] = {3, 1, 4, 2, 5};
    // s.bubbleSort(arr3, 5);
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arr3[i] << " ";
    // }
    // cout << endl;
    // Test inverse selection sort
    s.inverseBubbleSort(arr1, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    return 0;
}

// // Test inverse selection sort
// int arr4[5] = {3, 1, 4, 2, 5};
// s.inverseSelectionSort(arr4, 5);
// for (int i = 0; i < 5; i++)
// {
//     cout << arr4[i] << " ";
// }
// cout << endl;

// int arr5[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
// s.inverseSelectionSort(arr5, 10);
// for (int i = 0; i < 10; i++)
// {
//     cout << arr5[i] << " ";
// }
// cout << endl;

// int arr6[1] = {1};
// s.inverseSelectionSort(arr6, 1);
// for (int i = 0; i < 1; i++)
// {
//     cout << arr6[i] << " ";
// }
// cout << endl;