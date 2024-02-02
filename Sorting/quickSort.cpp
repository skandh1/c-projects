#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] <= pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSortIterative(vector<int> &arr, int low, int high)
{
    stack<pair<int, int>> stk;
    stk.push({low, high});

    while (!stk.empty())
    {
        pair<int, int> current = stk.top();
        stk.pop();
        low = current.first;
        high = current.second;

        if (low < high)
        {
            int pi = partition(arr, low, high);

            // Push elements before and after the pivot for sorting
            if (pi - 1 > low)
            {
                stk.push({low, pi - 1});
            }
            if (pi + 1 < high)
            {
                stk.push({pi + 1, high});
            }
        }
    }
}

int main()
{
    vector<int> arr = {64, 25, 12, 22, 11, 1};

    cout << "Original Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    int low = 0;
    int high = arr.size() - 1;
    quickSortIterative(arr, low, high);

    cout << "Sorted Array: ";
    for (int num : arr)
        cout << num << " ";
    cout << endl;

    return 0;
}
