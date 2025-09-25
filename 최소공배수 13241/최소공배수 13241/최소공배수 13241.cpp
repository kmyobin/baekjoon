#include <iostream>
#include <cmath>
using namespace std;

long long int A, B;

long long int gcd(long long int a, long long int b) {
	// ��Ŭ����ȣ����
	if (b == 0) {
		// b�� 0�̸� a�� �ִ�����
		//cout << A << "�� " << B << "�� �ִ����� : " << a << endl;
		return a;
	}

	int n = a % b;
	int m = (a - n) / (a / b);

	return gcd(m, n);
}



int main() {
	cin >> A >> B;
	if (A < B) {
		// �������� ����
		long long int temp = B;
		B = A;
		A = temp;
	}

	long long int g = gcd(A, B);

	cout << (A * B) / g;
}