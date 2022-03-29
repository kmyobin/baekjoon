#include <iostream>
using namespace std;

int main() {
	int h = 0;
	int m = 0;

	// 입력한 시간보다 45분 일찍 울려야 함

	cin >> h >> m;

	if (h >= 0 && h <= 23 && m >= 0 && m <= 59) { // 하루의 시작과 끝
		if (m >= 45) { // 45분 이상이면 45분만 빼면 되므로
			cout << h << " " << m - 45 << endl;
		}
		else if (h == 0) { // 그 전날로 돌아가고 45분 미만일 때
			cout << 23 << " " << m + 60 - 45 << endl;
		}
		else // 예외 상황이면 시간은 1시간 줄어듦
			cout << h - 1 << " " << m + 60 - 45 << endl;
	}
	return 0;
}