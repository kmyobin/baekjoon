#include <iostream>
using namespace std;
#define MAX 51

int N, M, r, c, d;

int A[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;
	// d=0 : 북쪽, d=1 : 동쪽, d=2 : 남쪽, d=3 : 서쪽
	// 로봇 청소기가 있는 곳은 항상 빈 칸
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			// 0이면 청소 안 되어있음
			// 1이면 벽있음
		}
	}

	int sum = 0;
	// 작동을 멈추는 경우는 딱 한 가지 : 뒤쪽 칸이 벽이라 후진할 수 없을 때

	int i = r; int j = c;
	while (1) {
		if (A[i][j] == 0) { // 현재 칸이 청소되지 않은 경우
			A[i][j] = 2; // 청소한 곳은 2로 설정
			sum++;
		}

		// 이제 주변 4칸을 보자
		if (A[i - 1][j] == 0 || A[i + 1][j] == 0 || A[i][j - 1] == 0 || A[i][j + 1] == 0) {
			// 청소되지 않은 빈 칸이 있는 경우
			
			// 반시계 방향으로 90도 회전
			d = (d == 0) ? 3 : d - 1;

			if (d == 0) {
				// 북쪽인 경우
				if (A[i - 1][j] == 0) i--;				
			}
			else if (d == 1) {
				// 동쪽인 경우
				if (A[i][j + 1] == 0) j++;
			}
			else if (d == 2) {
				// 남쪽인 경우
				if (A[i + 1][j] == 0) i++;
			}
			else {
				// 서쪽인 경우
				if (A[i][j - 1] == 0) j--;
			}
		}	
		else {
			// 모두 청소되어 있다면 후진
			if (d == 0) { // 북쪽
				if (A[i + 1][j] != 1) i++;
				else break;
			}
			else if (d == 1) { // 동쪽
				if (A[i][j - 1] != 1) j--;
				else break;
			}
			else if (d == 2) { // 남쪽
				if (A[i - 1][j] != 1) i--;				
				else break;
			}
			else { // 서쪽
				if (A[i][j + 1] != 1) j++;
				else break;
			}
		}
		
	}


	cout << sum;
}