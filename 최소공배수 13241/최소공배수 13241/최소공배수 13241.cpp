#include <iostream>
#include <cmath>
using namespace std;

long long int A, B;

long long int gcd(long long int a, long long int b) {
	// 유클리드호제법
	if (b == 0) {
		// b가 0이면 a가 최대공약수
		//cout << A << "와 " << B << "의 최대공약수 : " << a << endl;
		return a;
	}

	int n = a % b;
	int m = (a - n) / (a / b);

	return gcd(m, n);
}



int main() {
	cin >> A >> B;
	if (A < B) {
		// 내림차순 정렬
		long long int temp = B;
		B = A;
		A = temp;
	}

	long long int g = gcd(A, B);

	cout << (A * B) / g;
}