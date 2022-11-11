#include <iostream>
#include <cmath>
using namespace std;

int N;
int r, c;
int order;

// 큰 것을 작게 쪼갬
// 변의 길이가 2면 더이상 쪼갤 수 없음

void cut(int x, int y, int n) { 
	// x, y : 현재 사분면의 왼쪽 위 좌표
	// 행 열 적합한지?
	if (x == c && y == r) {
		cout << order;
		return;
	}
	if ((y <= r && r < y + n) && (x <= c && c < x + n)) { // 현재 구간 안에 r,c가 있다면
		cut(x, y, n / 2); // 1구간
		cut(x + n / 2, y, n / 2); // 2구간
		cut(x, y + n / 2, n / 2); // 3구간
		cut(x + n / 2, y + n / 2, n / 2); // 4구간
	}
	else { // 없으면 그 전 재귀로 돌아갈텐데 그 전에
		order += n * n; // 안에 있던 순서를 더함
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	cut(0, 0, 1 << N); // 1<<N = pow(2,N)
}