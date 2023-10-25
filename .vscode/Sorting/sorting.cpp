#include <iostream>

template <class T>
class sorting
{
private:
    T *ptr;
    int size;
    int NbrElement;

public:
    sorting(int s)
    {
        ptr = new T[s];
        size = s;
        NbrElement = 0;
    }

    ~sorting()
    {
        delete[] ptr;
    }

    // Selection sort
    void selectionSort(T *tab, int n);
    void inverseSelectionSort(T *tab, int n);
    
    // Insertion sort
    void insertionSort(T *tab, int n);
    void inverseInsertionSort(T *tab, int n);

    // Bubble sort
    void bubbleSort(T *tab, int n);
    void inverseBubbleSort(T *tab, int n);

    // Shell sort
    void shellSort(T *tab, int n);
    void InsertionShell(T *tab, int n, int h);

    // Heap sort
    void heapSort(T *tab, int n) void Insert(T x);
    Elem deleteMin();

    // Merge sort
    void MergeSort(T *tab, int n);
    void MergeSort(T *Tab, T *tmpTab, int left, int right);
    void Merge(T *Tab, T *tmpTab, int left, int mid, int right);

    // Quick sort
    void QuickSort(T *tab, int inf, int sup);
    int Partition(T *tab, int inf, int sup);
    
};

// Selection sort
template <class T>
void sorting<T>::selectionSort(T *tab, int n)
{
    int i, j, min;
    T Tmp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (tab[j] < tab[min])
                min = j;
        // swap
        Tmp = tab[i];
        tab[i] = tab[min];
        tab[min] = Tmp;
    }
}

// Inverse selection sort
template <class T>
void sorting<T>::inverseSelectionSort(T *tab, int n)
{
    int i, j, max;
    T Tmp;
    for (i = 0; i < n - 1; i++)
    {
        max = i;
        for (j = i + 1; j < n; j++)
            if (tab[j] > tab[max])
                max = j;
        // swap
        Tmp = tab[i];
        tab[i] = tab[max];
        tab[max] = Tmp;
    }
}

// Insertion sort
template <class T>
void sorting<T>::insertionSort(T *tab, int n)
{
    int i, j;
    T tmp;
    for (i = 1; i < n; i++)
    {
        tmp = tab[i];
        j = i;
        // while the insertion point is not found
        while (j > 0 && tab[j - 1] > tmp)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = tmp;
    }
}

// Inverse insertion sort
template <class T>
void sorting<T>::inverseInsertionSort(T *tab, int n)
{
    int i, j;
    T tmp;
    for (i = 1; i < n; i++)
    {
        tmp = tab[i];
        j = i;
        // while the insertion point is not found
        while (j > 0 && tab[j - 1] < tmp)
        {
            tab[j] = tab[j - 1];
            j--;
        }
        tab[j] = tmp;
    }
}

// Bubble sort
template <class T>
void sorting<T>::bubbleSort(T *tab, int n)
{
    int i, j;
    T tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (tab[j] < tab[j - 1])
            {
                tmp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = tmp;
            }
        }
    }
}

// Inverse bubble sort
template <class T>
void sorting<T>::inverseBubbleSort(T *tab, int n)
{
    int i, j;
    T tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = n - 1; j > i; j--)
        {
            if (tab[j] > tab[j - 1])
            {
                tmp = tab[j];
                tab[j] = tab[j - 1];
                tab[j - 1] = tmp;
            }
        }
    }
}

// Shell sort
template <class T>
void sorting<T>::shellSort(T *tab, int n)
{
    int h = 1;

    while (h <= n)
        h = 3 * h + 1;
    while (h > 1)
    {
        h = h / 3;
        InsertionShell<T>(tab, n, h);
    }
}

template <class T>
void sorting<T>::InsertionShell(T *tab, int n, int h)
{
    int i, j;
    T tmp;
    for (i = h; i < n; i++)
    {
        tmp = tab[i];
        j = i;
        // while the insertion point is not found
        while ((j - h) >= 0 && tab[j - h] > tmp)
        {
            tab[j] = tab[j - h];
            j = j - h;
        }
        tab[j] = tmp;
    }
}

// Heap sort
template <class T>
void sorting<T>::heapSort(T *tab, int n)
{
    for (int i = 0; i < n; i++)
    {
        Insert(a[i]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        Elem v = deleteMin();
        a[i] = v;
        /*
        for a MaxHeap:
        Elem v = deleteMin();
        */
    }
}

// Merge sort
template <class T>
void sorting<T>::MergeSort(T *tab, int n)
{
    T *tmpTab = new T[n];
    MergeSort(tab, tmpTab, 0, n - 1);
}

template <class T>
void sorting<T>::MergeSort(T *Tab, T *tmpTab, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(Tab, tmpTab, left, mid);
        MergeSort(Tab, tmpTab, mid + 1, right);
        Merge(Tab, tmpTab, left, mid, right);
    }
}

template <class T>
void sorting<T>::Merge(T *Tab, T *tmpTab, int left, int mid, int right)
{
    int i, j, k, r;
    // Copy the 2 sub tables in the temporary table
    for (i = left; i <= mid; i++)
        tmpTab[i] = Tab[i];
    for (j = 1; j <= right - mid; j++)
        // Insert the elements in the reverse order
        tmpTab[right - j + 1] = Tab[j + mid];
    // Merge the 2 subarrays
    r = right;
    for (k = left; k <= r; k++)
        if (tmpTab[left] <= tmpTab[right])
            Tab[k] = tmpTab[left++];
        else
            Tab[k] = tmpTab[right--];
}

template <class T>
void sorting<T>::QuickSort(T *tab, int inf, int sup)
{
    int middle;
    if (sup > inf)
    {
        middle = Partition(tab, inf, sup);
        QuickSort(tab, inf, middle - 1);
        QuickSort(tab, middle + 1, sup);
    }
}

template <class T>
int sorting<T>::Partition(T *tab, int inf, int sup)
{
    T pivot, temp;
    int pos, i, j;
    pivot = tab[inf];
    i = inf;

    for (j = inf + 1; j <= sup; j++)
    {
        if (tab[j] <= pivot)
        {
            i++;
            temp = tab[i];
            tab[i] = tab[j];
            tab[j] = temp;
        }
    }

    temp = tab[i];
    tab[i] = tab[inf];
    tab[inf] = temp;
    return i;
}
