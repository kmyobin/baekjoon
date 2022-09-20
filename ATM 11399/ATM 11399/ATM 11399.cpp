#include <iostream>
#include <algorithm>
using namespace std;

int N;
int P[1001];
int sum;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}

	sort(P, P + N);

	for (int i = 0; i < N; i++) {
		sum += P[i] * (N - i);
	}
	cout << sum;
}