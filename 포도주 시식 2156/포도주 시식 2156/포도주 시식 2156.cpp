#include <iostream>
#include <cmath>
using namespace std;

int N;
int A[10000]; int DP[10000];

// DP[i] : i번째에서의 포도주 최댓값
// 현재 포도주를 선택하지 않는 조건도 생각해야함

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	DP[0] = A[0];
	DP[1] = A[0] + A[1];
	DP[2] = max(DP[1], max(A[0] + A[2], A[1] + A[2])); // 2번째를 선택하지 않는 조건(DP[1])도 생각

	for (int i = 3; i < N; i++) {
		int d1, d2,d3;
		// i번째에 있는 걸 선택 o
		d1 = A[i] + A[i - 1] + DP[i - 3];
		d2 = A[i] + DP[i - 2];

		// i번째에 있는 걸 선택 x
		d3 = DP[i - 1];
		DP[i] = max(d3, max(d1, d2));
	}

	cout << DP[N - 1];
}