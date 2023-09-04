#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M;
int A[9][9];
vector<pair<int, int>> cctv;
int dr[4] = { 0,1,0,-1 }; int dc[4] = { 1,0,-1,0 }; // 동 남 서 북 
int answer = 64;

// default 방향 정해놓음
// 1번 CCTV : 동 (4)
// 2번 CCTV : 가로 (2)
// 3번 CCTV : 북동 (4)
// 4번 CCTV : 서북동 (4)
// 5번 CCTV : 동서남북 (1)

// 0 : 동, 1 : 남, 2 : 서, 3 : 북

int blind_spot() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i][j] == 0)cnt++;
        }
    }

    return cnt;
}

bool safe(int r, int c) {
    return (1 <= r && r <= N) && (1 <= c && c <= M);
}

void check(int r, int c, int dir) {
    dir %= 4; // 0<=dir<=3
    int new_r = r; int new_c = c;
    while (1) { 
        new_r += dr[dir];
        new_c += dc[dir];
        if (!safe(new_r, new_c) || A[new_r][new_c] == 6) return; // 범위 밖이거나 벽이면 패스
        if (safe(new_r, new_c) && A[new_r][new_c] == 0)A[new_r][new_c] = 10; // 감시구역이면 10으로 update
    }
}

void dfs(int index) {
    if (index == cctv.size()) {
        int temp_res = blind_spot();
        answer = (answer < temp_res) ? answer : temp_res;
        return;
    }
    int r = cctv[index].first;
    int c = cctv[index].second;

    // 기존 배열 저장
    int backup[9][9];
    
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                backup[i][j] = A[i][j]; // backup에 기존 A 저장
            }
        }

        if (A[r][c] == 1) {
            check(r, c, dir);
        }
        if (A[r][c] == 2) {
            check(r, c, dir);
            check(r, c, dir + 2);
        }
        if (A[r][c] == 3) {
            check(r, c, dir);
            check(r, c, dir + 3);
        }
        if (A[r][c] == 4) {
            // 0 2 3 (서북동), 1 3 4 (남 북 동)
            check(r, c, dir);
            check(r, c, dir + 3);
            check(r, c, dir + 2);
        }
        if (A[r][c] == 5) {
            check(r, c, dir);
            check(r, c, dir + 1);
            check(r, c, dir + 2);
            check(r, c, dir + 3);
        }

        dfs(index + 1); // index 바꾸고
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                A[i][j] = backup[i][j]; // 기존꺼 A에 덮어씀으로써 새로운 dir 탐색 준비 완료
            }
        }
    }

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
            if (1 <= input && input <= 5) {
                // CCTV라면
                cctv.push_back(make_pair(i, j));
            }
        }
    }    
    dfs(0);

    cout << answer;
    return 0;
}