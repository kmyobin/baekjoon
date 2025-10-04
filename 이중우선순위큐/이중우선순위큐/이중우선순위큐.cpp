#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

vector<string> operations = { "I 10", "I 20", "D 1", "I 30", "I 40", "D -1", "D -1" };; ;
//   { "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" }; ;;; ;
// //  { "I 1", "I 2", "D 1", "D -1", "I 3", "I 4", "D 1" };; ; 
//  //    { "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" }; ;///
//{ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" }; ;//
//  { "I 1", "D 1", "D -1" };

// multiset : �ߺ��� ����ϴ� set(�⺻������ �������� ����)
int main() {
    vector<int> answer;

    multiset<int> mts;
    for (int i = 0; i < operations.size(); i++) {
        if (operations[i][0] == 'D') {
            if (operations[i][2] == '-') {
                // �ִ� ����
                if(mts.empty())mts.erase(mts.begin());
            }
            else {
                // �ּڰ� ����
                if (mts.empty())mts.erase(--mts.end());
            }
        }
        else {
            string s_tmp = operations[i].substr(2); // �ε��� 2���� ���� ����
            int i_tmp = stoi(s_tmp);
            mts.insert(i_tmp);
        }
    }

    if (!mts.empty()) {
        for (auto iter = mts.begin(); iter != mts.end(); iter++) {
            if (iter == mts.begin()) {
                answer.push_back(*iter);
            }
            auto ii = iter;
            if (++ii == mts.end()) {
                answer.push_back(*iter);
            }

        }
    }
    else {
        answer.push_back(0);
        answer.push_back(0);
    }
    reverse(answer.begin(), answer.end()); // �������� -> �������� ����

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    
}

/*
priority_queue<int> desc_pq; // ��������(�ִ���) �켱����ť
priority_queue<int, vector<int>, greater<int>> asc_pq; // �������� �켱���� ť
map<string, int> m;
int cnt = 0; // ����/���� Ƚ�� ����
for (int i = 0; i < operations.size(); i++) {
    if (operations[i][0] == 'D'){
        if (cnt == 0) {
            desc_pq = priority_queue<int>();
            asc_pq = priority_queue<int, vector<int>, greater<int>>();
            continue;
        } // ť�� ��������� ����
        else {
            cnt--;
            if (operations[i][2] == '-') {
                // �ּڰ� ����
                while (1) {
                    string s_tmp = to_string(asc_pq.top());
                    if (m[s_tmp] <= 0) asc_pq.pop();
                    else break;
                }
                m[to_string(asc_pq.top())]--;
                //cout <<asc_pq.top() << " ����" << endl;
                asc_pq.pop();

            }
            else {
                // �ִ� ����
                // while (1) {
                string s_tmp = to_string(desc_pq.top());
                while (1) {
                    if (m[s_tmp] <= 0) desc_pq.pop();
                    else break;
                }
                m[to_string(desc_pq.top())]--;
                //cout << desc_pq.top() << " ����" << endl;
                desc_pq.pop();
            }
        }
    }
    else {
        string s_tmp = operations[i].substr(2); // �ε��� 2���� ���� ����
        int i_tmp = stoi(s_tmp);
        //cout << i_tmp << " �ֱ�" << endl;
        asc_pq.push(i_tmp);
        desc_pq.push(i_tmp);
        m[s_tmp]++;
        cnt++;
    }
}
if (!asc_pq.empty() && !desc_pq.empty()) {
    answer.push_back(desc_pq.top());
    answer.push_back(asc_pq.top());
}
else {
    answer.push_back(0);
    answer.push_back(0);
}
*/