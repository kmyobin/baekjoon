#include <iostream>
using namespace std;

long long n;

// 행렬 계산
long long** matrix(long long** a, long long** b) {
	long long** ans = new long long* [3];
	for (int i = 0; i <= 2; i++)ans[i] = new long long[3];

	for (int i = 1; i <= 2; i++) {
		for (int j = 1; j <= 2; j++) {
			long long sum = 0;
			for (int k = 1; k <= 2; k++) {
				sum += (a[i][k] * b[k][j]);
			}
			ans[i][j] = sum % 1000000007;
		}
	}

	return ans;
}

long long** solve(long long** a, long long b) {
	if (b == 1) return a;	

	if (b % 2 == 0) {
		// even
		long long** x = solve(a, b / 2);
		long long** ans = matrix(x, x);
		return ans;
	}
	else {
		// odd
		long long** x = solve(a, (b - 1) / 2);
		long long** ans = matrix(matrix(x, x), a);
		return ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	long long** A = new long long* [3];
	for (int i = 0; i <= 2; i++)A[i] = new long long[3];
	A[1][1] = 1; A[1][2] = 1; A[2][1] = 1; A[2][2] = 0;

	long long** ans = solve(A, n);
	cout << ans[1][2];
	return 0;
}