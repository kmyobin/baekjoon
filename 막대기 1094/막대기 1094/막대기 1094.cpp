#include <iostream>
using namespace std;

int X;
// 64 32 16 8 4 2 1
// 23 = 16 + 4 + 2 + 1 => 4번
// 48 : 32 + 16 => 2번
int cnt;

int main(){
	cin >> X;

	int cur = 64; // 64부터 쪼개기 시작
	while (1) {		
		if (cur > X) { // 원하는 수보다 아직 크면
			cur /= 2; // 반절로 쪼개기
		}
		else {
			if (X - cur >= 0) { // cur(cm)의 막대기로 X를 구성할 수 있다면
				X = X - cur; // cur(cm) 빼주고
				cnt++; // 횟수 증가
			}
		}
		if (X == 0) break; // 구성이 완료됐으면 while문 탈출
	}
	cout << cnt; // 횟수 출력
}