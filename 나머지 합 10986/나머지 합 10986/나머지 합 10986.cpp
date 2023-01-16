#include <iostream>
using namespace std;

int N, M;
long long S[1000001]; 
long long L[1001] = { 1, };
long long sum;
long long R[1000001];

void f() {
	// 0~i까지 누적합 계산
	// ex) R[3] = 1 + 2 + 3 = 6
	for (int i = 1; i <= N; i++) {
		if (i == 1)R[i] = 1;
		else R[i] = i + R[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(); // 최대 N까지의 누적합을 계산하면 됨

	for (int i = 1; i <= N; i++)
	{
		long long temp; cin >> temp;
		S[i] = S[i - 1] + temp; // 입력값의 누적합
	}

	for (int i = 1; i <= N; i++) {
		// 입력값들을 M으로 나눈 나머지 개수 L배열에 저장
		// L[1] = 입력된 값을 M으로 나눈 나머지가 1인 입력값들의 개수
		L[S[i] % M]++;
	}

	for (int i = 0; i < M; i++) {
		if (L[i] - 1 >= 0) { // 쌍을 이뤄야 함
			sum += R[L[i]-1];
		}
	}

	printf("%lld", sum);
}