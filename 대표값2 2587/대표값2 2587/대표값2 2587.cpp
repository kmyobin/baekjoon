#include <iostream>
#include <algorithm>
using namespace std;

int A[5]; int sum;

int main() {
	for (int i = 0; i < 5; i++)
	{
		cin >> A[i];
		sum += A[i];
	}

	sort(A, A + 5);
	cout << sum / 5 << "\n" << A[2];
}