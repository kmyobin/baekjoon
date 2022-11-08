#include <iostream>
using namespace std;

// 0 : white, 1 : blue

int N; int A[129][129];
int white, blue;

void cut(int x, int y, int n) {
	int color = A[x][y]; // 이 구간의 color를 구함
	bool diff = false;

	// 정해진 구간에서 모두 같은 색인지 판별
	for (int i = x; i <= x + n-1; i++) {
		for (int j = y; j <= y + n-1; j++) {
			if (color != A[i][j]) { // 색이 다르다면 
				diff = true; // 빠져나오기
				break;
			}
		}
		if (diff) break;
	}

	if (diff) { // 색이 구간 안에서 다르다면
		// 더 쪼개기
		cut(x, y, n / 2); // 1구간 (왼쪽 위)
		cut(x + n / 2, y, n / 2); // 2구간 (오른쪽 위)
		cut(x, y + n / 2, n / 2); // 3구간 (왼쪽 아래)
		cut(x + n / 2, y + n / 2, n / 2); // 4구간 (오른쪽 아래)
	}
	else {
		if (color == 0) white++;
		else blue++;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}

	cut(1, 1, N);

	printf("%d\n%d", white, blue);
}