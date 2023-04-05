#include <iostream>
#include <cmath>
using namespace std;

int N;
int T[17]; int P[17];
int A[17];
/*
	A[i] = i일까지 얻는 이익
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	// 그 다음날에 돈이 들어온다고 가정
	for (int i = 1; i <= N ; i++) {
		// i번째 날에 일 했을 경우
		if (i + T[i] <= N + 1) {
			// 퇴사 전 날까지만 일해야 함
			A[i + T[i]] = max(A[i + T[i]], A[i] + P[i]);
		}
				// i번째 날에 일을 하지 않았을 경우
		A[i + 1] = max(A[i + 1], A[i]);
	}

	cout << A[N + 1];
}