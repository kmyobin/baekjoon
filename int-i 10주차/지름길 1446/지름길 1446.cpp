#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int n, d;

vector<pair<int, int>> A[10001];

int d_[10001]; // 지름길 누적해서 저장

void input() {
	cin >> n >> d;
	for (int i = 0; i <= d; i++)
	{
		d_[i] = 10001; // 일단 최댓값으로 초기화
	}
	d_[d] = d;
	for (int i = 0; i < n; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		if (to - from <= cost)continue; // 지름길이 아닌경우
		if (to > d)continue; // 거리를 넘어가는 경우
		A[from].push_back(make_pair(to, cost));
	}
}

void solve() {
	// d_배열 상태 : d 인덱스 빼고는 다 1001로 초기화
	// d_ : i에 도착하기 위한 최소 운전 거리 저장
	int prev = -1;
	for (int i = 0; i <= d; i++) {
		if (i != 0)prev = d_[i - 1]; 
		d_[i] = min(d_[i], prev + 1);
		for (auto next : A[i]) { // A를 next로 읽어온다
			if (d_[i] + next.second < d_[next.first]) { // 지름길로 이동했을 때 < 이전 경로에서 운전했을 때 
				d_[next.first] = d_[i] + next.second; // 그 다음 갈 곳에 저장해놓는다
			}
		}
	}
}

void output() {
	cout << d_[d];
}

int main() {
	input();
	solve();
	output(); 
}