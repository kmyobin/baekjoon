#include <iostream>
using  namespace std;

int N;
int F, Nx;

int gcd(int a, int b) { // 유클리드 호제법
	int c;
	while (b != 0) {
		c = a % b;
		a = b; b = c;
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> F;
	for (int i = 0; i < N-1; i++)
	{
		cin >> Nx;
		// (제일 첫번째 링 / 최대 공약수) / (해당하는 링 / 최대 공약수)
		int d = gcd(Nx, F); // 작은 것부터 넣어줌
		printf("%d/%d\n", F / d, Nx / d);
	}
}