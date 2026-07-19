#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int evaluatePrefix(string prefix)
{
    stack<int> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {

        char ch = prefix[i];

        if (isdigit(ch))
        {
            st.push(ch - '0');
        }
        else
        {
            int operand1 = st.top();
            st.pop();

            int operand2 = st.top();
            st.pop();

            switch (ch)
            {
            case '+':
                st.push(operand1 + operand2);
                break;

            case '-':
                st.push(operand1 - operand2);
                break;

            case '*':
                st.push(operand1 * operand2);
                break;

            case '/':
                st.push(operand1 / operand2);
                break;

            case '^':
                st.push(pow(operand1, operand2));
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string prefix;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    cout << "Result = "
         << evaluatePrefix(prefix)
         << endl;

    return 0;
}