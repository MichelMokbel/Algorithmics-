#include <iostream>
#include <cassert>

using namespace std;

class Sorting
{
public:
    void radixSort(int *arr, int n);

private:
    int getMax(int *arr, int n);
    void radixCountingSort(int *arr, int n, int exp);
    void printArray(int arr[], int n, string msg);
    void countingSort(int *arr, int n);
};

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

int search(int *arr, int n, int m)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == m)
        {
            return i;
        }
    }
    return -1;;
}

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

    int maxVal = getMax(arr, n);

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
    // int arr1[] = {170, 45, 75, 90, 802, 24, 2, 66};
    // int n1 = sizeof(arr1) / sizeof(arr1[0]);
    // countingSort(arr1, n1);

    // int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // int n2 = sizeof(arr2) / sizeof(arr2[0]);
    // radixSort(arr2, n2);

    // int arr3[] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 0};
    // int n3 = sizeof(arr3) / sizeof(arr3[0]);
    // radixSort(arr3, n3);

    int arr4[] = {1235, 0, 1, 555, 1899, 42};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    radixSort(arr4, n4);

    // int arr[] = {10, 45, 75, 90, 82, 24, 2, 66};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // countingSort(arr, n);

    return 0;
}
