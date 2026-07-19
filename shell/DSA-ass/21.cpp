#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node *head;

public:
    DoublyLinkedList()
    {
        head = NULL;
    }

    // Insert at end
    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete by value
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        // Deleting first node
        if (temp == head)
        {
            head = head->next;

            if (head != NULL)
                head->prev = NULL;

            delete temp;
            cout << "Node deleted\n";
            return;
        }

        // Deleting middle or last node
        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        temp->prev->next = temp->next;

        delete temp;

        cout << "Node deleted\n";
    }

    // Search
    void search(int value)
    {
        Node *temp = head;
        int position = 1;

        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << "Element found at position "
                     << position << endl;
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << "Element not found\n";
    }

    // Display
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        cout << "NULL <- ";

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << " -> NULL\n";
    }
};

int main()
{
    DoublyLinkedList list;

    int choice, value;

    do
    {
        cout << "\n===== DOUBLY LINKED LIST MENU =====\n";
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