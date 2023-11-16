#include <iostream>
#include <string>
using namespace std;

class Hash
{
private:
    int size;
    int *arr;
    int nbr;

public:
    Hash(int s, string M)
    {
        arr = new int[s];
        size = s;
        nbr = 0;

    }

    Hash(){
        arr = new int[0];
        size = 0;
        nbr = 0;

    }

    ~Hash()
    {
        delete[] arr;
    }

    void insertNumber(int x)
    {
        // if (nbr + 1 > size)
        //     cout << "the table is full" << endl;
        // else
        // {
            if (method == "linear")
            {
                int i = 0;
                int l = 0;
                int hash = (x % size);
                if (arr[hash] == '\0')
                {
                    arr[hash] = x;
                    nbr++;
                }
                else
                {
                    for (i = 0; i <= size - 1; i++)
                    {
                        l = (hash + i) % size;
                        if (arr[l] == '\0')
                        {
                            arr[l] = x;
                            nbr++;
                            break;
                        }
                    }
                }
                return;
            }
            else if (method == "quadratic")
            {
                int i = 0;
                int l = 0;
                int hash = (x % size);
                if (arr[hash] == '\0')
                {
                    arr[hash] = x;
                    nbr++;
                }
                else
                {
                    for (i = 0; i <= size - 1; i++)
                    {
                        l = (hash + (i * i)) % size;
                        if (arr[l] == '\0')
                        {
                            arr[l] = x;
                            nbr++;
                            break;
                        }
                    }
                }
                return;
            }
        // }
    }

    int insertString(const string &key)
    {
        int value = 0;
        for (int i = key.size() - 1; i >= 0; --i)
        {
            value = 33 * value + key[i];
        }
        return value % size;
    }

    void displayElts()
    {
        for (int i = 0; i < size; i++)
            cout << i << " " << arr[i] << endl;
    }

    void deleteElt(int a)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == a)
            {
                for (int j = i; j < size; j++)
                    arr[j] = arr[j + 1];
            }
        }
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
    int nbr = 0;
    cout<< "Choose the Size of The Hash Table: " << endl;
    cin >> i;
    if(i <= 0){
        cout << "Enter a valid size: " << endl;
        cin >> i;
    }
    // Hash a(i , "");
    cout<< "Choose the type of Probing you want to use: "<< endl;
    cout<< "(1) for Linear Probing. \n(2) for Quadratic Probing." << endl;
    cin >> p;
    Hash a(i , "");
    if(p != 1 && p != 2){
        cout << "Enter a valid option: " << endl;
        cin >> p;
    }else if (p == 1){
        Hash a(i , "linear");
        while(x != -1){
            cout << "Choose the value to insert: " << endl;
            cout << "Choose '-1' to stop inserting: " << endl;
            cin >> x;
            if(x != -1){
                 a.insertNumber(x);
                 nbr++;
                 if(nbr >= i){
                    break;
                 }
            }
        }
        a.displayElts();
    }
    else if(p == 2){
        Hash a(i , "quadratic");
        while(x != -1){
            cout << "Choose the value to insert: " << endl;
            cout << "Choose '-1' to stop inserting: " << endl;
            cin >> x;
            if(x != -1){
                a.insertNumber(x);
                nbr++;
                if(nbr >= i){
                    break;
                }
            } 
        }
        a.displayElts();
    }
    
    
    return 0;
}
