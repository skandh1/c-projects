#include<iostream>
#include<stack>
using namespace std;

struct bound {
    int lb;
    int ub;
};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int a[], bound p) {
    int down = p.lb;
    int up = p.ub;
    int x = a[down];

    while (down <= up) {
        while (a[down] <= x) {
            down += 1;
        }
        while (a[up] > x) {
            up -= 1;
        }
        if (down <= up) {
            swap(a[down], a[up]);
        }
    }
    swap(a[up], a[p.lb]);

    return up;
}

void quicksort(int a[], int n) {
    stack<bound> s;
    bound p;
    p.lb = 0;
    p.ub = n - 1;

    s.push(p);

    while (!s.empty()) {
        p = s.top();
        s.pop();
        while (p.lb < p.ub) {
            int j = Partition(a, p);
            if (j - p.lb > p.ub - j) {
                s.push({p.lb, j - 1});
                p.lb = j + 1;
            } else {
                s.push({j + 1, p.ub});
                p.ub = j - 1;
            }
        }
    }
}

int main() {
    int a[] = {20, 10, 3, 2, 1, 25, 35, 21, 23, 12, 11};
    int n = sizeof(a) / sizeof(a[0]);
    quicksort(a, n);

    cout << "sorted array" << endl;

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}
