#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// [A B C D]
// [2 1 3 2] 숫자 클수록 우선순위 높음
// A 꺼냈다가 큐에 넣음.. [B C D A]
// B 꺼냈다가 큐에 넣음.. [C D A B]
// C 꺼냄 [D A B]

queue<pair<int, int>> s;
vector<int> maxis;

int solution(vector<int> priorities, int location) {
    vector<int> order;
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        s.push(make_pair(priorities[i], i));
        maxis.push_back(priorities[i]);
    }

    sort(maxis.begin(), maxis.end(), greater<>()); // 내림차순

    int cnt = 1;
    while (!s.empty()) {
        pair<int, int> tmp = s.front();
        int prior = tmp.first; int n = tmp.second;
        s.pop();

        if (prior < maxis[0]) {
            // 더 높은 우선순위가 있다면?
            s.push(make_pair(prior, n)); // 다시 넣기
        }
        else {
            // 그런 프로세스 없다면 
            maxis.erase(maxis.begin());

            if (location == n) {
                answer = cnt;
                break;
            }
            else cnt++;
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = { 2,1,3,2 };
    int location = 2;
    cout << solution(priorities, location);
}