#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int A[9][9];
queue<pair<int, int>> virus;
int dr[4] = { 1,0,-1,0 }; int dc[4] = { 0,1,0,-1 };
int answer = 0;

bool safe(int r, int c) {
	return 1 <= r && r <= N && 1 <= c && c <= M;
}

void bfs(int temp[][9]) {
	// temp = A 형식으로 하면 포인터라서 call by ref 

	copy(&A[0][0], &A[0][0] + 9 * 9, &temp[0][0]);
	
	queue<pair<int, int>> t_v(virus);

	while (!t_v.empty()) {
		int n_r = t_v.front().first;
		int n_c = t_v.front().second;
		t_v.pop();
		for (int i = 0; i < 4; i++) {
			if (safe(n_r + dr[i], n_c + dc[i]) &&
				temp[n_r + dr[i]][n_c + dc[i]] == 0) {
				temp[n_r + dr[i]][n_c + dc[i]] = 2;
				t_v.push(make_pair(n_r + dr[i], n_c + dc[i]));
			}
		}
	}
}

void print() {
	cout << "--\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--\n";
}

void dfs(int r, int c, int num) {
	if (num >= 3) {
		// 빈 칸 다 채웠다면
		int v[9][9];
		bfs(v); // 확산시키기
		int sum = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (v[i][j] == 0)sum++; // 안전지역 계산
			}
		}
		answer = (answer > sum) ? answer : sum;
		return;
	}

	if (r > N) return; // N행 넘어가면 종료
	
	if (A[r][c] == 0) {
		// 벽이 없는 상태라면
		A[r][c] = 1; // 벽 세우고

		// dfs
		if (c == M) dfs(r + 1, 1, num + 1);
		else dfs(r, c + 1, num + 1);

		A[r][c] = 0; // 벽 안세우고
	}

	// dfs
	if (c == M) dfs(r + 1, 1, num);
	else dfs(r, c + 1, num);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int input;
			cin >> input;
			A[i][j] = input;
			if (input == 2) virus.push(make_pair(i, j)); // virus 담음
		}
	}

	dfs(1, 1, 0);
	cout << answer;
}