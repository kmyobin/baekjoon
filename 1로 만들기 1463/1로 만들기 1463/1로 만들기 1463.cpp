#include <iostream>
#include <cmath>
using namespace std;

int N;
int A[1000001] = { 0, 0, 1, 1, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 4; i <= N; i++) {
		int min1 = 0; 
		int min2 = 1000000; 
		int min3 = 1000000;

		min1 = A[i - 1];
		if (i % 3 == 0) { // 3으로 나누어 떨어지면
			min2 = A[i / 3];
		}
		if (i % 2 == 0) { // 2로 나누어 떨어지면
			min3 = A[i / 2];
		}

		A[i] = 1 + min(min1, min(min2, min3));
	}

	cout << A[N];
}