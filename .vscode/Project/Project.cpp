#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

void printArray(int arr[], int n, string msg)
{
    cout << msg << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

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

    // Max value in the array
    int maxVal = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    // get the number of digits from the max number
    int numDigits = 0;
    while (maxVal > 0)
    {
        numDigits++;
        maxVal /= 10;
    }

    int *tempArr = new int[n];
    int *countArr = new int[10];

    int divisor = 1;
    for (int i = 0; i < numDigits; i++)
    {

        // for (int i = 0; i <= maxVal; i++)
        // {
        //     C[i] = 0;
        // }

        for (int j = 0; j < 10; j++)
        {
            countArr[j] = 0;
        }

        for (int j = 0; j < n; j++)
        {
            int digit = (arr[j] / divisor) % 10;
            countArr[digit]++;
        }

        for (int j = 1; j < 10; j++)
        {
            countArr[j] += countArr[j - 1];
        }

        for (int j = n - 1; j >= 0; j--)
        {
            int digit = (arr[j] / divisor) % 10;
            tempArr[countArr[digit] - 1] = arr[j];
            countArr[digit]--;
        }

        for (int j = 0; j < n; j++)
        {
            arr[j] = tempArr[j];
        }

        divisor *= 10;
    }

    delete[] tempArr;
    delete[] countArr;
}

void display(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    display(arr, n);

    return 0;
}
