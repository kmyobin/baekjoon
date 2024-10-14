#include <iostream>
using namespace std;

int A[10][10];
int main() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> A[i][j];
		}
	}

	int max_r = 1, max_c = 1;
	int max_value = A[1][1];

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (A[i][j] > max_value) {
				max_r = i; max_c = j;
				max_value = A[i][j];
			}
		}
	}

	cout << max_value << "\n" << max_r << " " << max_c;
}