#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[50];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A, A + N);

	cout << A[0] * A[N - 1];
}