#include <iostream>
using namespace std;

int N, K;
long long A[201][201];

void init() {
	for (int i = 1; i <= 200; i++) {
		A[1][i] = i; // 1을 i개의 정수로 나타내는 경우의 수 초기화
	}
}

// A[1][1] = 1, A[1][2] = 3, A[1][3] = 6, A[1][4] = 10, A[1][5] = 10 + 5 = 15
// A[2][1] = 1
// A[2][2] = 4 = A[1][1] + A[1][2]
// A[2][3] = 10 = A[1][1] + A[1][2] + A[1][3]

// A[i][j] = (A[i-1][k]의 합 (1<=k<=j)
void solve() {
	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			long long sum = 0;
			for (int k = 1; k <= j; k++) {
				sum += A[i - 1][k];
			}
			A[i][j] = sum % 1000000000; // overflow 방지
		}
	}

	cout << A[N][K];
}

int main() {
	cin >> N >> K;

	init();
	solve();
}