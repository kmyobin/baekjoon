#include <iostream>
using namespace std;
int N;
int A[41][2];

int main() {

    A[0][0] = 1; A[0][1] = 0;

    for (int i = 1; i <= 40; i++) {
        A[i][0] = A[i - 1][1];
        A[i][1] = A[i - 1][0] + A[i - 1][1];
    }
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cout << A[x][0] << " " << A[x][1] << endl;
    }   
}