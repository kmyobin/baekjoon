#include <iostream>
using namespace std;

int N, M;
int X[100001]; // index 0은 사용하지 않음
// X[i]의 최대 범위 : 1,000*100,000 = 100,000,000


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >>x;
		X[i] = X[i - 1] + x; // 누적합
	}

	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		printf("%d\n", X[y] - X[x - 1]); // cout 쓰면 시간 초과
		// 겹치는 구간을 빼줌
	}

}