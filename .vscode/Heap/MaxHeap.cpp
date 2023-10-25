#include <iostream>
#include <cstddef>

using namespace std;

template <class Elem>
class MaxHeap
{
private:
    Elem *tab;         // Pointer to the array
    int max;           // Max size of the array
    int n;             // Number of elements in the array
    void putHeap(int); // Rearrange the nodes in the heap
public:
    MaxHeap(Elem *h, int max, int n);
    MaxHeap(int max);
    ~MaxHeap();
    int HeapSize() const;
    bool isLeaf(int) const;
    int leftChild(int) const;
    int rightChild(int) const;
    int Parent(int) const;
    void insertMax(const Elem val);
    Elem deleteMax();
    void swap(int i, int j);
    void buildHeap();
    bool isEmpty() const;
    void display()
    {
        for (int i = 1; i <= n; i++)
        {
            cout << "Element " << i << ":" << tab[i] << endl;
        }
    }
};

template <class Elem>
int MaxHeap<Elem>::Parent(int pos) const
{
    if (pos > 1 && pos <= n)
        return pos / 2;
    return -1;
}

template <class Elem>
int MaxHeap<Elem>::leftChild(int pos) const
{
    return 2 * pos;
}

template <class Elem>
int MaxHeap<Elem>::rightChild(int pos) const
{
    return (2 * pos) + 1;
}

template <class Elem>
bool MaxHeap<Elem>::isLeaf(int pos) const
{
    return (pos > n / 2) && (pos <= n);
}

template <class Elem>
int MaxHeap<Elem>::HeapSize() const
{
    return this->n;
}

template <class Elem>
void MaxHeap<Elem>::swap(int i, int j)
{
    Elem temp = tab[j];
    tab[j] = tab[i];
    tab[i] = temp;
}

template <class Elem>
MaxHeap<Elem>::MaxHeap(Elem *h, int max, int n)
{
    tab = h;
    this->max = max;
    this->n = n;

    buildHeap();
}

template <class Elem>
MaxHeap<Elem>::MaxHeap(int max)
{
    this->max = max;
    this->n = 0;
    this->tab = new Elem[max + 1]; // +1 because of the index starting at one.
}

template <class Elem>
MaxHeap<Elem>::~MaxHeap()
{
    delete[] tab;
}

template <class Elem>
void MaxHeap<Elem>::buildHeap()
{
    for (int i = n / 2; i > 0; i--)
    {
        putHeap(i);
    }
}

template <class Elem>
void MaxHeap<Elem>::putHeap(int i)
{
    while (!isLeaf(i))
    {
        int l = leftChild(i);
        int r = rightChild(i);
        int greatest = l;
        if (r <= n && tab[r] > tab[l])
        {
            greatest = r;
        }
        if (tab[i] >= tab[greatest])
            return;

        swap(i, greatest);
        i = greatest;
    }
}
template <class Elem>
void MaxHeap<Elem>::insertMax(const Elem val)
{
    if (n < max)
    {
        int current = ++n;
        tab[current] = val;
        while (current > 1 && tab[current] > tab[Parent(current)])
        {
            swap(current, Parent(current));
            current = Parent(current);
        }
    }
}

template <class Elem>
Elem MaxHeap<Elem>::deleteMax()
{
    if (n == 0)
    {
        return -1;
    }
    Elem temp = tab[1];
    tab[1] = tab[n--];

    if (n > 1)
        putHeap(1);

    return temp;
}

template <class Elem>
bool Heap<Elem>::isMaxHeap() const
{
    if (n == 0)
        return true;

    for (int i = 1; i <= n; i++)
    {
        int l = 2 * i;
        int r = (2 * i) + 1;

        if (l <= n && tab[i] < tab[l])
            return false;
        if (r <= n && tab[i] < tab[r])
            return false;

        if (l > n && r < n)
        {
            // Left child is missing, but the right child exists
            return false;
        }
        if (r > n && (2 * (i + 1)) <= n)
        {
            // Right child is missing, but there exists a next left child
            return false;
        }
    }
    return true;
}

int main()
{
    MaxHeap<int> h1(10);
    h1.insertMax(5);
    h1.insertMax(7);
    h1.insertMax(52);
    h1.insertMax(25);
    h1.insertMax(8);
    h1.insertMax(15);

    h1.display();
    //     cout << "Min after inserts: " << h1.deleteMin() << endl;
    //     h1.display();
}