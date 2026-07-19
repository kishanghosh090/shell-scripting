#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to define operator precedence
int precedence(char op)
{
    if (op == '^')
        return 3;
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return 0;
}

// Check if character is operand
bool isOperand(char ch)
{
    return isalnum(ch);
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";

    for (char ch : infix)
    {

        if (isOperand(ch))
        {
            postfix += ch;
        }

        else if (ch == '(')
        {
            st.push(ch);
        }

        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop(); // remove '('
        }

        else
        { // operator
            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch))
            {
                postfix += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix;

    cout << "Enter Infix Expression: ";
    cin >> infix;

    cout << "Postfix Expression: "
         << infixToPostfix(infix)
         << endl;

    return 0;
}