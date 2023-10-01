#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<int> q; // FIFO
    for (int i = 0; i < progresses.size(); i++) {
        int progress = progresses[i];
        int left_progress = 100 - progress;
        int day_progress = left_progress / speeds[i];
        if (left_progress % speeds[i] != 0) day_progress++;
        q.push(day_progress);
    }

    // 5 10 1 1 20 1
    // 5일차 : 5, 1개
    // 10일차 : 10, 1, 1, 3개
    // 20일차 : 20, 1, 2개
    // 먼저 개발되었어도 앞에 있는 기능 배포되어야 함 

    int day = 1;
    while (!q.empty()) {
        if (day >= q.front()) {
            int feat = 1;
            q.pop();
            while (!q.empty()) {
                int next_ = q.front();
                if (next_ <= day) {
                    feat++;
                    //cout<<next_<<" 저장"<<endl;
                    q.pop();
                }
                else break;
            }
            answer.push_back(feat);
        }
        day++;
    }

    return answer;
}

int main() {
    vector<int> progresses = { 93, 30, 55 };
    vector<int> speeds = { 1,30,5 };
    vector<int> answer = solution(progresses, speeds);
    cout << "[";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
        if (i != answer.size()-1)cout << ", ";
    }
    cout << "]";
}