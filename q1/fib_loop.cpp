#include<iostream>
#include<ctime>
using namespace std;

long long int fib_loop(int n) {
    if (n <= 1) {return n;}
    long long int a = 0;
    long long int b = 1;

    for (int i = 0; i < n; i++) {
        a = a + b;
        b = a - b;
    }

    return a;
}

int main() {
    timespec ts, te;
    timespec_get(&ts, TIME_UTC);
    long long int fibonacci[51];
    for (int i = 0; i < 51; i++) {
        fibonacci[i] = fib_loop(i);
    }
    timespec_get(&te, TIME_UTC);
    cout << "Time taken is: " << (te.tv_nsec - ts.tv_nsec) / float(1000000000) << " sec" << endl;
    for (int i = 0; i < 51; i++) {
        cout << fibonacci[i] << " ";
    }
}