#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr = {15, 0, 1, 6, 7, 8};
    int size = arr.size() - 1;
    int start = 0;
    int key = 13;
    int end = size;
    cout << "everything is working\n";

    while (start < end)
    {
        int mid = (start + end) / 2;
        
        if (arr[0] >= arr[mid])
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << start;
    return 0;

}