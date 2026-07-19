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

class LinkedList
{
private:
    Node *head;

public:
    LinkedList()
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

    // Reverse the linked list
    void reverse()
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *nextNode = NULL;

        while (curr != NULL)
        {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        head = prev;
    }

    // Display list
    void display()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

int main()
{
    LinkedList list;
    int n, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> value;
        list.insert(value);
    }

    cout << "\nOriginal Linked List:\n";
    list.display();

    list.reverse();

    cout << "\nReversed Linked List:\n";
    list.display();

    return 0;
}