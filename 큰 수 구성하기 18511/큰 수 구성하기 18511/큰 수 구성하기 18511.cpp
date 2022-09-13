#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int N, k;
int K[3];

int maximum = -1;

void f(int idx, int num, int sum) { // 자릿수 , 지금 들어갈 값
	sum += num * int(pow(10, idx - 1));
	if (sum > N) {
		sum -= num * pow(10, idx - 1);
		if (sum > maximum) {
			maximum = sum;
			//printf("%d는 maximum(%d)보다 크고 %d(N)보다 작습니다.\n", sum, maximum, N);
		}
		return;
	}
	for (int i = 1; i <= k; i++) {
		f(idx + 1, K[i-1], sum);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> K[i];
	}
	f(0, 0, 0);
	printf("%d", maximum);
}