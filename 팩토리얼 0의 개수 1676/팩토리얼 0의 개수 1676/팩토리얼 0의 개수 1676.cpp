#include <iostream>
using namespace std;

int A[501];
int N;

void f() {
	int k = 0;
	for (int i = 0; i <= 500; i++) {
		if (i % 5 == 0 && i!=0) { // 5, 10, 15, 20 ,,,
			if (i % 25 == 0) { // 25, 50, 75,,
				if (i % 125 == 0) { // 125, 250, 500
					k++;
				}
				k++;
			}
			k++;
		}
		A[i] = k;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	f();
	cin >> N;

	printf("%d",A[N]);
}