#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int N; int A[100001];
int R[100001]; // R[i] = i번째까지의 연속합의 최댓값
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		R[i] = A[i];
	}
	ans = R[1];

	for (int i = 2; i <= N; i++) {
		R[i] = max(R[i - 1] + A[i], A[i]); // 기존 최댓값+새로운 값 vs 새로운 값
		ans = R[i] > ans ? R[i] : ans;
	}
	printf("%d", ans);

	return 0;
}