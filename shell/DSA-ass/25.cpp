#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    // Push operation
    void push(int value)
    {
        if (top == 99)
        {
            cout << "Stack Overflow\n";
            return;
        }

        arr[++top] = value;
        cout << value << " pushed into stack.\n";
    }

    // Pop operation
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Popped Element: "
             << arr[top--] << endl;
    }

    // Peek operation
    void peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top Element: "
             << arr[top] << endl;
    }

    // Display operation
    void display()
    {
        if (top == -1)
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack Elements (Top to Bottom): ";

        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        cout << "\n===== STACK MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
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