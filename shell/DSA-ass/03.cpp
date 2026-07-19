#include <iostream>
#include <vector>
using namespace std;

// Linear Search Function
int linearSearch(const vector<int> &arr, int key)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
            return i; // return index if found
    }
    return -1; // not found
}

int main()
{
    int n, key;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = linearSearch(arr, key);

    if (result != -1)
        cout << "Element found at position "
             << result + 1 << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}