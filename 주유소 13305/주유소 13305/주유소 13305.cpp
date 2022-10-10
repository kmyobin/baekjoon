#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int N;
long long C[100001];
long long M[100000];
long long minimum;

int main() {
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		cin >> M[i];
	}

	for (int i = 0; i < N; i++)
	{
		cin >> C[i];
	}

	minimum = C[0];
	long long sum = 0;
	sum += minimum * M[0];

	for (int i = 1; i < N-1; i++)
	{
		minimum = (C[i] < minimum) ? C[i] : minimum;
		sum += minimum * M[i];
	}

	printf("%ld", sum);

	return 0;
}