#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[12];
int opr[4];
int maximum = -1000000000; // 출력 범위가 10억 이하 -10억 이상이므로
int minimum = 1000000000;

// 사용했던 연산자는 어떻게 확인하는지? -> 연산자를 넘겨주자
// checked 함수를 이용해 모든 연산자를 사용했는지 체크함

bool checked(int p, int mi, int mu, int di) {
	if (p == opr[0] && mi == opr[1] &&
		mu == opr[2] && di == opr[3]) {
		return true;
	}
	return false;
}
void f(int a, int x, int plus, int minus, int multi, int divide) {
	if (checked(plus, minus, multi, divide) == true) { // 모든 연산자를 사용했다면
		maximum = max(a, maximum); // 최대, 최소 설정
		minimum = min(a, minimum);
		return; // 함수 종료
	}

	if (opr[0]>plus) { // 아직 연산자를 다 사용하지 않았다면
		f(a + num[x + 1], x+1, plus + 1, minus, multi, divide); // 연산자를 사용했으므로 +1
	}
	if (opr[1]>minus) {
		f(a - num[x + 1], x+1, plus, minus + 1, multi, divide);
	}
	if (opr[2]>multi) {
		f(a * num[x + 1], x+1, plus, minus, multi + 1, divide);
	}
	if (opr[3]>divide) {
		f(a / num[x + 1], x+1, plus, minus, multi, divide + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> opr[i];
	}

	f(num[0], 0, 0, 0, 0, 0);

	cout << maximum << "\n" << minimum;
}