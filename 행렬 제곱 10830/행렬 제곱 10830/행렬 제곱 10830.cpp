#include <iostream>
using namespace std;

int N; long long B;

// 행렬 계산
int** matrix(int** a, int** b) {
	// 동적할당
	int** ans = new int* [N + 1];
	for (int i = 0; i <= N; i++)ans[i] = new int[N + 1];
	// 계산
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			long long sum = 0;
			for (int k = 1; k <= N; k++) {
				sum += (a[i][k] * b[k][j]);
			}
			ans[i][j] = sum % 1000;
		}
	}
	return ans;
}

int** f(int**a, long long b) {
	if (b == 1) {
		// 1000으로 나눈 나머지 계산
		// 동적할당
		int** ans = new int* [N + 1];
		for (int i = 0; i <= N; i++)ans[i] = new int[N + 1];
		// 계산
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				ans[i][j] = a[i][j] % 1000;
			}
		}
		return ans;
	}

	if (b % 2 == 0) {
		// even
		int** x = f(a, b / 2);
		int** ans = matrix(x, x);
		return ans;
	}
	else {
		// odd
		int** x = f(a, (b - 1) / 2);
		int** ans = matrix(matrix(x, x), a);
		return ans;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> B;

	// 동적할당
	int** A = new int* [N + 1];
	for (int i = 0; i <= N; i++) {
		A[i] = new int[N + 1];
	}

	// 입력받기
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	int** ans = f(A, B);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
}