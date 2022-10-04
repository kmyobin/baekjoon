#include <iostream>
using namespace std;

int N, M; // N개의 수를 M개 이하의 구간으로 나눔
int X[5000];
int minimum = 50000000;

// 조건
// 무조건 연속된 수가 되게 나눠야 함
// 각 구간의 점수의 최댓값을 구하는데, 이것들의 집합의 최솟값을 구함
// 구간의 점수 : 구간에 속한 수의 최댓값 - 최솟값
// 구간의 점수의 범위 : 0 ~ 10,000

// 최적화 문제 : 구간의 점수의 최댓값의 최솟값
// 결정 문제 : 구간의 점수의 최댓값이 X일 째 
void BinarySearch(int start, int end) {
	if (start > end) {
		return;
	}
	
	int key = (start + end) / 2;
	int cnt = 1;
	
	int mini = 50000000; int maxi = -1;
	// 구간들의 최댓값을 구하고
	for (int i = 0; i < N; i++) {
		mini = min(mini, X[i]);
		maxi = max(maxi, X[i]);

		if (maxi - mini > key) {
			cnt++;
			maxi = X[i]; 
			mini = X[i];
		}
	}

	if (cnt <= M) {
		minimum = (key < minimum) ? key : minimum;
		BinarySearch(start, key - 1);
	}
	else {		
		BinarySearch(key + 1, end);
	}
		
	
}


int main() {
	cin >> N >> M;
	
	int sum = 0;
	int mini = 10000; int maxi = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		mini = (X[i] < mini) ? X[i] : mini;
		maxi= (X[i] > maxi) ? X[i] : maxi;
	}

	// 각 구간의 점수의 범위 : x2-x1 ~ xn-x1
	BinarySearch(0, maxi);

	cout << minimum;
}