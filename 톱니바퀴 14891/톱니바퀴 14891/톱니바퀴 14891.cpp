#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

struct tobni {
	deque<int> wheel;
};

struct tobni tobni[5];
int K;

// 독립적으로 회전시켜라

void turn(struct tobni& tobni, int dir) {
	if (dir == 1) {
		// 시계 방향이라면
		int tmp = tobni.wheel.back();
		tobni.wheel.push_front(tmp);
		tobni.wheel.pop_back();
	}
	else if (dir == -1) {
		// 반시계 방향이면
		int tmp = tobni.wheel.front();
		tobni.wheel.push_back(tmp);
		tobni.wheel.pop_front();
	}
	// dir = 0 : 회전 X
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 4; i++)
	{
		string x;
		cin >> x;
		for (int j = 0; j < 8; j++) {
			tobni[i].wheel.push_back(x[j] - '0'); // ascii 코드 참고
		}
	}

	cin >> K;
	int dirr[5];
	for (int i = 0; i < K; i++)
	{
		int num, dir;
		cin >> num >> dir; // 번호, 방향 입력받음

		for (int i = 0; i < 5; i++) { dirr[i] = 0; } // 방향 초기화
		dirr[num] = dir; // 돌리려는 톱니바퀴 미리 설정

		if (num == 1) { // 1번		
			for (int j = 1; j <= 3; j++) { // 3번 -> 2번 -> 1번 톱니바퀴 순으로 검사
				if (tobni[j].wheel.at(2) != tobni[j + 1].wheel.at(6))
					dirr[j + 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}			
		}
		else if (num == 2) { // 2번
			// 왼쪽
			if (tobni[num - 1].wheel.at(2) != tobni[num].wheel.at(6)) { 
				// 1번 톱니바퀴 검사
				dirr[num - 1] = (dirr[num] == 1) ? -1 : 1;
			}
			// 오른쪽
			for (int j = 2; j <= 3; j++) { // 3번 -> 4번 톱니바퀴 순으로 검사
				if (tobni[j].wheel.at(2) != tobni[j + 1].wheel.at(6))
					dirr[j + 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}
		}
		else if (num == 3) { // 3번
			// 오른쪽
			if (tobni[num].wheel.at(2) != tobni[num + 1].wheel.at(6)) {
				// 4번 톱니바퀴 검사
				dirr[num + 1] = (dirr[num] == 1) ? -1 : 1;
			}
			// 왼쪽
			for (int j = 3; j >= 2; j--) { // 2번 -> 1번 톱니바퀴 순으로 검사
				if (tobni[j - 1].wheel.at(2) != tobni[j].wheel.at(6))
					dirr[j - 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}

		}
		else { // 4번
			for (int j = 4; j >= 2; j--) { // 3번 -> 2번 -> 1번 톱니바퀴 순으로 검사
				if (tobni[j-1].wheel.at(2) != tobni[j].wheel.at(6))
					dirr[j - 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}
		}
		for (int j = 1; j <= 4; j++) turn(tobni[j], dirr[j]); // 일괄 회전
	}

	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		sum += tobni[i].wheel.at(0) * pow(2, i - 1);
	}

	cout << sum;
}