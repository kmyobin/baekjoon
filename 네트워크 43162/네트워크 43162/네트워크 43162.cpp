#include <string>
#include <vector>
#include <iostream>
using namespace std;

int visited[201];

void dfs(vector<vector<int>> c, int node) {    
    visited[node] = 1;
    
    for (int i = 0; i < c.size(); i++) {
        if (c[node][i] == 1 && visited[i] == 0 && node!=i) {
            // ����Ǿ��ְ�, �湮�� �� ������
            dfs(c, i); // �̾ �湮
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            dfs(computers, i);
            answer++; // �� ���� �ϳ��� ��Ʈ��ũ �ϼ�
        }
    }

    return answer;
}

int main() {
    int n = 5;
    vector<vector<int>> computers = { {1, 1, 1, 0, 0},
{1, 1, 0, 0, 0},
{1, 0, 1, 0, 0},
{0, 0, 0, 1, 1},
{0, 0, 0, 1, 1} }; 
    
    /* { { 1, 1, 0, 0 },
{1, 1, 0, 0},
{0, 0, 1, 1},
{0, 0, 1, 1} };
    { {1, 1, 0},{1, 1, 1},{0, 1, 1} };
   */
    ////// { { 1, 1, 0 }, { 1, 1, 0 }, { 0, 0, 1 } }; ;
    int answer = solution(n, computers);

    cout << answer;

    return 0;
}