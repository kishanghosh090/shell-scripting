#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Returns height if balanced, otherwise -1
int checkBalance(Node *root)
{
    if (root == NULL)
        return 0;

    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1)
        return -1;

    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1)
        return -1;

    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(Node *root)
{
    return checkBalance(root) != -1;
}

int main()
{

    // Creating a sample tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    if (isBalanced(root))
        cout << "Binary Tree is Height Balanced" << endl;
    else
        cout << "Binary Tree is NOT Height Balanced" << endl;

    return 0;
}