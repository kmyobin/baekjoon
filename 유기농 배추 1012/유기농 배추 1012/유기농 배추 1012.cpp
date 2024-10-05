#include <iostream>
#include <string.h>
using namespace std;

int dr[4] = {1,0,-1,0};
int dc[4] = { 0,1,0,-1 };

int T;
int M, N, K;
int A[51][51]; // 배추밭 길이 A[r][c]
// 뭉쳐있긴 배추의 개수를 세면 됨

bool safe(int r, int c) {
	return (1 <= r && r <= N && 1 <= c && c <= M);
}

void dfs(int index, int r, int c) {
	A[r][c] = index;

	for (int i = 0; i < 4; i++) {
		int new_r = r + dr[i];
		int new_c = c + dc[i];
		if (safe(new_r, new_c) && A[new_r][new_c] == 1) {
			dfs(index, new_r, new_c);
		}
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;

		for (int j = 0; j < K; j++) {
			int x, y;
			cin >> x >> y; // x : 가로, y : 세로
			A[y+1][x+1] = 1; // 1부터 시작하는 인덱스므로
		}

		int index = 1;
		for (int r = 1; r <= N; r++) {
			// 행 반복
			for (int c = 1; c <= M; c++) {
				// 열 반복
				if (A[r][c] == 1) {		
					index++;
					dfs(index, r, c);
				}
			}
		}

		cout << index - 1 << endl;

		memset(A, 0, sizeof(A)); // 0으로 초기화
	}

}