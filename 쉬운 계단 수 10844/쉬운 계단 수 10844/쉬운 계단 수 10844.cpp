#include <iostream>
using namespace std;

int N;
unsigned long long DP[101][10];
unsigned long long sum;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	/* 초기값 설정 */
	for (int i = 0; i <= 9; i++) {
		if (i == 0)DP[1][i] = 0;
		else DP[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) DP[i][j] = DP[i - 1][j + 1] % 1000000000;
			else if (j == 9) DP[i][j] = DP[i - 1][j - 1] % 1000000000;
			else DP[i][j] = (DP[i - 1][j - 1] + DP[i - 1][j + 1]) % 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++) {
		sum += (DP[N][i]);
	}
	cout << sum % 1000000000;

}