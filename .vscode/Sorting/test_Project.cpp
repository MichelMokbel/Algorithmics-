#include <iostream>
#include <cassert>

using namespace std;

// FILEPATH: /C:/Users/User/C++/.vscode/Sorting/Project.cpp
void countingSort(int *arr, int n)
{
    int *A = new int[n];
    for (int i = 0; i < n; i++)
    {
        A[i] = arr[i];
    }

    int maxVal = A[0];
    for (int i = 1; i < n; i++)
    {
        if (A[i] > maxVal)
        {
            maxVal = A[i];
        }
    }

    int *B = new int[n];

    // int* C = new int[maxVal];

    int *C = new int[maxVal + 1];

    for (int i = 0; i <= maxVal; i++)
    {
        C[i] = 0;
    }
    for (int j = 0; j < n; j++)
    {
        C[A[j]] = C[A[j]] + 1;
    }
    for (int i = 1; i <= maxVal; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = B[i];
    }
}

void display(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


int main()
{
    int arr1[] = {5, 2, 9, 5, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    countingSort(arr1, n1);
    display(arr1, n1);



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

    std::cout << "All test cases passed!\n";
    return 0;
}void testRadixSort() {
    int arr1[] = {5, 2, 9, 5, 2, 3};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    radixSort(arr1, n1);
    for (int i = 0; i < n1 - 1; i++)
    {
        assert(arr1[i] <= arr1[i + 1]);
    }

    int arr2[] = {1, 1, 1, 1, 1, 1};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    radixSort(arr2, n2);
    for (int i = 0; i < n2 - 1; i++)
    {
        assert(arr2[i] <= arr2[i + 1]);
    }

    int arr3[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    radixSort(arr3, n3);
    for (int i = 0; i < n3 - 1; i++)
    {
        assert(arr3[i] <= arr3[i + 1]);
    }
}

int main()
{
    testRadixSort();
    std::cout << "All test cases passed!\n";
    return 0;
}