#include<iostream>
#include<ctime>
using namespace std;

long long int memo[50] = {0};

long long int fib_rec_memo(int n) {
    
    if ((n == 0) | (n == 1)) 
    {
        return n;
    }

    if (memo[n-1] == 0) {memo[n-1] = fib_rec_memo(n-1);}
    if (memo[n-2] == 0) {memo[n-2] = fib_rec_memo(n-2);}
    
    return memo[n-1] + memo[n-2];
}

int main() {
    timespec ts, te;
    long long fibonacci[51];
    timespec_get(&ts, TIME_UTC);
    for (int i = 0; i < 51; i++) {
        fibonacci[i] = fib_rec_memo(i);
    }
    timespec_get(&te, TIME_UTC);
    cout << "Time taken is: " << (te.tv_nsec - ts.tv_nsec)/float(1000000000) << " sec" << endl;
    for (int i = 0; i < 51; i++) {
        cout << fibonacci[i] << " ";
    }
}