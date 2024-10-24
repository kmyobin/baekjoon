#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[3];
int sum;

int main() {
	cin >> A[0] >> A[1] >> A[2];

	sum += A[0] + A[1] + A[2];
	sort(A, A + 3);

	if (sum == 180) {
		if (A[0] == A[1] && A[1] == A[2])cout << "Equilateral";
		else if (A[0] == A[1] || A[1] == A[2])cout << "Isosceles";
		else cout << "Scalene";
	}
	else {
		cout << "Error";
	}
}