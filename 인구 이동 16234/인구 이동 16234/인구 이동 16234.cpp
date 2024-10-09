#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, L, R;
int A[51][51];
bool visited[51][51];
int dr[4] = {1,0,-1,0}; int dc[4] = {0,1,0,-1};
int sum;

vector<pair<int, int>> v;

bool safe(int r, int c) {
	return 1 <= r && r <= N && 1 <= c && c <= N;
}

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first)return a.second < b.second;
	return a.first < b.first;
}

void dfs(int r, int c) {
	// sum : 인구수 합

	sum += A[r][c];
	v.push_back(make_pair(r, c));
	for (int k = 0; k < 4; k++) {
		int diff = abs(A[r][c] - A[r + dr[k]][c + dc[k]]);
		if (safe(r + dr[k], c + dc[k]) && // 범위 이내
			(L <= diff && diff <= R) && // L이상 R이하 
			!visited[r+dr[k]][c+dc[k]]) { // 방문하지 않은 곳
			visited[r + dr[k]][c + dc[k]] = true;
			
			dfs(r + dr[k], c + dc[k]);
		}
	}	
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----------------\n";
}

int main() {
	cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	int answer = 0;

	while (1) {
		// 초기화
		fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
		int index = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 국경이 없어진 좌표를 담고
				if (!visited[i][j]) {
					visited[i][j] = true;
					dfs(i, j);

					// 중복 제거
					sort(v.begin(), v.end(), cmp);
					v.erase(unique(v.begin(), v.end()), v.end());
					
					if (v.size() == 1) {
						// 연합이 아닌 경우
						index++;
					}
					else {
						// 연합인 경우
						for (auto iter = v.begin(); iter != v.end(); iter++) {
							A[iter->first][iter->second] = sum / v.size();
						}
					}
					v.clear();
					sum = 0;
				}
			}
		}
		if (index == N * N)break; // 모든 곳을 들렀다면 연합이 없는거임

		answer++;		
	}

	cout << answer;
}