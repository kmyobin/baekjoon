#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[1000000];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A, A+N);
	for (int i = 0; i < N; i++)
	{
		printf("%d\n", A[i]);
	}
}