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
        prev = next = NULL;
    }
};

class Deque
{
private:
    Node *front;
    Node *rear;

public:
    Deque()
    {
        front = rear = NULL;
    }

    // Insert at front
    void enqueueFront(int value)
    {
        Node *newNode = new Node(value);

        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }

        cout << value << " inserted at front.\n";
    }

    // Insert at rear
    void enqueueRear(int value)
    {
        Node *newNode = new Node(value);

        if (rear == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << value << " inserted at rear.\n";
    }

    // Delete from front
    void dequeueFront()
    {
        if (front == NULL)
        {
            cout << "Deque Underflow\n";
            return;
        }

        Node *temp = front;

        cout << "Deleted from front: "
             << front->data << endl;

        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            front->prev = NULL;
        }

        delete temp;
    }

    // Delete from rear
    void dequeueRear()
    {
        if (rear == NULL)
        {
            cout << "Deque Underflow\n";
            return;
        }

        Node *temp = rear;

        cout << "Deleted from rear: "
             << rear->data << endl;

        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            rear = rear->prev;
            rear->next = NULL;
        }

        delete temp;
    }

    // Display deque
    void display()
    {
        if (front == NULL)
        {
            cout << "Deque is Empty\n";
            return;
        }

        Node *temp = front;

        cout << "Deque Elements: ";

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Deque dq;
    int choice, value;

    do
    {
        cout << "\n===== DEQUE MENU =====\n";
        cout << "1. Enqueue Front\n";
        cout << "2. Enqueue Rear\n";
        cout << "3. Dequeue Front\n";
        cout << "4. Dequeue Rear\n";
        cout << "5. Display\n";
        cout << "6. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            dq.enqueueFront(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            dq.enqueueRear(value);
            break;

        case 3:
            dq.dequeueFront();
            break;

        case 4:
            dq.dequeueRear();
            break;

        case 5:
            dq.display();
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 6);

    return 0;
}