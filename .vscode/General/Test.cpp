#include <iostream>

using namespace std;

void display(int p[]){

    for (int i = 0; i < 5; i++)
    {
        cout << "Element " << i << ":" << p[i] << endl;
    }

}

int main()
{
    // int a = 5, j;
    // int* ip = &a;
    // *ip = *ip + 7;
    // j = *ip + 1;

    // cout << "The value of ip = " <<ip<< endl;
    // cout << "The content referenced by ip = " << *ip << endl;
    // cout << "i = " << a << endl;
    // cout << "j = " << j << endl;

    int p = 8, q = 9;
    int *p1, *p2 = &q;
    p1  = &p;

    // cout << *p1 << endl;
    // cout << *p2 << endl;

    // *p1 = *p2;

    // cout << *p1 << endl;
    // cout << *p2 << endl;

    // Dynamic Allocation

    // int* p1;
    // p1 = new int;

    // cout << p1 << endl;

    // *p1 = 8;

    // cout << *p1 << endl;

    // int *p1, *p2;

    // p1 = new int;
    // *p1 = 42;
    // p2 = p1;

    // cout << *p1 << endl; // p1 = 42
    // cout << *p2 << endl; // p2 = 42

    // *p2 = 53;

    // cout << *p1 << endl; // p1 = 53
    // cout << *p2 << endl; // p2 = 53

    // p1 = new int;
    // *p1 = 88;

    // cout << *p1 << endl; // p1 = 88
    // cout << *p2 << endl; // p2 = 53

    // delete p1;
    // delete p2;

    // int *p;
    // p = new int[5];
    // int a;

    // for (int i = 0; i < 5; i++)
    // {

    //     cin >> a;
    //     p[i] = a;
    // }

    // display(p);


}