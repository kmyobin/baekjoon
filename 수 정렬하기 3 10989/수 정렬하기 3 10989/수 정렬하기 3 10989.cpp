#include <iostream>
using namespace std;

int A[10001];
int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		A[x]++;
	}

	for (int i = 1; i <= 10000; i++) {
		if (A[i]) {
			for (int j = 0; j < A[i]; j++) {
				printf("%d\n", i);
			}
		}
	}
}