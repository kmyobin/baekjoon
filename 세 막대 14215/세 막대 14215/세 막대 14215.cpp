#include <iostream>
#include <algorithm>
using namespace std;

int A[3];

int main() {
	cin >> A[0] >> A[1] >> A[2];
	sort(A, A + 3);

	while (1) {
		if (A[0] + A[1] <= A[2]) {
			A[2]--;
		}
		else {
			cout << A[0] + A[1] + A[2];
			break;
		}
	}
}