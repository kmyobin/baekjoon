#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N;
int A[21][21];
int dr[4] = { -1, 0, 1, 0 }; int dc[4] = { 0, -1, 0, 1 };
int answer = 987654321;

bool safe(int r, int c) {
    return (1 <= r && r <= N) && (1 <= c && c <= N);
}

bool canFeed(int size) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (0 < A[i][j] && A[i][j] < size) return true;
            // 먹을게 하나라도 있으면 true
        }
    }
    return false; // 하나도 없이 for문 다 지나갔으면 false
}

void bfs(int r, int c, int size, int level, int time) {
    // size : 아기 상어 크기, level : 먹은 먹이 수, time : 시간

    int before = time; // 먹을 것이 없을 것을 방지하여 시간 저장(큰 물고기 때문에 못간다던가 . .)

    if (!canFeed(size)) {
        // 아기 상어 크기에 대해 조사했을 때 먹을 거 없으면
        answer = (answer < time) ? answer : time;
        return;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    int dist[21][21];
    memset(dist, -1, sizeof(dist)); // 다 -1로 초기화
    dist[r][c] = 0;

    int min_dist = 987654321;
    while (!q.empty()) {
        int rr = q.front().first;
        int cc = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            // 위쪽, 왼쪽, 아래쪽, 오른쪽
            int new_r = rr + dr[i]; int new_c = cc + dc[i];
            if (safe(new_r, new_c) && A[new_r][new_c] <= size && dist[new_r][new_c] == -1) {
                // 해당 방향으로 갈 수 있고 처음 가는 곳이라면
                dist[new_r][new_c] = dist[rr][cc] + 1; // 그 방향으로 가는 최솟값 없데이트
                q.push(make_pair(new_r, new_c));

                if (0 < A[new_r][new_c] && A[new_r][new_c] < size) {
                    // 먹을 수 있다면                    
                    if (dist[new_r][new_c] < min_dist) {
                        // 심지어 거리가 최솟값이라면
                        min_dist = dist[new_r][new_c]; // 갱신
                        r = new_r; c = new_c; // 다음에 탐색할 좌표 지정 (먹었잖아)
                    }
                    else if (dist[new_r][new_c] == min_dist) {
                        // 최솟값과 동일하다면
                        // 가장 위에 있으면서 왼쪽을 선택해야 함
                        if (new_r < r || (new_r == r && new_c < c)) {
                            r = new_r; c = new_c;
                        }
                    }
                }
            }
        }
    }

    if (min_dist == 987654321) {
        // 최솟값 갱신을 못했다 == 먹을 것이 없다
        time = before; 
        answer = (answer < time) ? answer : time;
        return;
    }
    else {
        // 최솟값 갱신을 했다면
        // 물고기 먹은 것이므로
        time = dist[r][c]; // 물고기를 먹은 위치가 시간이랑 동일함
        A[r][c] = 0; // 먹었으니까 0

        level++;
        if (level == size) {
            size++;
            level = 0;
        }
    }
    
    bfs(r, c, size, level, before + time); // 기존 시간에 새롭게 추가된 시간 더해줌

}

int main() {
    int r = 0, c = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int input;
            cin >> input;
            A[i][j] = input;
            if (input == 9) {
                r = i; c = j;
                A[i][j] = 0;
            }

        }
    }

    bfs(r, c, 2, 0, 0);

    cout << answer;
}