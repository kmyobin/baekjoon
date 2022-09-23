#include <iostream>
using namespace std;

int a, b, c, aa, bb, cc;
int w[21][21][21];

int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1; // a,b,c 중 하나라도 0보다 작으면 1
	}
	if (a > 20 || b > 20 || c > 20) { 
		return W(20, 20, 20); // a,b,c 중 하나라도 20보다 크면 W(20,20,20) 호출
	}

	if (w[a][b][c])return w[a][b][c]; // 값이 채워져있다면 바로 반환. 이 코드 없으면 시간 초과. dp(중복된 값을 계산하지 않음)

	if (a < b && b < c) { // a<b<c라면
		w[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c); // 아직 안채워져있다면 재귀를 이용하여 더 아래의 값들을 불러옴
	}
	else {
		w[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
	}
	return w[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a,b,c));
	}

}