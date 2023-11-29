#include <iostream>
#include <string>
using namespace std;


class hashTable {
private:
    int* table;
    int size;
    int probingType; // 1 is linear 2 is quadratic
public:

    hashTable(int x, int p) { // Construtor
        size = x;
        table = new int[size];
        probingType = p;
        for (int i = 0; i < size; i++) {
            this->table[i] = -1;
        }
    }

    ~hashTable() { // Destructor
        size = 0;
        probingType = 0;
        delete[] table;
    }


    int probing(int k, int i) {  // Probing of the key / hashing
        if (probingType == 1) {
            return ((k % size) + i) % size;
        }
        else {
            return ((k % size) + i * i) % size;
        }
    }

    void insert(int k) { // insert a key
        bool full = true;
        for (int i = 0; i < size; i++) {
            if (table[i] == -1) {
                full = false;
            }
        }
        if (!full) {
            if (probingType == 1) {
                int i = 0; bool inserted = false; int pos;
                while (i < size && !inserted) {
                    pos = probing(k, i);
                    if (table[pos] == -1) {
                        inserted = true;
                    }
                    else {
                        i++;
                    }
                }
                table[pos] = k;
            }
            else {
                bool inserted = false; int pos; int i = 0;
                while (!inserted) {
                    pos = probing(k, i);
                    if (table[pos] == -1) {
                        inserted = true;
                    }
                    else {
                        i++;
                    }
                }
                table[pos] = k;
            }
        }
        else {
            cout << "Hash Table full" << endl;
        }
    }

    int search(int k) {
        int result = -1;
        int pos;
        if (probingType == 1) {
            int i = 0; bool found = false;
            while (i < size && !found) {
                pos = probing(k, i);
                if (table[pos] == k) {
                    found = true;
                    result = pos;
                }
                else {
                    i++;
                }
            }
        }
        else {
            int* reference = new int[size];
            for (int i = 0; i < size; i++) {
                reference[i] = 0;
            }
            bool found = false; int j = 0;
            while (!found && !arrayIsFull(reference)) {
                pos = probing(k, j);
                reference[pos] = 1;
                if (table[pos] == k) {
                    found = true;
                    return pos;
                }
                else {
                    j++;
                }
            }
        }
        return result;
    }

    bool arrayIsFull(int* ref) {
        bool full = true;
        for (int i = 0; i < size; i++) {
            if (ref[i] == 0) {
                full = false;
            }
        }
        return full;
    }

    void deleteKey(int k) {
        int pos = search(k);
        if (pos != -1) {
            this->table[pos] = -1;
        }
        else {
            cout << "Did not find key:" << k << endl;
        }
    }

    string print() {
        string res = "";
        for (int i = 0; i < size; i++) {
            res += to_string(table[i]) + "|";
        }
        return res;
    }

};

int main() {
    int size, type;
    cout << "Enter the size then the type (1=linear , 2=quadratic) of the hashtable ";
    cin >> size >> type;
    while (size < 1) {
        cout << "Enter the size of the table ";
        cin >> size;
    }
    while (type != 2 && type != 1) {
        cout << "Enter the the type (1=linear , 2=quadratic) of the table ";
        cin >> type;
    }
    hashTable t(size, type);

    int action;
    cout << "1:Insert | 2:Search | 3:Delete | -1:Exit";
    cin >> action;
    while (action != -1) {
        if (action == 1) {
            int i = 0;
            cout << "Enter the key to be inserted ( any negative nb to stop)";
           std:: cin >> i;
            while (i > -1) {
                t.insert(i);
                cout << t.print() << endl;
                cout << "Enter the key to be inserted ( any negative nb to stop)";
                cin >> i;
            }
        }
        else if (action == 2) {
            int i = 0;
            cout << "Enter the key to be searched ( any negative nb to stop)";
            cin >> i;
            while (i > -1) {
                cout << "The position of " << i << " is: " << t.search(i) << endl;
                cout << t.print() << endl;
                cout << "Enter the key to be searched ( any negative nb to stop)";
                cin >> i;
            }
        }
        else if (action == 3) {
            int i = 0;
            cout << "Enter the key to be deleted (any negative nb to stop)";
            cin >> i;
            while (i > -1) {
                t.deleteKey(i);
                cout << t.print() << endl;
                cout << "Enter the key to be deleted (any negative nb to stop)";
                cin >> i;
            }
        }
        cout << "1:Insert | 2:Search | 3:Delete | -1:Exit";
        cin >> action;
    }

    t.~hashTable();

    return 0;
}