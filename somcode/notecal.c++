#include<iostream>
using namespace std;

int main(){
    int t500, t200, t100, t50, t20, tat;
    cin >> tat;

    t500 = tat / 500;
    tat = tat % 500;

    t200 = tat / 200;
    tat = tat % 200;

    t100 = tat / 100;
    tat = tat % 100;

    t50 = tat / 50;
    tat = tat % 50;

    t20 = tat / 20;
    tat = tat % 20;


    cout << t500 << t200 << t100 << t50 << t20;
    return 0;
    }