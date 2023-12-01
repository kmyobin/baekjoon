#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
vector<int> A[2001]; // 배열로 하면 쓸 데 없는 노드도 거쳐야 해서 시간 초과
bool visited[2001];
bool answer;

void backtracking(int r, int cnt) {
	if (answer)return;

	if (cnt == 4) { // 노드 5개, 간선 4개
		answer = true; 
		return;
	}

	visited[r] = true;
	for (auto j : A[r]) {
		if (!visited[j]) {
			// 한번도 방문 x
			if (!visited[j]) backtracking(j, cnt + 1); // 없던 것이어야 함
		}
	}
	visited[r] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		backtracking(i, 0);
		if (answer)break;
		memset(visited, false, sizeof(bool));
	}
	
	if (answer)cout << 1;
	else cout << 0;
}