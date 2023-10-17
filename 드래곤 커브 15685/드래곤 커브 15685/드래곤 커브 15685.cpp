#include <iostream>
#include <vector>
using namespace std;

int A[101][101];
int N;

int check() {
	int answer = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (A[i][j] > 0 && A[i][j + 1] > 0
				&& A[i + 1][j] > 0 && A[i + 1][j + 1] > 0)
				answer++;
		}
	}
	return answer;
}

// 점을 90도 시계방향으로 회전하는 함수
pair<int, int> rotatePoint(int x, int y, int center_x, int center_y) {
	int angle = 90; // 90도를 라디안으로 표현
	int s = 1; // sin 90 = 0
	int c = 0; // cos 90 = 0

	// 중심을 기준으로 좌표를 이동
	x -= center_x; y -= center_y;

	// 회전 행렬을 적용 (왜 이렇게 된건진 모르겠음)
	int rotated_x = x * c - y * s;
	int rotated_y = x * s + y * c;

	// 중심을 다시 더해줌
	rotated_x += center_x; rotated_y += center_y;

	return make_pair(rotated_x, rotated_y);
}

bool safe(int x, int y) {
	return 0 <= x && x <= 100 && 0 <= y && y <= 100;
}

void print() {
	cout << "--A\n";
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 6; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		// x : 열, y : 행
		// A[y][x] 형식

		// 드래곤 커브 만들기
		vector<pair<int, int>> v;
		v.push_back(make_pair(x, y)); // 시작점 넣기
		A[y][x] = 1;

		// 0세대 처리
		if (d == 0) {
			// 오른쪽
			v.push_back(make_pair(x + 1, y));
			A[y][x+1] = 1;
		}
		else if (d == 1) {
			// 위쪽
			v.push_back(make_pair(x, y - 1));
			A[y - 1][x] = 1;
		}
		else if (d == 2) {
			// 왼쪽
			v.push_back(make_pair(x - 1, y));
			A[y][x-1] = 1;
		}
		else {
			// 아래쪽
			v.push_back(make_pair(x, y + 1));
			A[y+1][x] = 1;
		}

		for (int k = 1; k <= g; k++) {
			// 해당 세대만큼 반복
			vector<pair<int, int>> new_v; // 해당 세대에 새롭게 추가되는 점들을 담는 벡터
			pair<int, int> center = v[v.size() - 1]; // 끝점 받아옴
			for (int j = v.size() - 2; j >= 0; j--) {
				// 끝부터 회전
				// v.size()-2부터 시작하는 이유 : 끝점은 필요없음
				pair<int, int> rotate_p = rotatePoint(v[j].first, v[j].second, center.first, center.second);
				new_v.push_back(make_pair(rotate_p.first, rotate_p.second));
			}
			// 모두 회전시킨 점들을 벡터에 담았다면
			// 좌표 1로 업데이트
			for (auto p : new_v) {
				if (safe(p.first, p.second)) {
					// 범위 내에 있는 경우에만 배열에 업데이트
					A[p.second][p.first] = 1; // y = p.second, x = p.first인 점 주의
				}
			}

			// 기존 벡터에 붙이기
			vector<pair<int, int>>::iterator it = v.end();
			v.insert(it, new_v.begin(), new_v.end()); // 기존 vector에 붙임
		}
	}

	cout << check();
}