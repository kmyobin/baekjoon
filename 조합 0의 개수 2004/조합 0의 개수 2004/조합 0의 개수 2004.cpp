#include <iostream>
#include <cmath>
using namespace std;

int n, m;

int two(int x) {
	int r = 0;
	for (int i = 1; i <= 30; i++) {
		r += x / pow(2, i);
	}
	return r;
}

int five(int x) {
	int r = 0;
	for (int i = 1; i <= 13; i++) {
		r += x / pow(5, i);
	}
	return r;
}

int main() {
	cin >> n >> m;
	// 5^13 = 1,220,703,125
	// 2^30 = 1,073,741,824

	int R = two(n) - two(n - m) - two(m);
	int S = five(n) - five(n - m) - five(m);

	int F = min(R, S);
	printf("%d", F);

}