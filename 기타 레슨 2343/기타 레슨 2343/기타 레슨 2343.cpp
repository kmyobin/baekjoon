#include <iostream>
using namespace std;

int N, M;
int X[100000];
int minimum = 1000000000;

// 9 3
// 1 2 3 4 5 6 7 8 9
// 9개의 강의를 3개의 블루레이에 나눠 담아야함
// 1 2 3 4 5 / 6 7 / 8 9 하면
// 1 2 3 4 5 = 15byte
// 6 7 = 13byte
// 8 9 = 17byte
// 블루레이의 크기는 최소 17byte여야 함.
// 다른 경우의 수를 만들었을 때 17보다 더 작을 수가 없음

// 저번 문제와 다른 점 : 정렬 한 다음 풀 수가 없음. 순서가 뒤바뀌면 안되기 때문

// 블루레이의 크기는 최소 1부터 최대 sum(X)

void BinarySearch(int start, int end) {
	if (start > end) { // 탐색 끝났으면 종료
		return;
	}
	int key = (start + end) / 2; // 블루레이 최솟값으로 잡음

	int s = 0;
	int cnt = M;
	bool isover = false;
	for (int i = 0; i < N; i++) {
		if (s + X[i] > key) { // i번째 강의를 넣었을 때 블루레이의 크기보다 강의 영상 크기가 큰 경우
			cnt--;
			if (cnt == 0) { // 이거 안하면 시간 초과. 블루레이 다 쓰면 바로 for문 나가기
				isover = true;
				break;
			}
			i--;
			s = 0; // 영상 총 녹화본 초기화
		}
		else {
			s += X[i]; // 안커지면 아직 여유분 있는 것
		}
	}

	if (isover) { // 블루레이 개수를 초과해서 사용했다면 블루레이의 크기가 모자랐던 것
		BinarySearch(key + 1, end);
	}
	else {
		if (key < minimum) {
			minimum = key;
		}
		BinarySearch(start, key - 1); // 블루레이 더 작게 할 수 있나 찾아보기
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		sum += X[i];
	}

	BinarySearch(1, sum); // 블루레이 크기는 최소 1부터 최대 X 원소들의 합까지
	cout << minimum; // 최소 블루레이 출력
}