#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int A[100001];

bool check(int n) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == -1) return false;
    }
    return true;
}

int find_idx(int n) {
    for (int i = 1; i <= n; i++) {
        if (A[i] == -1) return i;
    }
}

int solution(int n, int m, vector<int> section) {
    int answer = 0;

    for (auto num : section) {
        A[num] = -1; // 덧칠해야 하는 곳은 -1로 설정
    }

    int idx = section[0];
    while (1) {
        if (check(n)) break;

        idx = find_idx(n);

        for (int i = 0; i < m; i++) {
            if (idx + i <= n) A[idx + i]++;
        }

        answer++;
    }

    return answer;
}

int main() {
    int n = 8; int m = 4;
    vector<int> section = { 2,3,6 };

    int result = solution(n, m, section);

    cout << result;
}