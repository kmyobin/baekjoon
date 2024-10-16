#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int B;
string N;

int main() {
	cin >> N >> B;

	int sum = 0;
	for (int i = N.length() - 1; i >= 0; i--) {
		if (N[i] >= 65) {
			// 알파벳인경우
			// A의 아스키코드 : 65, A의 10진법 : 10
			sum += (N[i] - 55) * pow(B, (N.length() - 1) - i);
		}
		else {
			// 숫자인 경우
			sum += (N[i] - '0') * pow(B, (N.length() - 1) - i);
		}
	}

	cout << sum;
}