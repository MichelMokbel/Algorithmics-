#include <iostream>
#include <cassert>

using namespace std;



// void countingSort(int *arr, int n)
// {
//     int *A = new int[n];
//     for (int i = 0; i < n; i++)
//     {
//         A[i] = arr[i];
//     }
//     printArray(A, n, "Original Array");

//     int maxVal = A[0];
//     for (int i = 1; i < n; i++)
//     {
//         if (A[i] > maxVal)
//         {
//             maxVal = A[i];
//         }
//     }

//     int *B = new int[n];
//     int *C = new int[maxVal + 1];

//     for (int i = 0; i <= maxVal; i++)
//     {
//         C[i] = 0;
//     }
//     printArray(C, maxVal + 1, "Initialized Count Array");
//     for (int j = 0; j < n; j++)
//     {
//         C[A[j]] = C[A[j]] + 1;
//     }
//     printArray(C, maxVal + 1, "Populated Count Array");
//     for (int i = 1; i <= maxVal; i++)
//     {
//         C[i] = C[i] + C[i - 1];
//     }
//     printArray(C, maxVal + 1, "Modified Count Array");
//     for (int j = n - 1; j >= 0; j--)
//     {
//         B[C[A[j]] - 1] = A[j];
//         C[A[j]] = C[A[j]] - 1;
//     }
//     printArray(B, n, "Sorted Array in Counting Sort");

//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = B[i];
//     }
// }

int getMax(int *arr, int n)
{
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void printArray(int arr[], int n, string msg)
{
    cout << msg << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}



void radixCountingSort(int *arr, int n, int exp)
{
    
    cout << endl;
    cout << "Sorted array for exp = " << exp << endl;
    cout << endl;
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = arr[i];
    }
    printArray(A, n, "Original Array");

    int *B = new int[n];
    int *C = new int[10];

    // Initialize Count Array to 0 for all values
    for (int i = 0; i < 10; i++)
    {
        C[i] = 0;
    }
    printArray(C, 10, "Initialized Count Array");

    // Populate Count Array with the number of times each value appears
    for (int j = 0; j < n; j++)
    {
        C[(A[j] / exp) % 10]++;
    }
    printArray(C, 10, "Populated Count Array");

    // Modify Count Array to show the number of values less than or equal to each value
    for (int i = 1; i < 10; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    printArray(C, 10, "Modified Count Array");

    // Sort the array based on the digit at the current exp value
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[(A[j] / exp) % 10] - 1] = A[j];
        C[(A[j] / exp) % 10]--;
    }
    // printArray(B, n, "Sorted Array in Counting Sort");

    // Copy the sorted array back into the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = B[i];
    }



    
    printArray(arr, n, "Final Sorted Array");
}

void radixSort(int *arr, int n)
{
    int maxVal = getMax(arr, n);

    // Sort the array based on each digit
    for (int exp = 1; maxVal / exp > 0; exp *= 10)
    {
        radixCountingSort(arr, n, exp);
    }
}

int main()
{
    int arr[] = {
        170,
        45,
        75,
        90,
        802,
        24,
        2,
        66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);


    return 0;
}
