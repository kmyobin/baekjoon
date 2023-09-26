#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    for (int i = 0; i < name.size(); i++) {
        m[name[i]] = yearning[i]; // m["may"]=5
    }

    for (int i = 0; i < photo.size(); i++) {
        int sum = 0;
        for (int j = 0; j < photo[i].size(); j++) {
            auto iter = m.find(photo[i][j]);
            if (iter != m.end()) {
                // ÀÖ´Ù¸é
                sum += iter->second;
            }
        }
        answer.push_back(sum);
    }

    return answer;
}

int main() {
    vector<string> name = { "may", "kein", "kain", "radi" };
    vector<int> yearning = { 5, 10, 1, 3 };
    vector<vector<string>> photo = {
        {"may", "kein", "kain", "radi"} ,
        {"may", "kein", "brin", "deny"},
        {"kon", "kain", "may", "coni"}
    };
    vector<int> answer = solution(name, yearning, photo);

    for (auto a : answer) {
        cout << a << " ";
    }
}