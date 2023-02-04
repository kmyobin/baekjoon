#include <iostream>
#include <string>
using namespace std;

int N;
int A[65][65];

void f(int r, int c, int n) {
	int flag = A[r][c]; bool isCorrect = true;	
	for (int i = r; i <= r + n - 1; i++) {
		for (int j = c; j <= c + n - 1; j++) {
			if (A[i][j] != flag) { // 영상이 모두 같은 숫자가 아니라면
				isCorrect = false;
				break;
			}
		}
		if (!isCorrect) break;
	}

	if (isCorrect) {
		// 주어진 영상의 번호가 다 일치하는 경우
		cout << flag;
	}
	else {
		// 쪼개야되는 경우
		n /= 2;
		cout << "("; // 시작 부분에 "(" 삽입
		f(r, c, n); // 1영역
		f(r, c + n, n); // 2영역
		f(r + n, c, n); // 3영역
		f(r + n, c + n, n); // 4영역
		cout << ")"; // 끝 부분에 ")" 삽입
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		string x;
		cin >> x;
		// 문자열 자르기
		for (int k = 1; k <= N; k++) {
			A[i][k] = x[k - 1] - '0'; // 숫자로 변환
		}
	}

	f(1, 1, N);
}