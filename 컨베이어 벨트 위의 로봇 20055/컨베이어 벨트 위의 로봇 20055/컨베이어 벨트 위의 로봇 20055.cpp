#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<pair<int, int >> A;
// first : 컨베이어벨트 번호(불변)
// second : 컨베이어벨트 번호의 내구도
// A의 index : 실시간으로 업데이트 되는 위치
// A[0] : 올리는 위치
// A[N-1] : 내리는 위치
int Robot[101]; // 로봇의 현재 위치

void print() {
	cout << "--" << endl;
	for (int i = 0; i < 2 * N; i++) {
		cout << A[i].first << " ";
	}
	cout << endl;
	for (int i = 0; i < 2 * N; i++) {
		cout << A[i].second << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << Robot[i] << " ";
	}
	cout << "\n--" << endl;

}

bool checkBelt() {
	int cnt = 0;
	for (auto a : A) {
		if (a.second == 0) cnt++;
		if (cnt >= K) return false; // 내구도 망한게 K개 이상이면 false
	}

	return true;
}

void minusDurability(int index) {
	// index번 컨베이어벨트의 내구도 1 깎기
	A[index].second--;
}

void rotate() {
	// 벨트 회전
	pair<int, int> temp, before;
	pair<int, int> index_0 = A[A.size() - 1];
	before = A[0];
	for (int i = 0; i < A.size() - 1; i++) {
		// 1 ~ 마지막 인덱스까지 접근
		temp = A[i + 1]; // 미리 담고
		A[i + 1] = before; // A[i+1] 업데이트하고
		before = temp; // before에 아까 기억한 temp 넣기
	}
	A[0] = index_0; // 맨 마지막 값 미리 저장했던거 A[0]에 넣기

	// 로봇 회전
	int temp_,before_;
	before_ = Robot[0];
	Robot[0] = 0; // 그냥 미는 것이므로 0
	for (int i = 0; i < N - 1; i++) {
		temp_ = Robot[i + 1];
		Robot[i + 1] = before_;
		before_ = temp_;

		if (Robot[i + 1] == 1 && i + 1 == N - 1) {
			// i+1에 로봇이 있고 i+1이 내리는 위치(N-1)라면
			Robot[i + 1] = 0; // 내려
		}
	}
}

bool isRobot(int index) {
	// 해당 인덱스에 로봇 있는지
	if (Robot[index] != 0) return true; // 로봇 있다
	return false;
}

bool getDurability(int index) {
	// 해당 인덱스의 내구도가 1이상인지
	if (A[index].second >= 1) return true; 
	return false;
}

void move() {
	// 로봇 이동
	for (int i = N - 2; i > 0; i--) {
		// 가장 먼저 벨트에 올라간 것부터 탐색해야되므로 역순 탐색
		if (Robot[i] != 0) {
			// 해당 인덱스에 로봇이 있다면
			if (!isRobot(i + 1) && getDurability(i + 1)) {
				// 다음 인덱스에 로봇 없고 내구도 1 이상이면
				Robot[i + 1] = 1;
				Robot[i] = 0;
				minusDurability(i + 1);
				if (i + 1 == N - 1) {
					// 이동해서 내려야 되면
					Robot[i + 1] = 0;
				}
			}
		}
	}
}


int main() {
	cin >> N >> K;

	for (int i = 1; i <= 2 * N; i++) {
		int input;
		cin >> input;
		A.push_back(make_pair(i, input));
	}

	int order = 0; // 단계 저장
	while (1) {
		order++; 
		rotate(); // 1단계
		move(); // 2단계

		// 3단계
		if (A[0].second != 0) {
			Robot[0] = 1; // 올리는 위치에 로봇 올림
			minusDurability(0);
		}

		// 4단계
		if (!checkBelt()) {
			// K개 이상 내구도가 무너졌다면 종료
			cout << order;
			break;
		}
	}
}