#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
    int work_num; // 작업 번호
    int work_req; // 작업 요청 시각
    int work_time; // 작업 소요 시간
    bool operator<(const Job jj) const {
        if (work_time != jj.work_time) return work_time > jj.work_time; // 작업소요시간 작은게 우선순위1
        if (work_req != jj.work_req) return work_req > jj.work_req; // 작업요청시각 작은게 우선순위2
        return work_num > jj.work_num; // 작업번호 작은게 우선순위3
    }
} ;

vector<vector<int>> jobs = { {0, 3}, {5,20}, {7,4} };

int main() {
    int answer = 0;

    priority_queue<Job> pq;

    int ms = -1; // 시간
    bool working = false;
    int working_time = 0;
    int working_num;
    vector<pair<int, int>> v(1000001);

    Job j;
    int cnt = 0;
    int sum = 0;

    while (1) {
        if (cnt >= jobs.size() && pq.empty() && !working) {
            // jobs도 다 돌았고, pq도 비어있고, 하드디스크도 일하고 있지 않으면
            break;
        }
        ms++;  

        // ms시점에 시작하는건 무조건 대기큐에 넣어야함
        for (int ii = 0; ii < jobs.size(); ii++) {
            if (jobs[ii][0] == ms) {
                j = { ii, jobs[ii][0], jobs[ii][1] };
                //cout << ii << "번 작업 넣음" << endl;
                v[ii].first = ms; // 요청시각
                jobs[ii] = { 0,0 };
                cnt++; // pq 하나 넣음
                pq.push(j);
            }
        }

        // 하드디스크의 작업
        if (working) {
            working_time--;
            //cout << "작업 중" << endl;
            if (working_time == 0) { // 일 다했으면
                working = false;
                v[working_num].second = ms; // 작업 종료 시각
                //cout << "작업 완료(" << v[working_num].second - v[working_num].first << "ms 소요)" << endl;
                sum += v[working_num].second - v[working_num].first;
            }
        }

        // 하드디스크 작업 X, 대기큐가 비어있지 않으면 
        // pq.top()을 하드디스크에서 작업 시킴
        if (!working && !pq.empty()) {
            Job j = pq.top();
            working = true;
            working_time = j.work_time;
            working_num = j.work_num;
            //cout << working_num << "번 작업 시작" << endl;
            pq.pop();
        }

    }

    answer = sum / jobs.size();
    cout << answer;

}