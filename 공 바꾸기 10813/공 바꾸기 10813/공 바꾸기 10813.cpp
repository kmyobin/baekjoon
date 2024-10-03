#include <iostream>
using namespace std;

int N, M;
int A[101];
int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)A[i] = i;

	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;

		int tmp = A[x];
		A[x] = A[y];
		A[y] = tmp;
	}
	
	for (int i = 1; i <= N; i++) cout << A[i] << " ";

}