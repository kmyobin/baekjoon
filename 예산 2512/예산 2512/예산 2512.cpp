#include <iostream>
#include <algorithm>
using namespace std;

int N;
int INPUT[10000];
int M;
int maximum = -1;

void BinarySearch(int start, int end, int key) {

	if (start > end) { // 다 탐색했으면
		return;
	}
	key = (start + end) / 2; // 상한액으로 잡음

	// key가 상한액인 경우의 총 예산액을 구해봄
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		if (INPUT[i] > key) {
			s += key;
		}
		else {
			s += INPUT[i];
		}
	}

	if (s > M) { // 상한액 오류, 더 작게 잡음
		BinarySearch(start, key - 1, key);
	}
	else { 
		if (key > maximum)maximum = key; // 새로 잡은 상한액이 기존보다 크면 갱신
		BinarySearch(key+1, end, key); // 상한액이 더 커질 수 있는지 더 크게 잡아봄
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> INPUT[i];
		sum += INPUT[i];
	}
	cin >> M;
	
	sort(INPUT, INPUT + N); // 이분 탐색을 위해 정렬
	

	if (sum > M) { // 예산 초과 시
		BinarySearch(1, INPUT[N - 1],-1);

		cout << maximum;
	}
	else { // 예산이 남아돌면
		cout << INPUT[N - 1]; // 각 지역 중 최댓값 출력
	}


}