#include <iostream>
using namespace std;

int N, M;
int A[101];
int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		for (int j = x; j <= y; j++) {
			A[j] = z;
		}
	}
	for (int i = 1; i <= N; i++)cout << A[i] << " ";
}