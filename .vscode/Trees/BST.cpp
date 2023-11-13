#include <iostream>

using namespace std;

template <class Element>
class BST
{
private:
    // Definition of class BNode
    class Bnode
    {
    public:
        Bnode *left; // Pointer to the left subtree
        Element data;
        Bnode *right; // Pointer to the right subtree

        /*Input param is the memory address of d*/
        Bnode(const Element &d)
        {
            left = 0;
            data = d;
            right = 0;
        }

        bool isLeaf()
        {
            return (left == NULL) && (right == NULL);
        }
    };

    Bnode *root; // Root of the tree
public:
    BST()
    {
        root = NULL;
    }

    void insert(const Element &d);
    void insertNodeHelper(Bnode *&ptr, const Element &value);
    bool search(const Element &value);
    bool searchNodeHelper(Bnode *&ptr, const Element &value);
    void remove(const Element &d);
    void removeNodeHelper(Bnode *&ptr, const Element &value);
    Element removeMin(Bnode *&ptr);
    void deleteMax() const;
    void deleteMax(Bnode *&ptr) const;
    bool isBST();
    bool isBSTHelper(Bnode *&ptr, Element min, Element max);
    Element sortedArrayToBST(int *tab, int start, int end);
    void print() const;
};

template <class Element>
void BST<Element>::insert(const Element &value)
{
    insertNodeHelper(root, value);
}

template <class Element>
void BST<Element>::insertNodeHelper(Bnode *&ptr, const Element &value)
{
    if (ptr == NULL)
    {
        ptr = new Bnode(value);
    }
    else if (value < ptr->data)
    {
        insertNodeHelper(ptr->left, value);
    }
    else
    {
        insertNodeHelper(ptr->right, value);
    }
}

template <class Element>
bool BST<Element>::search(const Element &value)
{
    return searchNodeHelper(root, value);
}

template <class Element>
bool BST<Element>::searchNodeHelper(Bnode *&ptr, const Element &value)
{
    if (ptr == NULL)
    {
        return false;
    }
    else if (value < ptr->data)
    {
        searchNodeHelper(ptr->left, value);
    }
    else if (value > ptr->data)
    {
        searchNodeHelper(ptr->right, value);
    }
    else
    {
        return true;
    }
}

template <class Element>
// bool BST<Element>::searchNodeHelper(Bnode *&ptr, const Element &value)
// {
//     while (ptr != NULL)
//     {
//         if (ptr->data == value)
//             return true;
//         else if (ptr->data < val)
//             ptr = ptr->right;
//         else
//             ptr = ptr->left;
//     }
//     return false;
// }

template <class Element>
void BST<Element>::remove(const Element &d)
{
    removeNodeHelper(root, d);
}

template <class Element>
void BST<Element>::removeNodeHelper(Bnode *&ptr, const Element &value)
{
    if (ptr == NULL)
        return;
    if (value < ptr->data)
    {
        removeNodeHelper(ptr->left, value);
    }
    else if (value > ptr->data)
    {
        removeNodeHelper(ptr->right, value);
    }
    else
    {
        if (ptr->left != NULL && ptr->right != NULL)
        {
            ptr->data = removeMin(ptr->right);
        }
        else
        {
            Bnode *oldNode = ptr;
            ptr = (ptr->left != NULL) ? ptr->left : ptr->right;
            delete oldNode;
        }
    }
}

template <class Element>
Element BST<Element>::removeMin(Bnode *&ptr)
{
    if (ptr == NULL)
        return NULL;
    else if (ptr->left != NULL)
    {
        removeMin(ptr->left);
    }
    else
    {
        Element replaceValue = ptr->data;
        Bnode *tmp = ptr;
        ptr = ptr->right;
        delete tmp;
        return replaceValue;
    }
}

template <class Element>
void BST<Element>::deleteMax() const
{
    deleteMax(root);
}

template <class Element>
void BST<Element>::deleteMax(Bnode *&ptr) const
{
    if (ptr == NULL)
        return;
    else if (ptr->right != NULL)
        deleteMax(ptr->right);
    else
        Bnode *tmp = ptr;
        ptr = ptr->left;
        delete ptr;
}

template <class Element>
bool BST<Element>::isBST()
{
    return isBSTHelper(root, INT_MIN, INT_MAX);
}

// template <class Element>
// bool BST<Element>::isBSTHelper(Bnode *&ptr)
// {
//     Bnode *right = ptr->right;
//     Bnode *left = ptr->left;
//     if (ptr == NULL)
//         return true;
//     if (right->data < ptr->data)
//         return false;
//     else if (left->data > ptr->data)
//         return false;
//     else
//         return isBSTHelper(ptr->right) &&
//                isBSTHelper(ptr->left);
//     return true;
// }

template <class Element>
bool BST<Element>::isBSTHelper(Bnode *&ptr, Element min, Element max)
{
    // An empty tree is a BST
    if (ptr == NULL)
        return true;

    // Check if current node's value is within the allowed range
    if (ptr->data <= min || ptr->data >= max)
        return false;

    // Recursively check the left and right subtree with updated ranges
    return isBSTHelper(ptr->left, min, ptr->data) && isBSTHelper(ptr->right, ptr->data, max);
}

template <class Element>
Element BST<Element>::sortedArrayToBST(int *tab, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    Bnode *root = new Bnode(tab[mid]);
    root->left = sortedArrayToBST(tab, start, mid - 1);
    root->right = sortedArrayToBST(tab, mid + 1, end);

    return root;
}




int main()
{
    return 0;
}