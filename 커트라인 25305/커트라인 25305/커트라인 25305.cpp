#include <iostream>
using namespace std;

int N, k, x;
int A[10001]; // 메모이제이션

int main() {
	cin >> N >> k;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		A[input]++;
	}

	bool isit = false;
	for (int i = 10000; i >= 0; i--) {
		while (A[i] != 0) {
			A[i]--;
			k--;
			if (k == 0) {
				printf("%d", i);
				isit = true;
				break;
			}
		}
		if (isit == true) {
			break;
		}
	}
}