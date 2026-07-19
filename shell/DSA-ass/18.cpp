#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' ||
            ch == '*' || ch == '/' ||
            ch == '^');
}

string prefixToInfix(string prefix)
{
    stack<string> st;

    for (int i = prefix.length() - 1; i >= 0; i--)
    {

        char ch = prefix[i];

        if (isalnum(ch))
        {
            st.push(string(1, ch));
        }
        else if (isOperator(ch))
        {

            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = "(" + op1 +
                          ch +
                          op2 + ")";

            st.push(temp);
        }
    }

    return st.top();
}

int main()
{
    string prefix;

    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    cout << "Infix Expression: "
         << prefixToInfix(prefix)
         << endl;

    return 0;
}