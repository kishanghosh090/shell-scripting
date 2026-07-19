#include <iostream>
using namespace std;

class Node {
public:
    int data;
    int priority;
    Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = NULL;
    }

    // Enqueue with priority
    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);

        if (front == NULL || priority < front->priority) {
            newNode->next = front;
            front = newNode;
            return;
        }

        Node* temp = front;

        while (temp->next != NULL &&
               temp->next->priority <= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Dequeue highest priority element
    void dequeue() {
        if (front == NULL) {
            cout << "Priority Queue Underflow\n";
            return;
        }

        Node* temp = front;

        cout << "Deleted Element: "
             << front->data << endl;

        front = front->next;
        delete temp;
    }

    // Display queue
    void display() {
        if (front == NULL) {
            cout << "Priority Queue is Empty\n";
            return;
        }

        Node* temp = front;

        cout << "\nElement\tPriority\n";

        while (temp != NULL) {
            cout << temp->data
                 << "\t"
                 << temp->priority
                 << endl;

            temp = temp->next;
        }
    }
};

int main() {
    PriorityQueue pq;

    int choice, data, priority;

    do {
        cout << "\n===== PRIORITY QUEUE MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;

            cout << "Enter priority: ";
            cin >> priority;

            pq.enqueue(data, priority);
            break;

        case 2:
            pq.dequeue();
            break;

        case 3:
            pq.display();
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