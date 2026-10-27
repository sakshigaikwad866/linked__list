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

void display(Node *root)
{
    if (root == NULL)
        return;

    int degree = 0;

    if (root->left != NULL)
        degree++;
    if (root->right != NULL)
        degree++;

    cout << "Node: " << root->data
         << ", Degree: " << degree;

    if (degree == 0)
        cout << ", Leaf Node";
    else if (root->data != 1)
        cout << ", Internal Node";

    cout << endl;

    display(root->left);
    display(root->right);
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

    cout << "\nTree Terminology:\n";
    display(root);

    cout << "\nHeight of Tree: "
         << height(root) << endl;

    return 0;
}

