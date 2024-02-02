#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void selectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j < arr.size(); ++j)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }
    }
    cout << "After sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void bubbleSort(vector<int> &arr)
{
    int i = arr.size() - 1;
    while (i >= 1)
    {
        int j = 0;
        while (j < i)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
            ++j;
        }
        --i;
    }
    cout << "After sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void insertionSort(vector<int> &arr)
{
    int i = 1;
    while (i < arr.size())
    {
        int x = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > x)
        {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = x;
        ++i;
    }
    cout << "After sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void shellSort(vector<int> &arr)
{
    int span = floor(arr.size() / 2);
    while (span >= 1)
    {
        for (int k = 0; k < span; ++k)
        {
            int i = k + 1;
            while (i < arr.size())
            {
                int x = arr[i];
                int j = i - span;
                while (j >= 0 && arr[j] > x)
                {
                    arr[j + span] = arr[j];
                    j -= span;
                }
                arr[j + span] = x;
                i += span;
            }
        }
        span = span / 2;
    }
    cout << "After sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

void mergeSort(vector<int> &arr)
{
    int size = 1;
    int n = arr.size();
    while (size < n)
    {
        int l1 = 0;
        int k = 0;
        vector<int> c;
        while (l1 + size < n)
        {
            int u1 = l1 + size - 1;
            int l2 = u1 + 1;
            int u2 = (l2 + size - 1 < n) ? l2 + size - 1 : n - 1;
            int i = l1;
            int j = l2;
            while (i <= u1 && j <= u2)
            {
                if (arr[i] < arr[j])
                {
                    c.push_back(arr[i]);
                    ++i;
                }
                else
                {
                    c.push_back(arr[j]);
                    ++j;
                }
                ++k;
            }
            while (i <= u1)
            {
                c.push_back(arr[i]);
                ++i;
                ++k;
            }
            while (j <= u2)
            {
                c.push_back(arr[j]);
                ++j;
                ++k;
            }
            l1 = u2 + 1;
        }
        while (k < n)
        {
            c.push_back(arr[k]);
            ++k;
        }
        for (int i = 0; i < n; ++i)
        {
            arr[i] = c[i];
        }
        size = size * 2;
    }
    cout << "After sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> arr = {42, 17, 89, 5, 67, 23, 54, 11, 32, 98, 73, 8, 61, 29, 83, 45, 19, 76, 93, 2};
    cout << "Before sorting: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    selectionSort(arr);

    return 0;
}
