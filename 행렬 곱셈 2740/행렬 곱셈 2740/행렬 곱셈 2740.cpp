#include <iostream>
using namespace std;

int N, M, K;
int A[101][101], B[101][101];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	cin >> M >> K;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= K; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			int sum = 0;
			for (int k = 1; k <= M; k++) {
				sum += A[i][k] * B[k][j];
			}

			cout << sum << " ";
		}
		cout << endl;
	}
}