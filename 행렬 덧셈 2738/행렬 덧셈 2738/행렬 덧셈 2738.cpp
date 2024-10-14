#include <iostream>
using namespace std;

int N, M;

int A[101][101];
int B[101][101];

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)cin >> A[i][j];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)cin >> B[i][j];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cout << A[i][j] + B[i][j] << " ";
		cout << endl;
	}
}