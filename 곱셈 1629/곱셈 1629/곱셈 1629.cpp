#include <iostream>
using namespace std;

long long A, B, C;

// 분할정복 거듭제곱 알고리즘
long long dcsquare(long long a, long long b) {
	if (b == 1)return a % C;
	if (b % 2 == 0) {
		// even
		long long x = dcsquare(a, b / 2) % C;
		return (x * x) % C;
	}
	else {
		// odd
		long long x = dcsquare(a, (b - 1) / 2) % C;
		return ((x * x) % C * a) % C;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> C;
	cout << dcsquare(A, B);
}