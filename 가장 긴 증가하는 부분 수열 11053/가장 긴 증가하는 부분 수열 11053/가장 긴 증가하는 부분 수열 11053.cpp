#include <iostream>
using namespace std;

int A[1001]; int N;
int DP[1001] = { 0,1, }; 
// DP[i] : i번째 수를 마지막 원소로 가지는 LIS의 길이
int maximum;
int ans = 1; // 정답은 최소 1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 2; i <= N; i++) {
		maximum = 0;
		for (int j = 1; j < i; j++) { // 최댓값 찾기
			if (A[j] < A[i] && DP[j] > maximum) {
				// 현재 A[i]값보다 작으면서, LIS 길이가 제일 큰 것
				maximum = DP[j]; // maximum에 담음
			}
		}
		DP[i] = maximum + 1; // DP[i]는 maximum으로부터 길이가 1 추가된 것임
		ans = (DP[i] > ans) ? DP[i] : ans; // DP[N]이 최댓값이 아니므로 바로 비교해서 정답에 넣음
	}
	cout << ans;
}