#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void shellSort(vector<int>& arr) {
    for (int span = floor(arr.size() / 2); span >= 1; span /= 2) {
        for (int k = 0; k < span; ++k) {
            for (int i = k + 1; i < arr.size(); i += span) {
                int x = arr[i];
                int j;
                for (j = i - span; j >= 0 && arr[j] > x; j -= span) {
                    arr[j + span] = arr[j];
                }
                arr[j + span] = x;
            }
        }
    }
    cout << "After sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {9, 2, 50, 63, 24, 70, 100, 30, 5, 3, 7};
    cout << "Before sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
    shellSort(arr);

    return 0;
}
