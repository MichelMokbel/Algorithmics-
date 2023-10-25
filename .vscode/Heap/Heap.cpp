#include <cstddef>
#include <iostream>

using namespace std;

template <class Elem>
class Heap
{
private:
    Elem *tab;             // Pointer to the array - Heap
    int max;               // Maximum length of the Heap (array)
    int n;                 // Number of elements in the Heap
    void putHeap(int pos); // Put an element in its right position
public:
    Heap(Elem *j, int num, int max); // Constructor
    Heap(int max);                   // Constructor
    ~Heap();                         // Destrutor
    int heapSize() const;
    bool isLeaf(int) const;
    /* Return consequently the position of the left child, right child and father of an element
    giving its position*/
    int leftChild(int) const;
    int rightChild(int) const;
    int Parent(int) const;          // Insert an element in the Heap
    Elem deleteMin();               // Delete the smallest element from the Heap
    Elem remove(int pos);           // Delete the element at position n
    void buildHeap();               // Build a heap from an unordered array
    void insertMin(const Elem val); // Insert in a Min-Heap
    void swap(int i, int j);        // Swap the elements inside the array
    bool isMinHeap() const;

    void display()
    {

        for (int i = 1; i <= n; i++)
        {
            cout << "Element " << i << ":" << tab[i] << endl;
        }
    }
};

template <class Elem>
int Heap<Elem>::Parent(int pos) const
{
    if (pos > 1 && pos <= n)
    {
        return pos / 2;
    }
    return -1; // Error
}

template <class Elem>
int Heap<Elem>::leftChild(int pos) const
{
    return (2 * pos);
}

template <class Elem>
int Heap<Elem>::rightChild(int pos) const
{
    return (2 * pos) + 1;
}

template <class Elem>
bool Heap<Elem>::isLeaf(int pos) const
{
    return (pos > n / 2) && (pos <= n);
}

// Return the current heap size
template <class Elem>
int Heap<Elem>::heapSize() const
{
    return this->n;
}

// Heap Constructor
template <class Elem>
Heap<Elem>::Heap(Elem *h, int num, int max)
{
    tab = h;
    this->n = num;
    this->max = max;

    buildHeap();
}

template <class Elem>
Heap<Elem>::Heap(int maxVal)
{
    this->n = 0;
    this->max = maxVal;
    this->tab = new Elem[maxVal + 1];
}

template <class Elem>
Heap<Elem>::~Heap()
{
    delete[] tab;
}

template <class Elem>
void Heap<Elem>::buildHeap()
{
    for (int i = n / 2; i > 0; i--)
    {
        putHeap(i);
    }
}

template <class Elem>
void Heap<Elem>::swap(int i, int j)
{
    Elem temp = tab[i];
    tab[i] = tab[j];
    tab[j] = temp;
}

template <class Elem>
void Heap<Elem>::insertMin(const Elem val)
{
    if (n < max)
    {                       // Number of element is less than the size.
        int current = ++n;  // Plus one element
        tab[current] = val; // Insert at the end of the heap.
        while (current > 1 && tab[current] < tab[Parent(current)])
        {
            // If it's smaller then swap with parent
            swap(current, Parent(current));
            current = Parent(current);
        }
    }
}

template <class Elem>
Elem Heap<Elem>::deleteMin()
{
    if (n == 0)
    {
        return -1; // Heap is empty
    }
    Elem temp = tab[1];
    tab[1] = tab[n--];
    // Exchange the first element with the last
    if (n > 1)
        putHeap(1); // More than one element
    // Put the new root of the heap at the right position.
    return temp;
}

template <class Elem>
void Heap<Elem>::putHeap(int pos)
{
    // int pos = 1; // Start from the root
    while (!isLeaf(pos))
    {
        int l = leftChild(pos);
        int r = rightChild(pos);
        int smallest = l;
        if (r <= n && tab[r] < tab[l])
        {
            smallest = r; // l will be the smallest index among the 2 children
        }
        if (tab[pos] <= tab[smallest])
            return;
        swap(pos, smallest);
        pos = smallest; // Go down one level
    }
}

template <class Elem>
Elem Heap<Elem>::remove(int pos)
{
    if ((pos < 0) || (pos >= n))
    {
        return nullptr;
    }
    Elem removedElem = tab[pos];
    swap(pos, n - 1); // Swap with the last element
    n--;              // Decrease the size of the heap

    while ((pos != 0) && tab[pos] < tab[Parent(pos)])
    {
        swap(pos, Parent(pos));
        pos = Parent(pos);
    }

    if (pos == 0 || tab[pos] != removedElem)
    {
        putHeap(pos);
    }
    return removedElem;
}

template <class Elem>
bool Heap<Elem>::isMinHeap() const
{
    if (n == 0)
        return true;

    for (int i = 1; i <= n; i++)
    {
        int l = 2 * i;
        int r = (2 * i) + 1;

        if (l <= n && tab[i] > tab[l])
            return false;
        if (r <= n && tab[i] > tab[r])
            return false;

        if (i < n){
            if(l > n && r < n){
                // Left child is missing, but the right child exists
                return false;
            }
            if(r > n && (2 * (i + 1)) <= n){
                // Right child is missing, but there exists a next left child
                return false;
            }
        }
    }
    return true;
}

int main()
{
    Heap<int> h1(10);
    h1.insertMin(5);
    h1.insertMin(3);
    h1.insertMin(8);
    h1.insertMin(1);
    h1.insertMin(18);
    h1.insertMin(0);

    h1.display();
    cout << "Min after inserts: " << h1.deleteMin() << endl;
    h1.display();

    cout << "<------------------------------------------------------------------------------------->" << endl;

    int arr[] = {0, 10, 20, 15, 30, 1};
    Heap<int> h2(arr, 5, 10);

    h2.display();
    cout << "Min after inserts: " << h2.deleteMin() << endl;
    h2.display();

    return 0;
}