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

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
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
    }

    // Delete by value
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted\n";
            return;
        }

        Node *curr = head;

        while (curr->next != NULL &&
               curr->next->data != value)
        {
            curr = curr->next;
        }

        if (curr->next == NULL)
        {
            cout << "Value not found\n";
            return;
        }

        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;

        cout << "Node deleted\n";
    }

    // Display list
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;

        cout << "Linked List: ";

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    SinglyLinkedList list;

    int choice, value;

    do
    {
        cout << "\n===== SINGLY LINKED LIST MENU =====\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

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
            list.display();
            break;

        case 4:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 4);

    return 0;
}