#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
    int work_num; // �۾� ��ȣ
    int work_req; // �۾� ��û �ð�
    int work_time; // �۾� �ҿ� �ð�
    bool operator<(const Job jj) const {
        if (work_time != jj.work_time) return work_time > jj.work_time; // �۾��ҿ�ð� ������ �켱����1
        if (work_req != jj.work_req) return work_req > jj.work_req; // �۾���û�ð� ������ �켱����2
        return work_num > jj.work_num; // �۾���ȣ ������ �켱����3
    }
} ;

vector<vector<int>> jobs = { {0, 3}, {5,20}, {7,4} };

int main() {
    int answer = 0;

    priority_queue<Job> pq;

    int ms = -1; // �ð�
    bool working = false;
    int working_time = 0;
    int working_num;
    vector<pair<int, int>> v(1000001);

    Job j;
    int cnt = 0;
    int sum = 0;

    while (1) {
        if (cnt >= jobs.size() && pq.empty() && !working) {
            // jobs�� �� ���Ұ�, pq�� ����ְ�, �ϵ��ũ�� ���ϰ� ���� ������
            break;
        }
        ms++;  

        // ms������ �����ϴ°� ������ ���ť�� �־����
        for (int ii = 0; ii < jobs.size(); ii++) {
            if (jobs[ii][0] == ms) {
                j = { ii, jobs[ii][0], jobs[ii][1] };
                //cout << ii << "�� �۾� ����" << endl;
                v[ii].first = ms; // ��û�ð�
                jobs[ii] = { 0,0 };
                cnt++; // pq �ϳ� ����
                pq.push(j);
            }
        }

        // �ϵ��ũ�� �۾�
        if (working) {
            working_time--;
            //cout << "�۾� ��" << endl;
            if (working_time == 0) { // �� ��������
                working = false;
                v[working_num].second = ms; // �۾� ���� �ð�
                //cout << "�۾� �Ϸ�(" << v[working_num].second - v[working_num].first << "ms �ҿ�)" << endl;
                sum += v[working_num].second - v[working_num].first;
            }
        }

        // �ϵ��ũ �۾� X, ���ť�� ������� ������ 
        // pq.top()�� �ϵ��ũ���� �۾� ��Ŵ
        if (!working && !pq.empty()) {
            Job j = pq.top();
            working = true;
            working_time = j.work_time;
            working_num = j.work_num;
            //cout << working_num << "�� �۾� ����" << endl;
            pq.pop();
        }

    }

    answer = sum / jobs.size();
    cout << answer;

}