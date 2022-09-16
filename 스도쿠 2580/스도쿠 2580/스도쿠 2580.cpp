#include <iostream>
using namespace std;

int A[10][10];
int cnt;
bool finish;

struct blank {
	int x;
	int y;
};

blank bln[81];

bool is_inArray(int k, int index) {
	if (index == 1) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 1; j <= 3; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 2) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 4; j <= 6; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 3) {
		for (int i = 1; i <= 3; i++) {
			for (int j = 7; j <= 9; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 4) {
		for (int i = 4; i <= 6; i++) {
			for (int j = 1; j <= 3; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 5) {
		for (int i = 4; i <= 6; i++) {
			for (int j = 4; j <= 6; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 6) {
		for (int i = 4; i <= 6; i++) {
			for (int j = 7; j <= 9; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 7) {
		for (int i = 7; i <= 9; i++) {
			for (int j = 1; j <= 3; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else if (index == 8) {
		for (int i = 7; i <= 9; i++) {
			for (int j = 4; j <= 6; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}
	else {
		for (int i = 7; i <= 9; i++) {
			for (int j = 7; j <= 9; j++) {
				if (A[i][j] == k) {
					return true;
				}
			}
		}
	}

	return false;
}

bool is_Correct(int k, int x, int y) {
	// 1. 그 행에 적합한지
	// 2. 그 열에 적합한지
	// 3. 그 정사각형 안에 적합한지

	// 1, 2
	for (int i = 1; i <= 9; i++) {
		if (i != x && A[i][y] == k) return false;
		if (i != y && A[x][i] == k) return false;

	}

	// 3
	if (1 <= x && x <= 3 && 1 <= y && y <= 3) {
		if (is_inArray(k, 1)) return false;	
	}
	if (1 <= x && x <= 3 && 4 <= y&& y <= 6) {
		if (is_inArray(k, 2)) return false;
	}
	if (1 <= x && x <= 3 && 7 <= y && y <= 9) {
		if (is_inArray(k, 3)) return false;
	}

	if (4 <= x && x <= 6 && 1 <= y && y <= 3) {
		if (is_inArray(k, 4)) return false;
	}
	if (4 <= x && x <= 6 && 4 <= y && y <= 6) {
		if (is_inArray(k, 5)) return false;
	}
	if (4 <= x && x <= 6 && 7 <= y && y <= 9) {
		if (is_inArray(k, 6)) return false;
	}

	if (7 <= x && x <= 9 && 1 <= y && y <= 3) {
		if (is_inArray(k,7)) return false;
	}
	if (7 <= x && x <= 9 && 4 <= y && y <= 6) {
		if (is_inArray(k, 8)) return false;
	}
	if (7 <= x && x <= 9 && 7 <= y && y <= 9) {
		if (is_inArray(k, 9)) return false;
	}

	return true;
}

void f(int count) {
	if (count >= cnt) {
		finish = true;
		for (int i = 1; i <= 9; i++) {
			for (int j = 1; j <= 9; j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
		return;
	}

	for (int k = 1; k <= 9; k++) {
		if (is_Correct(k, bln[count].x, bln[count].y)) {
			if (finish)return; // 안하면 여러가지 경우의 수가 출력돼서 무한 루프가 될 수도
			A[bln[count].x][bln[count].y] = k;
			f(count + 1);
			A[bln[count].x][bln[count].y] = 0; // 다시 돌아와서 다른 길로 갈 수 있게끔
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> A[i][j];
			if (!A[i][j]) { // A[i][j]가 0이면
				bln[cnt].x = i;
				bln[cnt].y = j;
				cnt++;
			}
		}
	}

	f(0);
}