#include<iostream>
#include<ctime>
#include<stack>
using namespace std;

void fib_loop_memo(int n, long long *fibonacci) {
    for (int i = 2; i < n + 1; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    return;
}

int main() {
    timespec ts, te;
    long long fibonacci[51] = {0};
    fibonacci[1] = 1;
    timespec_get(&ts, TIME_UTC);
    fib_loop_memo(50, fibonacci);
    timespec_get(&te, TIME_UTC);
    cout << "Time taken is: " << (te.tv_nsec - ts.tv_nsec) / float(1000000000) << " sec" << endl;
    for (int i = 0; i < 51; i++) {
        cout << fibonacci[i] << " ";
    }
}