#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <cmath>
using namespace std;

int dr[4] = { 1,0,-1,0 }; int dc[4] = { 0,1,0,-1 };
vector<vector<int>> table_; vector<vector<int>> game_;
bool visited[51][51];
int R, C;
int result;

// 최대한 많은 조각을 넣어야함 
// 비어있는 곳 세기
// 빈 곳이 table에 있는 조각으로 채울 수 있는지 

struct G {
    int cnt; // 블록 개수
    vector<pair<int, int>> p; // 해당 블록의 원점 이동된 좌표 
    pair<int, int> max_rc; // 해당 블록의 최대 좌표
    pair<int, int> min_rc; // 해당 블록의 최소 좌표
};

struct G gg[2500];

bool safe(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

vector<pair<int, int>> translate_origin(vector<pair<int, int>> v) {
    // 원점 이동 (마이너스 좌표 되지 않도록)
    pair<int, int> min_rc;
    int min_r = 51, min_c = 51;
    for (int j = 0; j < v.size(); j++) {
        min_r = min(v[j].first, min_r); min_c = min(v[j].second, min_c);
    }

    min_rc = make_pair(min_r, min_c);

    // 원점 이동 
    for (int i = 0; i < v.size(); i++) {
        v[i].first -= min_rc.first;
        v[i].second -= min_rc.second;
    }

    sort(v.begin(), v.end()); // 정렬해야 나중에 벡터 비교할 때 편함 
    return v;
}

vector<pair<int, int>> rotate(vector<pair<int, int>> v) {
    int center_r = v[0].first; int center_c = v[0].second; // 제일 첫 좌표 기준으로 회전 (어디로 하든 상관없음)

    int angle = 90; // 90도를 라디안으로 표현
    int s = 1; // sin 90 = 0
    int c = 0; // cos 90 = 0

    for (int i = 0; i < v.size(); i++) {
        // 중심을 기준으로 좌표를 이동
        v[i].first -= center_r;
        v[i].second -= center_c;

        // 회전 행렬을 적용 (왜 이렇게 된건진 모르겠음)
        int rotated_r = v[i].first * c - v[i].second * s;
        int rotated_c = v[i].first * s + v[i].second * c;

        // 중심을 다시 더해줌
        rotated_r += center_r; rotated_c += center_c;
        v[i].first = rotated_r; v[i].second = rotated_c;
    }

    v = translate_origin(v); // 마이너스 좌표가 되지 않게 원점 이동 

    return v;
}

void bfs_table(int r, int c, int z) {
    queue<pair<int, int>> q;

    int cnt = 0; // 블록이 차지하는 정사각형의 개수

    q.push(make_pair(r, c));
    visited[r][c] = true;
    gg[z].p.push_back(make_pair(r, c));
    cnt++;

    while (!q.empty()) {
        int rr = q.front().first; int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (safe(rr + dr[i], cc + dc[i]) && !visited[rr + dr[i]][cc + dc[i]]
                && table_[rr + dr[i]][cc + dc[i]] == 1) { // 블록 발견
                visited[rr + dr[i]][cc + dc[i]] = true;
                gg[z].p.push_back(make_pair(rr + dr[i], cc + dc[i]));
                cnt++;
                q.push(make_pair(rr + dr[i], cc + dc[i]));
            }
        }
    }
    gg[z].cnt = cnt; // 해당 블록이 차지하는 정사각형의 개수 저장
}

void bfs_game(int r, int c, int piece_cnt) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v; // game_board의 비어있는 부분 담기 

    int cnt = 0; // 블록이 차지하는 정사각형의 개수

    q.push(make_pair(r, c));
    v.push_back(make_pair(r, c));
    visited[r][c] = true;
    cnt++;

    while (!q.empty()) {
        int rr = q.front().first; int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (safe(rr + dr[i], cc + dc[i]) && !visited[rr + dr[i]][cc + dc[i]]
                && game_[rr + dr[i]][cc + dc[i]] == 0) {
                visited[rr + dr[i]][cc + dc[i]] = true;
                v.push_back(make_pair(rr + dr[i], cc + dc[i]));
                cnt++;
                q.push(make_pair(rr + dr[i], cc + dc[i]));
            }
        }
    }

    // 빈칸 원점 이동
    v = translate_origin(v);

    // 개수 동일했을 때, 회전하면 같은지
    bool isDone = false;
    for (int i = 0; i < piece_cnt; i++) {
        if (cnt == gg[i].cnt) { // 개수가 같으면
            for (int j = 0; j < 4; j++) { // 4번 회전시키기
                if (v == gg[i].p) { // 같다면
                    result += cnt;
                    gg[i].p = {}; // 썼으니까 빈 배열로 만들어서 다시는 못쓰게
                    isDone = true;
                    break;
                }
                else v = rotate(v); // 같지 않다면 회전                 
            }
        }
        if (isDone)break; // 정답이면 종료
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    R = game_board.size();
    C = R;
    table_ = table; game_ = game_board; // 전역변수 처리

    // table
    int piece_cnt = 0;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.size(); j++) {
            if (table[i][j] == 1 && !visited[i][j]) {
                bfs_table(i, j, piece_cnt);
                piece_cnt++; // 블록의 개수
            }
        }
    }

    // 원점 이동 
    for (int i = 0; i < piece_cnt; i++) gg[i].p = translate_origin(gg[i].p); // 비교하기 쉽도록
    

    // visited 초기화
    for (int i = 0; i < table.size(); i++) {
        memset(visited[i], false, sizeof(bool) * table.size());
    }

    // game_board와 비교
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board.size(); j++) {
            if (game_board[i][j] == 0 && !visited[i][j]) bfs_game(i, j, piece_cnt);            
        }
    }

    return result;
}

int main() {
    vector<vector<int>> game_board = { {1, 1, 0, 0, 1, 0}, { 0,0,1,0,1,0 }, { 0,1,1,0,0,1 }, { 1,1,0,1,1,1 }, { 1,0,0,0,1,0 }, { 0,1,1,1,0,0 } };
    vector<vector<int>> table = { {1,0,0,1,1,0 }, { 1,0,1,0,1,0 }, { 0,1,1,0,1,1 }, { 0,0,1,0,0,0 }, { 1,1,0,1,1,0 }, { 0,1,0,0,0,0 } };

    cout << solution(game_board, table);
}