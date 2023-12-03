#include <iostream>
#include <string>
using namespace std;

class Hash
{
private:
    int size;
    int *arr;
    int nbr;
    string method;

public:
    Hash(int s, string M)
    {
        arr = new int[s];
        size = s;
        nbr = 0;
        method = M;
        for (int i = 0; i < size; i++)
        {
            this->arr[i] = -1;
        }
    }

    Hash()
    {
        arr = new int[0];
        size = 0;
        nbr = 0;
        method = "";
    }

    ~Hash()
    {
        delete[] arr;
    }

    void insertNumber(int x, string m)
    {
        // if (nbr + 1 > size)
        //     cout << "the table is full" << endl;
        // else
        // {
        if (m == "linear")
        {
            int i = 0;
            int l = 0;
            int hash = (x % size);
            if (arr[hash] == -1)
            {
                arr[hash] = x;
                nbr++;
            }
            else
            {
                for (i = 0; i <= size - 1; i++)
                {
                    l = (hash + i) % size;
                    if (arr[l] == -1)
                    {
                        arr[l] = x;
                        nbr++;
                        break;
                    }
                }
            }
            return;
        }
        else if (m == "quadratic")
        {
            int i = 0;
            int l = 0;
            int hash = (x % size);
            if (arr[hash] == -1)
            {
                arr[hash] = x;
                nbr++;
            }
            else
            {
                for (i = 0; i <= size - 1; i++)
                {
                    l = (hash + (i * i)) % size;
                    if (arr[l] == -1)
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
    // void displayElts()
    // {
    //     cout << endl;
    //     for (int i = 0; i < size; i++)
    //         cout << "|" << i << "|" <<arr[i] << endl;
    // }
    void displayElts()
    {
        cout << endl;
        cout << endl;
        cout << "Index:  ";
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t";
        }
        cout << endl
             << "Value:  ";
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == INT_MIN)
                cout << "Empty\t";
            else
                cout << arr[i] << "\t";
        }
        cout << endl;
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
    }

    int search(int a)
    {
        int index = a % this->size;
        int i = 0;

        while (arr[index] != -1 && i < size)
        {
            if (arr[index] == a)
            {
                cout << "Element " << a << " found at index " << index << "." << endl;
                return index;
            }

            else if (method == "linear")
            {
                cout << "Used Linear Probing" << endl;
                index = (index + 1) % size;
            }
            else if (method == "quadratic")
            {
                cout << "Used Quadratic Probing" << endl;
                i++;
                index = (index + i * i) % size;
            }

            i++;

            if (i >= size)
            {
                cout << "Element " << a << " not found." << endl;
                return -1;
            }
        }

        cout << "Element" << a << " not found." << endl;
        return -1;
    }

    void deleteElmts(int a)
    {
        int index = a % this->size;
        int i = 0;

        while (arr[index] != -1 && i < size)
        {
            if (arr[index] == a)
            {
                arr[index] = -1;
                return;
            }

            else if (method == "linear")
            {
                cout << "Used Linear Probing" << endl;
                index = (index + 1) % size;
            }
            else if (method == "quadratic")
            {
                cout << "Used Quadratic Probing" << endl;
                i++;
                index = (index + i * i) % size;
            }

            i++;

            if (i >= size)
            {
                cout << "Element " << a << " not found." << endl;
                return;
            }
        }

        cout << "Element" << a << " not found." << endl;
        return;
    }
};

int main()
{
    int i, p, x, num;
    int nbr = 0;
    cout << "Choose the Size of The Hash Table: " << endl;
    cin >> i;
    if (i < 0)
    {
        cout << "Enter a valid size: " << endl;
        cin >> i;
    }
    // Hash a(i , "");
    cout << "Choose the type of Probing you want to use: " << endl;
    cout << "(1) for Linear Probing. \n(2) for Quadratic Probing." << endl;
    cin >> p;
    Hash a(i, "");
    if (p != 1 && p != 2)
    {
        cout << "Enter a valid option: " << endl;
        cin >> p;
    }
    else if (p == 1)
    {
        Hash a(i, "linear");
        while (x != -1)
        {
            cout << "Choose the value to insert: " << endl;
            cout << "Choose '-1' to stop inserting: " << endl;
            cin >> x;
            if (x != -1)
            {
                a.insertNumber(x, "linear");
                nbr++;
                if (nbr >= i)
                {
                    break;
                }
            }
        }
        a.displayElts();

        cout << "Choose the element to search: " << endl;
        cin >> num;
        a.deleteElmts(num);
        // cout << a.search(num) << endl;
        // a.search(num);
        a.displayElts();
    }
    else if (p == 2)
    {
        Hash a(i, "quadratic");
        while (x != -1)
        {
            cout << "Choose the value to insert: " << endl;
            cout << "Choose '-1' to stop inserting: " << endl;
            cin >> x;
            if (x != -1)
            {
                a.insertNumber(x, "quadratic");
                nbr++;
                if (nbr >= i)
                {
                    break;
                }
            }
        }
        a.displayElts();

        cout << "Choose the element to search: " << endl;
        cin >> num;
        cout << a.search(num) << endl;
        // a.search(num);
    }

    return 0;
}
