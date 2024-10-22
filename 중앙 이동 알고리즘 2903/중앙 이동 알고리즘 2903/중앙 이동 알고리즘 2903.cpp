#include <iostream>
#include <cmath>
using namespace std;

int N;

int A[16];

int main() {
	cin >> N;

	A[0] = 2;
	for (int i = 1; i <= N; i++) {
		A[i] = 2 * A[i - 1] - 1;
	}

	cout << A[N] * A[N];
}