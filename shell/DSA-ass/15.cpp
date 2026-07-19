#include <iostream>
using namespace std;

// Recursive Function
long long factorialRecursive(int n)
{
    if (n == 0 || n == 1)
        return 1;

    return n * factorialRecursive(n - 1);
}

// Iterative Function
long long factorialIterative(int n)
{
    long long fact = 1;

    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers.\n";
        return 0;
    }

    cout << "Factorial using Recursion = "
         << factorialRecursive(n) << endl;

    cout << "Factorial using Iteration = "
         << factorialIterative(n) << endl;

    return 0;
}