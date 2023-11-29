#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Hash
{
private:
    int size;
    int *arr;
    int nbr;
    string method;

public:
    Hash(int s, string M) : size(s), method(M), nbr(0)
    {
        arr = new int[s];
        for(int i = 0; i < size; ++i)
            arr[i] = INT_MIN; // Initialize all elements to indicate empty slots
    }

    Hash() : size(0), arr(nullptr), nbr(0), method("") {}

    ~Hash()
    {
        delete[] arr;
    }

    void insertNumber(int x)
    {
        if (nbr >= size)
        {
            cout << "The table is full" << endl;
            return;
        }
        int index = x % size;
        if (method == "linear")
        {
            while (arr[index] != INT_MIN)
                index = (index + 1) % size;
        }
        else if (method == "quadratic")
        {
            int i = 0;
            while (arr[index] != INT_MIN)
            {
                i++;
                index = (x % size + i * i) % size;
            }
        }
        arr[index] = x;
        nbr++;
    }

    void displayElts()
    {
        for (int i = 0; i < size; i++)
        {
            if(arr[i] == INT_MIN)
                cout << i << " " << "Empty" << endl;
            else
                cout << i << " " << arr[i] << endl;
        }
    }

    void deleteElt(int a)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == a)
            {
                arr[i] = INT_MIN; // Mark as deleted/empty
                nbr--;
                return;
            }
        }
        cout << "Element not found." << endl;
    }

    bool exists(int a)
    {
        for (int i = 0; i < size; i++)
            if (arr[i] == a)
                return true;
        return false;
    }
};

int main()
{
    int i, p, x;
    cout << "Choose the Size of The Hash Table: " << endl;
    cin >> i;
    while(i <= 0){
        cout << "Enter a valid size: " << endl;
        cin >> i;
    }

    cout << "Choose the type of Probing you want to use: " << endl;
    cout << "(1) for Linear Probing. \n(2) for Quadratic Probing." << endl;
    cin >> p;
    while(p != 1 && p != 2){
        cout << "Enter a valid option: " << endl;
        cin >> p;
    }

    string method = (p == 1) ? "linear" : "quadratic";
    Hash a(i, method);
    
    cout << "Insert numbers into the hash table (Enter -1 to stop): " << endl;
    while(true){
        cin >> x;
        if(x == -1){
            break;
        }
        a.insertNumber(x);
    }
    a.displayElts();
    
    return 0;
}