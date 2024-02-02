#include <iostream>
#include <vector>

using namespace std;

class Search {
public:
    int linearSearch(const vector<int>& arr, int target) {
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }

    int binarySearch(const vector<int>& arr, int target) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    Search search;

    int linearTarget = 7;
    int linearResult = search.linearSearch(arr, linearTarget);
    cout << "Linear Search: " << linearResult << endl;

    int binaryTarget = 3;
    int binaryResult = search.binarySearch(arr, binaryTarget);
    cout << "Binary Search: " << binaryResult << endl;

    return 0;
}
