#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> A(n + 1, 1); // 1로 초기화
    A[0] = -1;

    for (auto l : lost) {
        A[l]--;
    }

    for (auto r : reserve) {
        A[r]++;
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] == 0) {
            if (A[i - 1] == 2) {
                A[i - 1]--;
                A[i]++;
            }
            else {
                if (A[i + 1] == 2) {
                    A[i + 1]--;
                    A[i]++;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (A[i] >= 1) answer++;
    }

    return answer;
}

int main() {
    int n = 5; vector<int> lost = { 2,4 }; vector<int> reserve = { 1,3,5 };
    int answer = solution(n, lost, reserve);
    cout << answer;
}