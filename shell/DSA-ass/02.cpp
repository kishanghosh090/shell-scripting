#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class BST
{
private:
    Node *root;

    Node *insert(Node *node, int val)
    {
        if (node == NULL)
            return new Node(val);

        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);

        return node;
    }

    Node *findMin(Node *node)
    {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node *deleteNode(Node *node, int key)
    {
        if (node == NULL)
            return NULL;

        if (key < node->data)
            node->left = deleteNode(node->left, key);

        else if (key > node->data)
            node->right = deleteNode(node->right, key);

        else
        {
            // No child
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }

            // One child
            if (node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }

            // Two children
            Node *temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    bool search(Node *node, int key)
    {
        if (node == NULL)
            return false;

        if (node->data == key)
            return true;

        if (key < node->data)
            return search(node->left, key);

        return search(node->right, key);
    }

    int height(Node *node)
    {
        if (node == NULL)
            return -1;

        return 1 + max(height(node->left), height(node->right));
    }

    void inorder(Node *node)
    {
        if (node)
        {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(Node *node)
    {
        if (node)
        {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(Node *node)
    {
        if (node)
        {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }

    int countNodes(Node *node)
    {
        if (node == NULL)
            return 0;

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(int val)
    {
        root = insert(root, val);
    }

    void deleteValue(int key)
    {
        root = deleteNode(root, key);
    }

    void searchValue(int key)
    {
        if (search(root, key))
            cout << "Node Found\n";
        else
            cout << "Node Not Found\n";
    }

    void printHeight()
    {
        cout << "Height = " << height(root) << endl;
    }

    void inorderTraversal()
    {
        cout << "Inorder: ";
        inorder(root);
        cout << endl;
    }

    void preorderTraversal()
    {
        cout << "Preorder: ";
        preorder(root);
        cout << endl;
    }

    void postorderTraversal()
    {
        cout << "Postorder: ";
        postorder(root);
        cout << endl;
    }

    void printNodeCount()
    {
        cout << "Total Nodes = "
             << countNodes(root) << endl;
    }

    void printSmallestNode()
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        Node *temp = findMin(root);
        cout << "Smallest Node = "
             << temp->data << endl;
    }
};

int main()
{
    BST tree;
    int choice, value;

    do
    {
        cout << "\n===== BST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Height\n";
        cout << "5. Inorder Traversal\n";
        cout << "6. Preorder Traversal\n";
        cout << "7. Postorder Traversal\n";
        cout << "8. Number of Nodes\n";
        cout << "9. Smallest Node\n";
        cout << "10. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            tree.insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            tree.deleteValue(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            tree.searchValue(value);
            break;

        case 4:
            tree.printHeight();
            break;

        case 5:
            tree.inorderTraversal();
            break;

        case 6:
            tree.preorderTraversal();
            break;

        case 7:
            tree.postorderTraversal();
            break;

        case 8:
            tree.printNodeCount();
            break;

        case 9:
            tree.printSmallestNode();
            break;

        case 10:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 10);

    return 0;
}