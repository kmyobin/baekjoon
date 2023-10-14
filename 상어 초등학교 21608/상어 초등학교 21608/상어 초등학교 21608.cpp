#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>
#include <cmath>
using namespace std;


int N;
int A[21][21];
int students[401][5]; 
vector<vector<int>> v(401, vector<int>(4, 0));


bool safe(int r, int c) {
	return 1 <= r && r <= N && 1 <= c && c <= N;
}
bool cmp(int a, int b) {
	return a > b;
}

void printTemp(int tmp[][21]) {

	cout << "-----temp\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << tmp[i][j] << " ";
		}
		cout << endl;
	}
}
void printA() {
	cout << "-----A\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N * N; i++) {
		int num, f1, f2, f3, f4;
		cin >> num >> f1 >> f2 >> f3 >> f4;
		students[i][0] = num;
		students[i][1] = f1; students[i][2] = f2; students[i][3] = f3; students[i][4] = f4;

		// 학생 번호로 접근하기 위한 벡터 업데이트
		v[num].push_back(f1);
		v[num].push_back(f2);
		v[num].push_back(f3);
		v[num].push_back(f4);
	}

	for (int k = 0; k < N * N; k++) {
		int num = students[k][0]; // 학생 번호
		int temp[21][21] = { 0 };
		
		// 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int cnt = 0;
				if (A[i][j] == students[k][1]) cnt++;
				if (A[i][j] == students[k][2]) cnt++;
				if (A[i][j] == students[k][3]) cnt++;
				if (A[i][j] == students[k][4]) cnt++;

				if (safe(i - 1, j) && A[i-1][j]==0)temp[i - 1][j] += cnt;
				if (safe(i + 1, j) && A[i + 1][j] == 0)temp[i + 1][j] += cnt;
				if (safe(i, j - 1) && A[i][j-1] == 0)temp[i][j - 1] += cnt;
				if (safe(i, j + 1) && A[i ][j+1] == 0)temp[i][j + 1] += cnt;
			}
		}

		// 비어있는 인접칸의 개수를 센다.
		vector<int> max_cnt(N * N, 0);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (temp[i][j] > 0) max_cnt.push_back(temp[i][j]);
			}
		}
		sort(max_cnt.begin(), max_cnt.end(), cmp); // 내림차순 정렬

		if (max_cnt[0] == max_cnt[1]) {
			// 중복된 값이 존재한다면
			// 5 5 2 1 ..
			// 0 0 0 .. (아무 값도 들어가지 못한 것) == 좋아하는 학생이 없던 것
			// 2. 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.

			// 아무 값도 들어가지 못했다면
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (temp[i][j] == max_cnt[0] && A[i][j] == 0) {
						// 이미 업데이트 된 곳에서, 추가적으로 비어있는 공간이라면
						if (safe(i - 1, j) && A[i - 1][j] == 0) temp[i][j]++;
						if (safe(i + 1, j) && A[i + 1][j] == 0) temp[i][j]++;
						if (safe(i, j - 1) && A[i][j - 1] == 0) temp[i][j]++;
						if (safe(i, j + 1) && A[i][j + 1] == 0) temp[i][j]++;
					}
				}
			}

			max_cnt.clear();
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (temp[i][j] >= 0) max_cnt.push_back(temp[i][j]);
				}
			}
			sort(max_cnt.begin(), max_cnt.end(), cmp); // 내림차순 정렬
				
		}

		bool isDone = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (temp[i][j] == max_cnt[0] && A[i][j] == 0) {
					// 제일 최댓값
					A[i][j] = num;
					isDone = true;
					break;
				}
			}
			if (isDone)break;
		}
	}

	// 만족도 계산
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num = A[i][j];
			int total_num = 0;
			if (safe(i + 1, j) && 
				find(v[num].begin(), v[num].end(), A[i + 1][j])!=v[num].end()) total_num++;			
			if (safe(i - 1, j) &&
				find(v[num].begin(), v[num].end(), A[i - 1][j]) != v[num].end()) total_num++;			
			if (safe(i , j+1) &&
				find(v[num].begin(), v[num].end(), A[i][j+1]) != v[num].end()) total_num++;			
			if (safe(i , j-1) &&
				find(v[num].begin(), v[num].end(), A[i][j-1]) != v[num].end()) total_num++;
			answer += pow(10, total_num - 1);
		}
	}

	cout << answer;
}