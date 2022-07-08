#include <iostream>
using namespace std;

int N; int sum;
int minimum = 1000001;
bool isit = false;

int main() {
	cin >> N;

	// 생성자 + 각 자리 수 = N
	for (int i = 1; i <= N; i++) {
		sum += i; // 생성자
		sum += (i / 1000000) + 
			((i % 1000000) / 100000) + 
			((i % 100000) / 10000) + 
			((i % 10000) / 1000) + 
			((i % 1000) / 100) + 
			((i % 100) / 10) + 
			(i % 10); // 각 자리 수의 합
		// 구한 분해합과 같고 가장 작은 생성자를 구해야하므로
		if ((sum == N) && (i < minimum)) { isit = true; minimum = i; }
		sum = 0;
	}
	if (isit == true)	cout << minimum;
	else cout << 0; // 생성자가 없는 경우
}