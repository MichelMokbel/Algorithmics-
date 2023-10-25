#include <iostream>

using namespace std;

template <class T>
class X
{
private:
    T *ptr;
    int size;
    int NbrElement;

public:
    X(int s)
    {
        ptr = new T[s];
        size = s;
        NbrElement = 0;
    }

    ~X()
    {
        delete[] ptr;
    }

    void insertElement(T a)
    {
        if ((this->NbrElement) + 1 > this->size)
        {
            cout << "Element can't be inserted" << endl;
        }
        else
        {
            ptr[NbrElement] = a;
            NbrElement++;
        }
    }

    int binarySearch(int *tab, int start, int end, int key)
    {
        if (start < end)
        {
            return -1;
        }
        int mid = (start + end) / 2;
        if (tab[mid] == key)
            return mid;
        else if (tab[mid < key])
        {
            return binarySearch(tab, start, mid - 1, key);
        }
        else
        {
            return binarySearch(tab, mid + 1, end, key);
        }
    }

    void display()
    {
        for (int i = 0; i < 5; i++)
        {
            cout << "Element " << i << ":" << ptr[i] << endl;
        }
    }

    bool exists(T a)
    {
        for (int i = 0; i < NbrElement; i++)
        {
            if (ptr[i] == a)
            {
                return true;
            }
        }
        return false;
    }

    void deleteElements(T a)
    {
        for (int i = 0; i < NbrElement; i++)
        {
            if (ptr[i] == a)
            {
                for (int j = i; i < NbrElement; i++)
                {
                    ptr[j] = ptr[j + 1];
                }
                NbrElement--;
            }
        }
    }
};

int main()
{
    X<int> a(5);
    a.insertElement(1);
    a.insertElement(2);
    a.insertElement(17);
    a.insertElement(15);
    a.insertElement(19);

    a.display();

    // a.insertElement(10);

    // a.deleteElements(19);

    // a.display();

    // a.insertElement(10);

    // a.display();
}