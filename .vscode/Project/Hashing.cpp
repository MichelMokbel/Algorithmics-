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

    /**
     * Inserts a number into the hash table using the specified collision resolution method.
     * 
     * @param x The number to be inserted.
     * @param m The collision resolution method to be used ("linear", "quadratic", or "double").
     */
    void insertNumber(int x, string m)
    {

        int i = 0;
        int l = 0;
        if (m == "linear")
        {

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
        else if (m == "double")
        {
            int q = nearestPrime(size);
            int hash1 = (x % size);
            int hash2 = q - (x % q);
            int hash = (hash1 + (i * hash2)) % size;
            if (arr[hash] == -1)
            {
                arr[hash] = x;
                nbr++;
            }
            else
            {
                for (i = 0; i <= size - 1; i++)
                {
                    l = (hash1 + (i * hash2)) % size;
                    if (arr[l] == -1)
                    {
                        arr[l] = x;
                        nbr++;
                        break;
                    }
                }
            }
        }
    }

    /**
     * Checks if a number is prime.
     * 
     * @param n The number to be checked.
     * @return True if the number is prime, false otherwise.
     */
    bool isPrime(int n)
    {
        if (n <= 1)
            return false; // Numbers less than or equal to 1 are not prime numbers

        // Check from 2 to the square root of n
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * Finds the nearest prime number less than the given number.
     * 
     * @param n The number to find the nearest prime for.
     * @return The nearest prime number less than the given number, or -1 if no prime is found.
     */
    int nearestPrime(int n)
    {
        n--;
        while (n > 1)
        {
            if (isPrime(n))
                return n;
            n--;
        }
        return -1;
    }


    /**
     * Displays the elements of the array.
     * Prints the index and value of each element in the array.
     * If an element is empty, it is displayed as "Empty".
     */
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
            if (arr[i] == -1)
                cout << "-\t";
            else
                cout << arr[i] << "\t";
        }
        cout << endl;
    }


    /**
     * @brief Searches for an element in the hash table.
     * 
     * @param a The element to search for.
     * @return The index of the element if found, -1 otherwise.
     */
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
            else if (method == "double")
            {
                cout << "Used Double Hashing" << endl;
                int q = nearestPrime(size);
                i++;
                int hash1 = (a % size);
                int hash2 = q - (a % q);
                index = (hash1 + (i * hash2)) % size;
            }

            i++;

            if (i >= size)
            {
                cout << "Element " << a << " not found." << endl;
                return -1;
            }
        }

        cout << "Element " << a << " not found." << endl;
        return -1;
    }

    /**
     * @brief Deletes an element from the hash table.
     * 
     * @param a The element to be deleted.
     */
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
            else if (method == "double")
            {
                cout << "Used Double Hashing" << endl;
                int q = nearestPrime(size);
                i++;
                int hash1 = (a % size);
                int hash2 = q - (a % q);
                index = (hash1 + (i * hash2)) % size;
            }

            i++;

            if (i >= size)
            {
                cout << "Element " << a << " not found." << endl;
                return;
            }
        }

        cout << "Element " << a << " not found." << endl;
        return;
    }
};

int main()
{
    int tableSize, probeType, value, num, action, nbr;
    cout << "Choose the Size of The Hash Table: ";
    cin >> tableSize;
    while (tableSize <= 0)
    {
        cout << "Enter a valid size: ";
        cin >> tableSize;
    }

    cout << "Choose the type of Probing you want to use: " << endl;
    cout << "(1) for Linear Probing. \n(2) for Quadratic Probing. \n(3) for Double Hashing." << endl;
    cin >> probeType;
    while (probeType < 1 || probeType > 3)
    {
        cout << "Enter a valid option: ";
        cin >> probeType;
    }

    string method = (probeType == 1) ? "linear" : (probeType == 2) ? "quadratic"
                                                                   : "double";
    Hash a(tableSize, method);

    bool continueProgram = true;
    while (continueProgram)
    {
        cout << "Choose the type of action you want to perform: " << endl;
        cout << "(1) Insert \n(2) Delete \n(3) Search \n(4) Display Hash Table \n(5) Exit" << endl;
        cin >> action;

        switch (action)
        {
        case 1: // Insert
            cout << "Enter value to insert (Enter -1 to stop inserting): ";
            while (true && nbr < tableSize)
            {
                cin >> value;
                if (value == -1)
                    break;
                a.insertNumber(value, method);
                nbr++;
            }
            break;
        case 2: // Delete
            cout << "Enter value to delete: ";
            cin >> num;
            a.deleteElmts(num);
            break;
        case 3: // Search
            cout << "Enter value to search: ";
            cin >> num;
            cout << a.search(num) << endl;
            break;
        case 4: // Display Hash Table
            a.displayElts();
            break;
        case 5: // Exit
            continueProgram = false;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    cout << "Exiting program." << endl;
    return 0;
}
