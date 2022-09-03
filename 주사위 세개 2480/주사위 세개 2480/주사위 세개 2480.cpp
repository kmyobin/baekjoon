#include <iostream>
#include <algorithm>
using namespace std;

int A[3];

int main() {
	cin >> A[0] >> A[1] >> A[2];

	sort(A, A + 3);
	if (A[0] == A[1] && A[1] == A[2]) { // ¸ðµÎ °°Àº ´«
		printf("%d", 10000 + A[0] * 1000);
	}
	else {
		if (A[0] == A[1] || A[0] == A[2] || A[1] == A[2]) { // °°Àº ´« 2°³
			if (A[0] == A[1] || A[0] == A[2]) {
				printf("%d", 1000 + A[0] * 100);
			}
			else {
				printf("%d", 1000 + A[1] * 100);
			}
		}
		else { // ¸ðµÎ ´Ù¸¥ ´«
			printf("%d", A[2] * 100);
		}
	}
}