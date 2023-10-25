#include <iostream>

using namespace std;
/*
A pointer is a variable whose value is a memory address.

Types of Pointer:
    int  *xPtr;
    char *yPtr;
    void *zPtr;

Pointer Declaration:
1-  int *p1;
    p1 = 8;
2-  int i;
    int *ip = &i;
3-  int *ip;
    ip = new int;



*/

int main()
{
    int intVar = 10;
    int *intPtr; // intPtr is a pointer
    intPtr = &intVar;
    cout << "\nLocation of intVar: " << &intVar;
    cout << "\nContents of intVar: " << intVar;
    cout << "\nLocation of intPtr: " << &intPtr; //This is the address of the intVar
    cout << "\nContents of intPtr: " << intPtr;
    cout << "\nThe value that intPtr points to: " << *intPtr;
}