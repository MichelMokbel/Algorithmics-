#include<iostream>
using namespace std;

void printArray(int arr[], int n, string msg) {
    cout << msg << ": ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countingSort(int *arr, int n) {
    int *A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = arr[i];
    }
    printArray(A, n, "Original Array");

    int maxVal = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > maxVal) {
            maxVal = A[i];
        }
    }

    int *B = new int[n];
    int *C = new int[maxVal + 1];

    for (int i = 0; i <= maxVal; i++) {
        C[i] = 0;
    }
    printArray(C, maxVal + 1, "Initialized Count Array");

    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] + 1;
    }
    printArray(C, maxVal + 1, "Populated Count Array");

    for (int i = 1; i <= maxVal; i++) {
        C[i] = C[i] + C[i - 1];
    }
    printArray(C, maxVal + 1, "Modified Count Array");

    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    printArray(B, n, "Sorted Array in Counting Sort");

    for (int i = 0; i < n; i++) {
        arr[i] = B[i];
    }

    delete[] A;
    delete[] B;
    delete[] C;
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    countingSort(arr, n);
    printArray(arr, n, "Final Sorted Array");
    return 0;
}