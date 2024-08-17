#include<iostream>
#include<vector>
#include<ctime>
using namespace std;

int N = 1024;

void matmul(vector<vector<int>> (&A), vector<vector<int>> (&B)) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                B[i][j] += A[i][k] * A[k][j];
            }
        }
    }
    return;
}

int create_matrix(vector<vector<int>> (&Matrix)) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Matrix[i][j] = rand() % 100;
        }
    }
    return 0;
}

int main() {
    timespec ts, te, ts1;
    timespec_get(&ts, TIME_UTC);

    vector<vector<int>> matrix(N, vector<int> (N));
    create_matrix(matrix);

    vector<vector<int>> out(N, vector<int> (N));
    
    timespec_get(&ts1, TIME_UTC);
    matmul(matrix, out);
    timespec_get(&te, TIME_UTC);

    cout << "Total Time for N = " << N << " is : " << (te.tv_nsec - ts.tv_nsec) / float(1000000000) << " sec" << endl;
    cout << "Time for meat part for N = " << N << " is : " << (te.tv_nsec - ts1.tv_nsec) / float(1000000000) << " sec" << endl;

    return 0;
}