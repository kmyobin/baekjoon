#include <iostream>
using namespace std;

char board[51][51];

int minimum = 51*51;
int cnt, cnt_;
int N, M;

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	// 왼쪽 위를 W라고 가정 후 바꿔야 되는 개수 구함
	// minimum과 비교 후 대입
	// 왼쪽 위를 B라고 가정 후 바꿔야 되는 개수 구함
	// minimum과 비교 후 대입
	// 체스판 옮기고 또 반복

	for (int i = 1; i <= N - 7; i++) {
		for (int j = 1; j <= M - 7; j++) {
			cnt = 0; cnt_ = 0;
			
			// 왼쪽 위가 W
			for (int r = i; r <= i + 7; r++) {
				for (int c = j; c <= j + 7; c++) {
					if ((r + c) % 2 == 0) { // 현재 헹 + 열 = 짝수
						if (board[r][c] != 'W')cnt++;
					}
					else { // 현재 행 + 열 = 홀수
						if (board[r][c] != 'B')cnt++;
					}
				}
			}
			if (cnt < minimum)
			{
				minimum = cnt;
			}

			// 왼쪽 위가 B
			for (int r = i; r <= i + 7; r++) {
				for (int c = j; c <= j + 7; c++) {
					if ((r + c) % 2 == 0/*i+j = 짝수*/) {
						if (board[r][c] != 'B')cnt_++;
					}
					else { // i+j = 홀수
						if (board[r][c] != 'W')cnt_++;
					}
				}
			}
			if (cnt_ < minimum) {
				minimum = cnt_;
			}
		}
	}

	cout << minimum;

}