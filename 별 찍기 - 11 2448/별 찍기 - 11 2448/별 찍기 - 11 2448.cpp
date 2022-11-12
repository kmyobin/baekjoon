#include <iostream>
using namespace std;

int N;
char A[3072][6143];

void star(int x, int y, int exponent) {
	if (exponent < 1) { // 제일 작은 삼각형이 되면
		A[y][x] = '*';
		A[y + 1][x - 1] = '*'; A[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++) A[y + 2][i] = '*';
		return;
	}
	int p = 1; exponent--; // 지수 감소
	for (int i = 0; i < exponent; i++) {
		p = p << 1; // 2^exponent를 p에 저장
	}
	star(x, y, exponent); // 위
	star(x - 3 * p, y + 3 * p, exponent); // 왼쪽
	star(x + 3 * p, y + 3 * p, exponent); // 오른쪽
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	int a = N / 3;
	int q = 1;
	for (int i = 0;; i++) {
		if (q == a) { a = i; break; }
		q = q << 1; // 2배
	}
	star(N - 1, 0, a);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (A[i][j] == '*') printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}