#include <iostream>
#include <vector>
#include <cmath>

struct Node
{
    int key;
    int degree;
    Node *parent;
    Node *child;
    Node *left;
    Node *right;
    bool mark;

    Node(int value) : key(value), degree(0), parent(nullptr), child(nullptr), left(this), right(this), mark(false) {}
};

class FibonacciHeap
{
public:
    FibonacciHeap() : minNode(nullptr), totalNodes(0) {}

    Node *insert(int key)
    {
        Node *newNode = new Node(key);

        if (!minNode)
        {
            minNode = newNode;
        }
        else
        {
            addNode(newNode, minNode);
            
            if (key < minNode->key)
            {
                minNode = newNode;
            }
        }

        totalNodes++;

        return newNode;
    }

    void decreaseKey(Node *node, int newKey)
    {
        if (newKey > node->key)
        {
            std::cerr << "New key is greater than current key." << std::endl;
            return;
        }

        node->key = newKey;

        Node *parent = node->parent;

        if (parent && node->key < parent->key)
        {
            cut(node, parent);
            cascadingCut(parent);
        }

        if (node->key < minNode->key)
        {
            minNode = node;
        }
    }

private:
    Node *minNode;
    int totalNodes;

    void addNode(Node *node, Node *root)
    {
        node->left = root;
        node->right = root->right;
        root->right->left = node;
        root->right = node;
    }

    void cut(Node *node, Node *parent)
    {
        removeNode(node);

        parent->degree--;

        addNode(node, minNode);

        node->parent = nullptr;
        node->mark = false;
    }

    void cascadingCut(Node *node)
    {
        Node *parent = node->parent;

        if (parent)
        {
            if (!node->mark)
            {
                node->mark = true;
            }
            else
            {
                cut(node, parent);
                cascadingCut(parent);
            }
        }
    }

    void removeNode(Node *node)
    {
        node->left->right = node->right;
        node->right->left = node->left;
    }
};

int main()
{
    FibonacciHeap heap;

    Node *node1 = heap.insert(10);
    Node *node2 = heap.insert(20);
    Node *node3 = heap.insert(30);

    heap.decreaseKey(node3, 5);

    std::cout << "Decrease key operation completed." << std::endl;

    return 0;
}