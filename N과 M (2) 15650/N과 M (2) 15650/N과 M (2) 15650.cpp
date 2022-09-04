#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[8];
bool visited[9];

void f(int x, int cnt) { // x : A배열에 들어가는 숫자, cnt : A배열의 크기
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for (int i = x; i <= N; i++) {
		if (!visited[i]) { // 방문하지 않았다면
			visited[i] = true;
			A[cnt] = i;
			f(i + 1, cnt + 1); // 그 다음 수는 전보다 항상 크게 설정
			visited[i] = false; // 다시 바꿔서 다른 곳으로
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(1,0);
}