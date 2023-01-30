#include <iostream>
#include <deque>
using namespace std;

int N, M; int cnt;
deque<int> mydeq;
deque<int> order;

void calc_left() {
	// 2번 연산
	int tmp = mydeq.front();
	mydeq.pop_front();
	mydeq.push_back(tmp);
	cnt++;
}

void calc_right() {
	// 3번 연산
	int tmp = mydeq.back();
	mydeq.pop_back();
	mydeq.push_front(tmp);
	cnt++;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		mydeq.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		// 궁금한 순서 입력 받기
		int tmp; cin >> tmp;
		order.push_back(tmp);
	}

	while (1) {
		// order가 비어있으면 끝
		if (order.empty()) break;
		int mid = mydeq.size() / 2; // 중간 인덱스 찾기
		int idx;
		// 원하는 원소의 위치 찾기
		for (int i = 0; i < mydeq.size(); i++)
		{
			if (mydeq[i] == order.front()) {
				// 원하는 원소라면
				idx = i;
				break;
			}
		}
		if (idx <= mid) {
			// 2번 연산 수행
			while (1) {
				if (mydeq.front() == order.front()) {
					mydeq.pop_front();
					order.pop_front();
					break;
				}
				calc_left();
			}
		}
		else {
			// 3번 연산 수행
			while (1) {
				if (mydeq.front() == order.front()) {
					mydeq.pop_front();
					order.pop_front();
					break;
				}
				calc_right();
			}
		}

	}

	cout << cnt;
}