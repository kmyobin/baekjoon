#include <iostream>
using namespace std;

int N, M;

int A[101];
int maximum = -1;
int sum;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int i = 0; i < N - 2; i++) {
		sum = 0;
		sum += A[i];
		if (sum > M) continue;

		for (int j = i + 1; j < N - 1; j++) {
			sum += A[j];
			if (sum > M) { // sum이 M을 넘어버리면 조건 어긋나므로
				sum -= A[j];
				continue;
			}

			for (int k = j + 1; k < N; k++) {
				sum += A[k];
				if (sum > M) {
					sum -= A[k];
					continue;
				}
				if (sum > maximum) maximum = sum;

				sum -= A[k];
			}

			sum -= A[j];
		}
	}

	cout << maximum;
}