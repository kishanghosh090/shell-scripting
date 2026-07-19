#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeArrays(const vector<int> &arr1,
                        const vector<int> &arr2)
{
    vector<int> merged;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] <= arr2[j])
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    // Copy remaining elements of arr1
    while (i < arr1.size())
    {
        merged.push_back(arr1[i]);
        i++;
    }

    // Copy remaining elements of arr2
    while (j < arr2.size())
    {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main()
{
    int n1, n2;

    cout << "Enter size of first sorted array: ";
    cin >> n1;

    vector<int> arr1(n1);

    cout << "Enter elements of first sorted array:\n";
    for (int i = 0; i < n1; i++)
        cin >> arr1[i];

    cout << "Enter size of second sorted array: ";
    cin >> n2;

    vector<int> arr2(n2);

    cout << "Enter elements of second sorted array:\n";
    for (int i = 0; i < n2; i++)
        cin >> arr2[i];

    vector<int> merged = mergeArrays(arr1, arr2);

    cout << "Merged Sorted Array: ";
    for (int x : merged)
        cout << x << " ";

    cout << endl;

    return 0;
}