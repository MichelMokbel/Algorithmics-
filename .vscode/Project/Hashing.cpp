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
        // Variables used for indexing and the loop
        int i = 0;
        int l = 0;

        // Check if linear probing is selected
        if (m == "linear")
        {
            int hash = (x % size); // Calculate initial hash index using modulo operation

            // If the calculated position is empty (-1), insert the element
            if (arr[hash] == -1)
            {
                arr[hash] = x;
            }
            else
            {
                // If initial position is not empty, find the next available slot
                for (i = 0; i <= size - 1; i++)
                {
                    l = (hash + i) % size; // Calculate next position
                    if (arr[l] == -1)
                    {
                        arr[l] = x; // Insert element in the next available slot
                        break; // Break the loop after inserting
                    }
                }
            }
            return;
        }
        // Check if quadratic probing is selected
        else if (m == "quadratic")
        {
            int hash = (x % size); // Calculate initial hash index

            // If the calculated position is empty, insert the element
            if (arr[hash] == -1)
            {
                arr[hash] = x;
            }
            else
            {
                // If initial position is not empty, use quadratic probing for collision resolution
                for (i = 0; i <= size - 1; i++)
                {
                    l = (hash + (i * i)) % size; // Calculate next position using quadratic formula
                    if (arr[l] == -1)
                    {
                        arr[l] = x;
                        break;
                    }
                }
            }
            return;
        }
        // Check if double hashing is selected
        else if (m == "double")
        {
            // Find the nearest prime number less than the size for the second hash function
            int q = nearestPrime(size);
            int hash1 = (x % size);  // First hash function
            int hash2 = q - (x % q); // Second hash function

            // Combine the two hash functions for the initial index
            int hash = (hash1 + (i * hash2)) % size;

            // Insert the element if the position is empty
            if (arr[hash] == -1)
            {
                arr[hash] = x;
            }
            else
            {
                // Use double hashing for collision resolution
                for (i = 0; i <= size - 1; i++)
                {
                    l = (hash1 + (i * hash2)) % size; // Calculate next position using double hashing
                    if (arr[l] == -1)
                    {
                        arr[l] = x;
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

        // Check from 2 to n for any divisors
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                return false; // If n is divisible by i, then n is not a prime number
            }
        }
        return true; // If no divisors are found, n is a prime number
    }

    /**
     * Finds the nearest prime number less than the given number.
     *
     * @param n The number to find the nearest prime for.
     * @return The nearest prime number less than the given number, or -1 if no prime is found.
     */
    int nearestPrime(int n)
    {
        n--; // Start from the number just less than n
        while (n > 1)
        {
            if (isPrime(n))
                return n; // Return the first prime number found less than n
            n--;          // Decrement n and check the next lower number
        }
        return -1; // Return -1 if no prime number is found (should not happen for n > 2)
    }

    /**
     * Displays the elements of the array.
     * Prints the index and value of each element in the array.
     * If an element is empty, it is displayed as "Empty".
     */
    void displayElts()
    {
        cout << endl
             << "Index:  ";
        // Loop to display indices
        for (int i = 0; i < size; i++)
        {
            cout << i << "\t"; // Display each index followed by a tab
        }

        cout << endl
             << "Value:  ";
        // Loop to display values
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == -1)
                cout << "-\t"; // Display a dash for empty slots
            else
                cout << arr[i] << "\t"; // Display the value in the slot
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
        int index = a % this->size; // Calculate the initial index using modulo operation
        int i = 0;                  // Counter for probing

        // Loop until an empty slot is found or the entire table is probed
        while (arr[index] != -1 && i < size)
        {
            if (arr[index] == a)
            {
                cout << "Element " << a << " found at index " << index << "." << endl;
                return index; // Element found, return its index
            }

            // Probing methods
            if (method == "linear")
            {
                cout << "Used Linear Probing" << endl;
                index = (index + 1) % size; // Linear probing: move to the next index
            }
            else if (method == "quadratic")
            {
                cout << "Used Quadratic Probing" << endl;
                i++;
                index = (index + i * i) % size; // Quadratic probing: move to i^2 index
            }
            else if (method == "double")
            {
                cout << "Used Double Hashing" << endl;
                int q = nearestPrime(size); // Find nearest prime for double hashing
                i++;
                int hash1 = (a % size);
                int hash2 = q - (a % q);
                index = (hash1 + (i * hash2)) % size; // Double hashing: combine two hashes
            }

            i++; // Increment counter

            // If the entire table has been probed
            if (i >= size)
            {
                cout << "Element " << a << " not found." << endl;
                return -1; // Element not found
            }
        }

        cout << "Element " << a << " not found." << endl;
        return -1; // Element not found after probing
    }

    /**
     * @brief Deletes an element from the hash table.
     *
     * @param a The element to be deleted.
     */
    void deleteElmts(int a)
    {
        int index = a % this->size; // Calculate the initial index using modulo operation
        int i = 0;                  // Counter for probing

        // Loop until an empty slot is found or the entire table is probed
        while (arr[index] != -1 && i < size)
        {
            if (arr[index] == a)
            {
                arr[index] = -1; // Element found, mark it as deleted
                return;
            }

            // Probing methods
            if (method == "linear")
            {
                cout << "Used Linear Probing" << endl;
                index = (index + 1) % size; // Linear probing: move to the next index
            }
            else if (method == "quadratic")
            {
                cout << "Used Quadratic Probing" << endl;
                i++;
                index = (index + i * i) % size; // Quadratic probing: move to i^2 index
            }
            else if (method == "double")
            {
                cout << "Used Double Hashing" << endl;
                int q = nearestPrime(size); // Find nearest prime for double hashing
                i++;
                int hash1 = (a % size);
                int hash2 = q - (a % q);
                index = (hash1 + (i * hash2)) % size; // Double hashing: combine two hashes
            }

            i++; // Increment counter

            // If the entire table has been probed
            if (i >= size)
            {
                cout << "Element " << a << " not found." << endl;
                return; // Element not found
            }
        }

        cout << "Element " << a << " not found." << endl;
        return; // Element not found after probing
    }
};

