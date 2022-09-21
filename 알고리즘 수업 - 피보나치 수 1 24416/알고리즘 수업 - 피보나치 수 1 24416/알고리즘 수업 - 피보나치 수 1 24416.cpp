#include <iostream>
using namespace std;

int F[41]; int cnt1, cnt2;
int N;

int fib(int n) {
  
    if (n == 1 || n == 2) {
        cnt1++;
        return 1;
    }
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    for (int i = 3; i <= n; i++) {
        F[i] = F[i - 1] + F[i - 2];
        cnt2++;
    }
       
    return F[n];
}

int main() {
    F[1] = -1; F[2] = -1;
    cin >> N;

    fib(N); fibonacci(N);
    printf("%d %d", cnt1, cnt2);
}