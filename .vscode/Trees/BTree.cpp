#include <iostream>

using namespace std;

template <class Element>
class BTree
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
    BTree()
    {
        root = NULL;
    }

    void emptyTree();
    bool isEmpty() const;
    void insert(const Element &d);
    void remove(const Element &d);
    void print() const;
};

template <class Element>
void BTree<Element>::insert(const Element &d)
{
    // Private helper function to assist with recursive insertion.
    Bnode *insertRecursively(Bnode * current, const Element &d)
    {
        // If the current node is NULL, it means we've found the place to insert our new node.
        if (current == NULL)
        {
            return new Bnode(d);
        }

        // If the data to insert is less than the current node's data, go to the left subtree.
        if (d < current->data)
        {
            current->left = insertRecursively(current->left, d);
        }
        // If the data to insert is greater than the current node's data, go to the right subtree.
        else if (d > current->data)
        {
            current->right = insertRecursively(current->right, d);
        }
        // If the data is the same as current's data, we don't insert it (no duplicates allowed in this implementation).
        else
        {
            // Do nothing, or you can throw an exception or handle duplicates as you wish.
        }

        return current;
    };

    root = insertRecursively(root, d);
}

template <class Element>
bool BTree<Element>::isEmpty() const
{
    return (root == NULL);
}


