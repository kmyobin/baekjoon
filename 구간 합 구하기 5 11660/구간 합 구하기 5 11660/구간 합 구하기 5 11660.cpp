#include <iostream>
using namespace std;

int N, M;
int A[1025][1025];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	// 시간 : 128ms
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			A[i][j] = A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1] + tmp;
		}
	}

	for (int i = 1; i <= M; i++) {
		int r, c, rr, cc;
		cin >> r >> c;
		cin >> rr >> cc;
		printf("%d\n", A[rr][cc] - A[rr][c - 1] - A[r - 1][cc] + A[r - 1][c - 1]);
	}
	/*
	시간 : 428ms
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int tmp; cin >> tmp;
			A[i][j] = A[i][j - 1] + tmp;
		}
	}

	for (int i = 1; i <= M; i++) {
		int r, c, rr, cc;
		cin >> r >> c;
		cin >> rr >> cc;
		for (int j = r; j <= rr; j++) {
			sum += A[j][cc];
			sum -= A[j][c - 1];
		}
		printf("%d\n", sum); // cout 쓰면 시간초과
	}*/
}