#include <iostream>
using namespace std;

int T, N, M;
int dp[31][31];

int f(int n, int k) {

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 0; i <= k; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
		}
	}

	return dp[n][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	f(30, 30); // 미리 구해놓고 시작

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N >> M;
		printf("%d\n", dp[M][N]);
	}
}