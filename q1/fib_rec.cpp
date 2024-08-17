#include<iostream>
#include<ctime>
using namespace std;

long long int fib_rec(int n) {
    
    if ((n == 0) | (n == 1)) 
    {
        return n;
    }

    return fib_rec(n-1) + fib_rec(n-2);
}

int main() {
    timespec ts, te;
    long long fibonacci[51];
    timespec_get(&ts, TIME_UTC);
    for (int i = 0; i < 51; i++) {
        fibonacci[i] = fib_rec(i);
    }
    timespec_get(&te, TIME_UTC);
    cout << "Time taken is: " << te.tv_sec - ts.tv_sec << " sec" << endl;
    for (int i = 0; i < 51; i++) {
        cout << fibonacci[i] << " ";
    }
}