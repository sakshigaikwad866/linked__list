#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

void display(Node *root, int parent, int depth)
{
    if (root == NULL)
        return;

    int degree = 0;

    if (root->left != NULL)
        degree++;

    if (root->right != NULL)
        degree++;

    cout << "\nNode: " << root->data;

    if (parent == -1)
        cout << "\nParent: None";
    else
        cout << "\nParent: " << parent;

    cout << "\nChildren: ";

    if (degree == 0)
        cout << "None";
    else
    {
        if (root->left != NULL)
            cout << root->left->data << " ";

        if (root->right != NULL)
            cout << root->right->data;
    }

    cout << "\nDegree: " << degree;
    cout << "\nDepth: " << depth;

    if (degree == 0)
        cout << "\nType: Leaf Node";
    else if (parent == -1)
        cout << "\nType: Root Node";
    else
        cout << "\nType: Internal Node";

    cout << endl;

    display(root->left, root->data, depth + 1);
    display(root->right, root->data, depth + 1);
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left),
                   height(root->right));
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Root Node: " << root->data << endl;

    cout << "\nTree Node Details:\n";
    display(root, -1, 0);

    cout << "\nHeight of Tree: "
         << height(root) << " levels" << endl;

    return 0;
}

