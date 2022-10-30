#include <iostream>
#include <cmath>
using namespace std;
// 1. 계단은 한 번에 1, 2칸씩
// 2. 시작점 제외하고 연속해서 3계단 밟지 마라
// 3. 마지막 도착 계단은 밟아라

int N;
int A[301]; int DP[301]; // i번째 계단에서의 최댓값

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	// 초기값 설정
	DP[1] = A[1];
	DP[2] = max(A[1] + A[2], A[2]); // 시작->1->2번째 계단 or 시작->2번째 계단
	DP[3] = max(A[1] + A[3], A[2] + A[3]); // 시작->1->3번째 계단 or 시작->2->3번째 계단 비교

	for (int i = 4; i <= N; i++) {
		int d1, d2;
		d1 = DP[i - 3] + A[i - 1] + A[i]; // 바로 전계단 밟음(그러면 전전전계단을 밟아야하므로 i-3)
		d2 = DP[i - 2] + A[i]; // 전전계단 밟음
		DP[i] = max(d1, d2);
	}

	cout << DP[N];
}