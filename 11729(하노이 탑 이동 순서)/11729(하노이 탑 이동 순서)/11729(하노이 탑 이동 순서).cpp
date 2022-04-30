#include <iostream>
#include <cmath>
using namespace std;

/*
1. 틀렸던 점
- vector를 이용하여 위치를 담고 출력하면 시간초과
- 애초에 시간 복잡도가 2^n이라서 바로바로 출력해야함
*/

// A B C

// 분할 정복하자
// n개의 원반을 크게 두부분으로 나눈다
// 1. 한 부분 : 제일 아래에 있는 가장 큰 원반 하나
// 2. 나머지 부분 : 위 부분을 제외한 2~n번 원반들

// 그래서 원반이 2개인 것처럼 해결함
// 1. 2~n번 원반들(from)을 C(temp)를 이용하여 중간 단계 B(to)로 옮기고
// 2. 제일 아래에 있는 가장 큰 원반(from)을 C(to)로 옮기고
// 3. B에 있던 원반(from)을 A(temp)를 이용하여 C(to)로 옮긴다.

int N; int cnt; // cnt는 여기서 필요하진 않지만 원래 이동 횟수를 나타냄

void moveHanoi(int from, int temp, int to, int n) {
	if (n == 1) {
		cnt++;
		printf("%d %d\n", from, to);
	}
	else {
		moveHanoi(from, to, temp, n - 1); // 1번 단계
		cnt++;
		printf("%d %d\n", from, to);
		moveHanoi(temp, from, to, n - 1); // 3번 단계
	}
}


int main() {
	cin >> N;
	
	cout << int(pow(2, N) - 1) << endl;
	moveHanoi(1, 2, 3, N);
}