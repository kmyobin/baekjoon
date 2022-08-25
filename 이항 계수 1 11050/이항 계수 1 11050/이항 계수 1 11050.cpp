#include <iostream>
using namespace std;

int N, K;

int factorial(int n) {
	if (n <= 1)return 1;
	return n * factorial(n - 1);

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	printf("%d", factorial(N) / (factorial(K) * factorial(N - K)));

}