#include <iostream>
using namespace std;

int N, M;
int A[8];
int before;

void f(int x) {
	if (x == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (i >= before) {
			A[x] = i;
			before = A[x];
			f(x + 1);
			before = A[x];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(0);
}