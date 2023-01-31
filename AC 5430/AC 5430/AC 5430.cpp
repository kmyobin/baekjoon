#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int T;
deque<int> mydeq;

bool D(bool reverse) {
	// true : 에러 발생 O
	// false : 에러 발생 X
	if (mydeq.empty()) return true;
	else {
		// 뒤집혀있으면 맨 뒤가 첫번째 원소인 점을 이용
		// 원래 상태면 맨 앞에 첫번째 원소인 점을 이용
		if (reverse) mydeq.pop_back();
		else mydeq.pop_front();
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string p, arr;
		cin >> p;
		int n; cin >> n; // 실제로 안쓰였음
		cin >> arr;
		int num = 0;
		// 문자열 parsing 후 deque에 집어넣기 
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] == ',' || arr[j] == ']') {
				// 하나의 정수가 완성된 경우
				if (num != 0) mydeq.push_back(num);				
				num = 0;
			} 
			if (48 <= arr[j] && arr[j] <= 57) {
				// 숫자 범위라면
				num = num * 10 + (arr[j] - 48);
			}
		}

		bool isError = false; 
		bool reverse = false; // 배열이 뒤집혀있는지 나타내주는 변수
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				// 뒤집혀있는 상태에서 뒤집으면 원상복구
				// 원래 상태에서 뒤집으면 뒤집혀있는 상태
				reverse = !reverse;
			}
			else {
				isError = D(reverse);
				if (isError) break;
			}
		}

		if (isError) cout << "error\n";
		else {
			cout << "[";
			if (!reverse) {
				// 뒤집혀 있지 않다면 앞부터 출력
				while (1) {
					if (mydeq.empty()) { cout << "]\n"; break; }
					cout << mydeq.front();
					mydeq.pop_front();
					if (!mydeq.empty())cout << ",";
				}
			}
			else {
				// 뒤집혀 있다면 뒤부터 출력
				while (1) {
					if (mydeq.empty()) { cout << "]\n"; break; }
					cout << mydeq.back();
					mydeq.pop_back();
					if (!mydeq.empty())cout << ",";
				}
			}
			
		}
	}
}