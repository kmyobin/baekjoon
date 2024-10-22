#include <iostream>
using namespace std;

int N;
int max_r = -1, max_c = -1;
int min_r = 20002, min_c = 20002;
int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int r, c;
		cin >> r >> c;

		r += 10000; c += 10000;
		max_r = (r > max_r) ? r : max_r;
		max_c = (c > max_c) ? c : max_c;

		min_r = (r < min_r) ? r : min_r;
		min_c = (c < min_c) ? c : min_c;
	}

	if (N == 1) cout << 0;
	else {
		cout << (max_r - min_r) * (max_c - min_c);
	}
}