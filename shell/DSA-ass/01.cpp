#include <iostream>
#include <queue>
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

class BinaryTree
{
private:
    Node *root;

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

public:
    BinaryTree()
    {
        root = NULL;
    }

    // Insert in Complete Binary Tree
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
            return;
        }

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->left == NULL)
            {
                temp->left = newNode;
                return;
            }
            else
            {
                q.push(temp->left);
            }

            if (temp->right == NULL)
            {
                temp->right = newNode;
                return;
            }
            else
            {
                q.push(temp->right);
            }
        }
    }

    // Search
    bool search(int key)
    {
        if (root == NULL)
            return false;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            if (temp->data == key)
                return true;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        return false;
    }

    // Delete node
    void deleteNode(int key)
    {
        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            if (root->data == key)
            {
                delete root;
                root = NULL;
            }
            return;
        }

        queue<Node *> q;
        q.push(root);

        Node *target = NULL;
        Node *temp;

        while (!q.empty())
        {
            temp = q.front();
            q.pop();

            if (temp->data == key)
                target = temp;

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        if (target != NULL)
        {
            int deepestValue = temp->data;

            queue<Node *> q2;
            q2.push(root);

            while (!q2.empty())
            {
                Node *curr = q2.front();
                q2.pop();

                if (curr->left)
                {
                    if (curr->left == temp)
                    {
                        delete curr->left;
                        curr->left = NULL;
                        break;
                    }
                    q2.push(curr->left);
                }

                if (curr->right)
                {
                    if (curr->right == temp)
                    {
                        delete curr->right;
                        curr->right = NULL;
                        break;
                    }
                    q2.push(curr->right);
                }
            }

            target->data = deepestValue;
        }
    }

    void displayHeight()
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

    void levelOrderTraversal()
    {
        if (root == NULL)
        {
            cout << "Tree is empty\n";
            return;
        }

        queue<Node *> q;
        q.push(root);

        cout << "Level Order: ";

        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);

            if (temp->right)
                q.push(temp->right);
        }

        cout << endl;
    }
};

int main()
{
    BinaryTree tree;
    int choice, value;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Height\n";
        cout << "5. Inorder Traversal\n";
        cout << "6. Preorder Traversal\n";
        cout << "7. Postorder Traversal\n";
        cout << "8. Level Order Traversal\n";
        cout << "9. Exit\n";
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
            tree.deleteNode(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            if (tree.search(value))
                cout << "Found\n";
            else
                cout << "Not Found\n";
            break;

        case 4:
            tree.displayHeight();
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
            tree.levelOrderTraversal();
            break;

        case 9:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 9);

    return 0;
}