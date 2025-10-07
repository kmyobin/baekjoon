#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

int n = 4;// 9;
vector<vector<int>> wires = {{1, 2}, {2, 3}, {3, 4}};// { { 1, 3 }, { 2, 3 }, { 3, 4 }, { 4, 5 }, { 4, 6 }, { 4, 7 }, { 7, 8 }, { 7, 9 } };
int A[101][101];

int bfs(int from, vector<int> visited) {    
    queue<int> q;
    int cnt = 0;

    visited[from] = 1;
    q.push(from);
    
    while (!q.empty()) {
        // 담긴 좌표에 대해 모두 탐색
        int t = q.front();
        q.pop();
        cnt++;
        // t에서 갈 수 있는 노드 모두 queue에 담기
        for (int i = 1; i <= visited.size(); i++) {
            if (A[t][i] == 1 && visited[i] == 0) {
                // 접근 가능하면서, 방문한 적 없어야함
                visited[i] = 1;
                q.push(i);
            }
        }
    }

    return cnt;
}

int main() {
    int answer = 101;
    
    for (int i = 0; i < wires.size(); i++) {
        int ii = wires[i][0];
        int jj = wires[i][1];
        A[ii][jj] = 1;
        A[jj][ii] = 1;
    }

    for (int i = 0; i < wires.size(); i++) {
        int from = wires[i][0];
        int to = wires[i][1];

        // 전선 끊기
        A[from][to] = 0;
        A[to][from] = 0;

        vector<int> visited(n+1);

        // 끊은 후 bfs
        int C1 = bfs(from, visited);
        int C2 = bfs(to, visited);

        // 끊은 전선 원상복구
        A[from][to] = 1;
        A[to][from] = 1;

        answer = (answer < abs(C1 - C2)) ? answer : abs(C1 - C2);
    }

    cout << "답: " << answer << endl;
}