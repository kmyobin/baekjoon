#include <iostream>
#include <cmath>
using namespace std;

int N, M, x, y, K;
int A[21][21];
int B[3] = { 1,5,3 }; // 현재 주사위의 윗 - 앞 - 옆의 original 번호
int dice[7]; // 주사위 번호에 새겨져있는 수
// dice[B[0]] 형식으로 접근

bool safe(int r, int c) {
	return 1 <= r && r <= N && 1 <= c && c <= M;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}

	x++; y++; // index 1, 1부터 시작하므로
	
	for (int i = 0; i < K; i++) {
		int dir; 
		cin >> dir;
		if (dir == 1) {
			if (safe(x, y + 1)) {
				// 주사위 윗, 앞, 옆 업데이트
				int temp = B[0];
				B[0] = abs(B[2] - 7);
				B[2] = temp;
				y++;
			}
			else continue;
		}
		else if (dir == 2) {
			if (safe(x, y - 1)) {
				// 주사위 윗, 앞, 옆 업데이트
				int temp = B[0];
				B[0] = B[2];
				B[2] = abs(temp - 7);
				y--;
			}
			else continue;
		}
		else if (dir == 3) {
			if (safe(x - 1, y)) {
				// 주사위 윗, 앞, 옆 업데이트
				int temp = B[0];
				B[0] = B[1];
				B[1] = abs(temp - 7);
				x--;
			}
			else  continue;
		}
		else {
			if (safe(x + 1, y)) {
				// 주사위 윗, 앞, 옆 업데이트
				int temp = B[0];
				B[0] = abs(B[1] - 7);
				B[1] = temp;
				x++;
			}
			else continue;
		}

		if (A[x][y] != 0) {
			dice[abs(B[0] - 7)] = A[x][y]; // 칸 -> 주사위 복사
			A[x][y] = 0; // 칸은 0
		}
		else {
			// 칸에 쓰여 있는 수가 0이면
			A[x][y] = dice[abs(B[0] - 7)]; // 주사위 -> 칸 복사
		}
		cout << dice[B[0]] << endl;
	}
}