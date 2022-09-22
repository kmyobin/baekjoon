#include <iostream>
using namespace std;

int N, F;
int minimum = 2147483647; // 최대로 설정. 이것 때문에 틀림

int main() {
	cin >> N >> F;

	int temp = N - N % 100; // 십의 자리 이하를 모두 0으로 만든 다음 시작
	while (1) {
		if (temp % F == 0) { // 나누어 떨어지면
			minimum = (temp < minimum) ? temp : minimum;
			if (temp >= N) break; // temp가 N보다 커지면 최솟값은 발생하지 않으므로 break
		}
		temp++;
	}

	printf("%02d", minimum % 100); // %02d로 2자리를 0으로 맞춰줌
}