#include <iostream>
using namespace std;


int A[101][101];
int N;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		for (int q = x; q < x + 10; q++) {
			for (int w = y; w < y + 10; w++) {
				A[q][w] = 1;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (A[i][j] == 1)answer++;
		}
	}

	cout << answer;
}