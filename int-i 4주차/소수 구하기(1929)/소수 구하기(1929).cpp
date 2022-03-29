#include <iostream>
#include <cmath>
using namespace std;

int m, n;
int e[1000001];

int main() {
	// 에라토스테네스의 체
	// 배열을 만들어서 어떤 수의 배수이면 배열 값을 0으로 만들어줌
	// 0이 아니다 == 어떤 수의 배수가 아니다 == 소수이다
	// 배열값이 0이 아니면 소수이므로 출력
	// 근데 루트 n 까지만 돌려도 됨
	// 시간복잡도 n*loglogn

	for (int i = 2; i <= 1000000; i++)
	{
		e[i] = 1; // 일단 다 숫자를 채워줌
	}


	for (int i = 2; i <= sqrt(1000000); i++) // 1은 소수가 아니므로 제외
	{
		if (e[i] == 0)continue; // 이미 어떤 수의 배수이므로 건너뜀(시간 복잡도 감소)
		for (int j = 2 * i; j <= 1000000; j += i) {
			e[j] = 0;
		}
	}

	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		if (e[i] != 0) {
			printf("%d\n", i);
		}
	}
}