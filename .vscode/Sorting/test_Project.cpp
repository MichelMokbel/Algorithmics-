#include <iostream>
#include <cassert>

using namespace std;

void printArray(int arr[], int n, string msg)
{
    cout << msg << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// // FILEPATH: /C:/Users/User/C++/.vscode/Sorting/Project.cpp
// void countingSort(int *arr, int n)
// {
//     int *A = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         A[i] = arr[i];
//     }

//     int maxVal = A[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (A[i] > maxVal)
//         {
//             maxVal = A[i];
//         }
//     }

//     int *B = new int[n];

//     // int* C = new int[maxVal];

//     int *C = new int[maxVal + 1];

//     for (int i = 0; i <= maxVal; i++)
//     {
//         C[i] = 0;
//     }
//     for (int j = 0; j < n; j++)
//     {
//         C[A[j]] = C[A[j]] + 1;
//     }
//     for (int i = 1; i <= maxVal; i++)
//     {
//         C[i] = C[i] + C[i - 1];
//     }
//     for (int j = n - 1; j >= 0; j--)
//     {
//         B[C[A[j]] - 1] = A[j];
//         C[A[j]] = C[A[j]] - 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = B[i];
//     }
// }

// void display(int* arr, int n) {
//     for (int i = 0; i < n; i++) {
//         std::cout << arr[i] << " ";
//     }
//     std::cout << std::endl;
// }

void countingSort(int *arr, int n)
{
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = arr[i];
    }
    printArray(A, n, "Original Array");

    int maxVal = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > maxVal)
        {
            maxVal = A[i];
        }
    }

    int *B = new int[n];
    int *C = new int[maxVal + 1];

    for (int i = 0; i <= maxVal; i++)
    {
        C[i] = 0;
    }
    printArray(C, maxVal + 1, "Initialized Count Array");
    for (int j = 0; j < n; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }
    printArray(C, maxVal + 1, "Populated Count Array");
    for (int i = 1; i <= maxVal; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    printArray(C, maxVal + 1, "Modified Count Array");
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }
    printArray(B, n, "Sorted Array in Counting Sort");

    for (int i = 0; i < n; i++)
    {
        arr[i] = B[i];
    }
}

void radixSort(int *arr, int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // Sort the array based on each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        countingSort(arr, n);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printArray(arr, n, "Final Sorted Array");

    return 0;
}

// int main()
// {
//     int arr1[] = {5, 2, 9, 5, 2, 3};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     countingSort(arr1, n1);
//     display(arr1, n1);

// for (int i = 0; i < n1 - 1; i++)
// {
//     assert(arr1[i] <= arr1[i + 1]);
// }

// int arr2[] = {1, 1, 1, 1, 1, 1};
// int n2 = sizeof(arr2) / sizeof(arr2[0]);
// countingSort(arr2, n2);
// for (int i = 0; i < n2 - 1; i++)
// {
//     assert(arr2[i] <= arr2[i + 1]);
// }

// int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
// int n3 = sizeof(arr3) / sizeof(arr3[0]);
// countingSort(arr3, n3);
// for (int i = 0; i < n3 - 1; i++)
// {
//     assert(arr3[i] <= arr3[i + 1]);
// }

// std::cout << "All test cases passed!\n";
// return 0;
// }
// void testRadixSort() {
//     int arr1[] = {5, 2, 9, 5, 2, 3};
//     int n1 = sizeof(arr1) / sizeof(arr1[0]);
//     radixSort(arr1, n1);
//     for (int i = 0; i < n1 - 1; i++)
//     {
//         assert(arr1[i] <= arr1[i + 1]);
//     }

//     int arr2[] = {1, 1, 1, 1, 1, 1};
//     int n2 = sizeof(arr2) / sizeof(arr2[0]);
//     radixSort(arr2, n2);
//     for (int i = 0; i < n2 - 1; i++)
//     {
//         assert(arr2[i] <= arr2[i + 1]);
//     }

//     int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
//     int n3 = sizeof(arr3) / sizeof(arr3[0]);
//     radixSort(arr3, n3);
//     for (int i = 0; i < n3 - 1; i++)
//     {
//         assert(arr3[i] <= arr3[i + 1]);
//     }
// }

// int main()
// {
//     testRadixSort();
//     std::cout << "All test cases passed!\n";
//     return 0;
// }