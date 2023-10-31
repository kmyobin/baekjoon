#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
map<string, int> m;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    for (auto p : participant) m[p]++;
    for (auto c : completion) m[c]++;

    for (auto iter = m.begin(); iter != m.end(); iter++) {
        // 참가자 이름이 2의 배수로 불렸다는 건 완주했다는 뜻
        if (iter->second % 2 == 1) {
            answer = iter->first;
            break;
        }
    }
    return answer;
}

int main() {
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki" };
    cout << solution(participant, completion);
}