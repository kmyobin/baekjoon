#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int A[100001]; int maximum ;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		A[i] = A[i - 1] + tmp;
		if (i > K) {
			maximum = (A[i] - A[i - K] > maximum) ? A[i] - A[i - K] : maximum;
		}
		else if (i == K) {
			// 초기 최댓값 설정
			maximum = A[i];
		}
	}

	cout << maximum;
}