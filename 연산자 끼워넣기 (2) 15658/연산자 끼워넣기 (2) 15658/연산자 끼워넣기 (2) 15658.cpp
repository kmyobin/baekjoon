#include <iostream>
using namespace std;

int N;
int A[100];
int maximum = -1000000000;
int minimum = 1000000000;

int p, mi, mu, d;

void foo(int plus, int minus, int multi, int div, int count, int result) {
	if (count >= N) { // 모두 계산했다면
		maximum = (result > maximum) ? result : maximum;
		minimum = (result < minimum) ? result : minimum;
		return;
	}

	if (plus > 0) { // plus 계산을 할 수 있다면
		foo(plus - 1, minus, multi, div, count + 1, result + A[count]);
	}
	if (minus > 0) {
		foo(plus, minus - 1, multi, div, count + 1, result - A[count]);
	}
	if (multi > 0) {
		foo(plus, minus, multi - 1, div, count + 1, result * A[count]);
	}
	if (div > 0) {
		foo(plus, minus, multi, div - 1, count + 1, result / A[count]);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> p >> mi >> mu >> d;

	foo(p, mi, mu, d, 1, A[0]);

	cout << maximum << "\n" << minimum;
}