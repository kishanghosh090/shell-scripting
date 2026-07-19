#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList
{
private:
    Node *last;

public:
    CircularLinkedList()
    {
        last = NULL;
    }

    // Insert at end
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (last == NULL)
        {
            last = newNode;
            last->next = last;
            return;
        }

        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }

    // Delete by value
    void deleteNode(int value)
    {
        if (last == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *curr = last->next;
        Node *prev = last;

        do
        {
            if (curr->data == value)
            {

                // Single node case
                if (curr == last && curr == last->next)
                {
                    delete curr;
                    last = NULL;
                }

                // Deleting last node
                else if (curr == last)
                {
                    prev->next = curr->next;
                    last = prev;
                    delete curr;
                }

                // Deleting first or middle node
                else
                {
                    prev->next = curr->next;
                    delete curr;
                }

                cout << "Node deleted\n";
                return;
            }

            prev = curr;
            curr = curr->next;

        } while (curr != last->next);

        cout << "Value not found\n";
    }

    // Search
    void search(int value)
    {
        if (last == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = last->next;
        int position = 1;

        do
        {
            if (temp->data == value)
            {
                cout << "Element found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;

        } while (temp != last->next);

        cout << "Element not found\n";
    }

    // Display
    void display()
    {
        if (last == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = last->next;

        cout << "Circular List: ";

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != last->next);

        cout << "(back to start)\n";
    }
};

int main()
{
    CircularLinkedList list;

    int choice, value;

    do
    {
        cout << "\n===== CIRCULAR LINKED LIST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insert(value);
            break;

        case 2:
            cout << "Enter value to delete: ";
            cin >> value;
            list.deleteNode(value);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 5);

    return 0;
}