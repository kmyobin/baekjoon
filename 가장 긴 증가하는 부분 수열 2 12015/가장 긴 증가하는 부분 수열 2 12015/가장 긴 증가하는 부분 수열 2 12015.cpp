#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000001];
int N; int idx;

int main() {
	// lower_bound : 원하는 수 이상인 수가 처음으로 등장하는 위치
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int input; 
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (idx == 0) { // 맨 처음
			DP[idx] = input; // 처음 값 설정
			idx++;
		}
		else {
			if (input > DP[idx - 1]) { // 현재 최댓값보다 클 경우
				DP[idx] = input; //  맨 뒤에 새롭게 값을 넣음
				idx++;
			}
			else {  // 최댓값보다 작으면
				// DP 내에서 대체할 수 있는 인덱스를 찾아야 함
				DP[lower_bound(DP, DP + idx, input) - DP] = input;
			}
		}
	}
	cout << idx;
}