int main()
{
    int tableSize, probeType, value, num, action, nbr = 0;
    // Prompt user for size of the hash table
    cout << "Choose the Size of The Hash Table: ";
    cin >> tableSize;
    while (tableSize <= 0)
    {
        // Validate the input size
        cout << "Enter a valid size: ";
        cin >> tableSize;
    }

    // Prompt user for the probing method
    cout << "Choose the type of Probing you want to use: " << endl;
    cout << "(1) for Linear Probing. \n(2) for Quadratic Probing. \n(3) for Double Hashing." << endl;
    cin >> probeType;
    while (probeType < 1 || probeType > 3)
    {
        // Validate the input for probing method
        cout << "Enter a valid option: ";
        cin >> probeType;
    }

    // Assign the selected probing method
    string method = (probeType == 1) ? "linear" : (probeType == 2) ? "quadratic"
                                                                   : "double";
    // Create a hash table object with the selected size and method
    Hash a(tableSize, method);

    // Variable to control the main loop
    bool continueProgram = true;
    while (continueProgram)
    {
        // Display options for the user
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
                // Insert the value into the hash table
                a.insertNumber(value, method);
                nbr++; // Increment number of elements inserted
            }
            break;
        case 2: // Delete
            cout << "Enter value to delete: ";
            cin >> num;
            // Delete the specified element
            a.deleteElmts(num);
            break;
        case 3: // Search
            cout << "Enter value to search: ";
            cin >> num;
            // Search for the specified element
            cout << a.search(num) << endl;
            break;
        case 4: // Display Hash Table
            // Display the contents of the hash table
            a.displayElts();
            break;
        case 5: // Exit
            // Exit the program
            continueProgram = false;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    }

    // Message indicating the program is ending
    cout << "Exiting program." << endl;
    return 0;
}
