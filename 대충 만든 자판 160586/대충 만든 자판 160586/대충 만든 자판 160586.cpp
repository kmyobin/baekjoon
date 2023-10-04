#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

map<char, int> m[100];

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    int n = keymap.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < keymap[i].length(); j++) {
            char temp = keymap[i][j];
            if (m[i].find(temp) == m[i].end()) m[i][temp] = j + 1; // 아직 없으면 값 넣기
        }
    }

    for (int i = 0; i < targets.size(); i++) {
        int sum = 0;
        for (auto k : targets[i]) {
            int min_k = 100;
            // targets[i]의 char 별로 
            for (int i = 0; i < n; i++) {
                // 각 keymap map에 대해서 돌려보기                
                if (m[i].find(k) != m[i].end()) {
                    // keymap에 있다면
                    min_k = (min_k < m[i][k]) ? min_k : m[i][k];
                }
            }
            if (min_k != 100) {
                sum += min_k;
            }
            else {
                // 하나라도 못찾으면 실패
                sum = -1;
                break;
            }
        }

        answer.push_back(sum);
    }

    return answer;
}

int main() {
    vector<string> keymap = { "ABACD", "BCEFD" };
    vector<string> targets{ "ABCD", "AABB" };
    vector<int> result = solution(keymap, targets);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)cout << ", ";
    }
    cout << "]";
}