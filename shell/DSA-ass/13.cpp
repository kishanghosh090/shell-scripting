#include <iostream>
using namespace std;

class Queue
{
private:
    int front, rear;
    int arr[100];
    int size;

public:
    Queue(int s = 100)
    {
        size = s;
        front = -1;
        rear = -1;
    }

    void enqueue(int value)
    {
        if (rear == size - 1)
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (front == -1)
            front = 0;

        arr[++rear] = value;

        cout << value << " inserted.\n";
    }

    void dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted Element: "
             << arr[front] << endl;

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
    }

    void display()
    {
        if (front == -1)
        {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue Elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n===== QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.display();
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