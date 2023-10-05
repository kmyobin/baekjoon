#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int R, C, T;
vector<vector<int>> A(51, vector<int>(51));
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int answer() {
	int sum = 0; 
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(A[i][j]>0) sum += A[i][j];
		}
	}
	return sum;
}

bool safe(int r, int c) {
	return (1 <= r && r <= R) && (1 <= c && c <= C);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	vector<pair<int, int>> v; // 미세먼지
	vector<pair<int, int>> a; // 공기 청정기

	fill(A.begin(), A.end(), vector<int>(51, 0)); // 초기화 안하면 A[i][j] 대입 오류

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int input;
			cin >> input;
			A[i][j] = input;
			if (input > 0) v.push_back(make_pair(i, j));
			if (input < 0) a.push_back(make_pair(i, j));
		}
	}

	int to_r = a[0].first; int to_c = a[0].second;
	int bo_r = a[1].first; int bo_c = a[1].second;

	vector<vector<int>> temp_A; // 동시에 모든 미세먼지가 확산되므로 실시간 업데이트 X
	 
	while (T > 0) {
		T--;

		temp_A = A;

		// 1. 미세먼지 확산
		for (int i = 0; i < v.size(); i++) {
			int r = v[i].first; int c = v[i].second;
			int cur = A[r][c] / 5; // 현재 미세먼지/5

			int cnt = 0; // 확산된 방향의 개수
			for (int dir = 0; dir < 4; dir++) {
				if (safe(r + dr[dir], c + dc[dir])
					&& (A[r + dr[dir]][c + dc[dir]] != -1)) {
					cnt++;
					temp_A[r + dr[dir]][c + dc[dir]] += cur; // update
					temp_A[r][c] -= cur; // 현재 위치 깎기
				}
			}
		}

		// 2. 공기청정기 작동
		int r = to_r, c = to_c + 1;
		int num = 1; int temp = temp_A[r][c]; int cur;

		// 위쪽 공기청정기
		while (1) {
			if (r == to_r && c == to_c) break;
			cur = temp_A[r][c];
			temp_A[r][c] = temp;
			if (r == to_r && c == to_c + 1) {
				// 왼쪽 아래
				num = 1;
				temp_A[r][c] = 0;
			}
			if (r == to_r && c == C) {
				// 오른쪽 아래
				num = 2;
			}
			if (r == 1 && c == C) {
				// 오른쪽 위
				num = 3;
			}
			if (r == 1 && c == 1) {
				num = 4;
			}
			temp = cur;
			if (num == 1) {
				c++;
			}
			else if (num == 2) {
				r--;
			}
			else if (num == 3) {
				c--;
			}
			else {
				r++;
			}
		};

		r = bo_r; c = bo_c + 1;
		num = 1; temp = temp_A[r][c]; 

		// 아래쪽 공기청정기
		while (1) {
			if (r == bo_r && c == bo_c) break;
			cur = temp_A[r][c];
			temp_A[r][c] = temp;
			if (r == bo_r && c == bo_c + 1) {
				// 왼쪽 위
				num = 1;
				temp_A[r][c] = 0;
			}
			if (r == bo_r && c == C) {
				// 오른쪽 위
				num = 2;
			}
			if (r == R && c == C) {
				// 오른쪽 아래
				num = 3;
			}
			if (r == R && c == 1) {
				// 왼쪽 아래
				num = 4;
			}
			temp = cur;
			if (num == 1) {
				c++;
			}
			else if (num == 2) {
				r++;
			}
			else if (num == 3) {
				c--;
			}
			else {
				r--;
			}
		}

		v.clear();
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if(temp_A[i][j]>0) v.push_back(make_pair(i, j)); // 새로 미세먼지 위치 갱신
			}
		}

		A = temp_A;
	}

	cout << answer();

}