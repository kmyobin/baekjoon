#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, vector<pair<int, int>>> m;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first; // 고유 번호 낮은 순
    }
    return a.second > b.second;
}

bool cmp2(pair<string, vector<pair<int, int>>> a, pair<string, vector<pair<int, int>>> b) {
    // 장르별 재생횟수
    int sum_a = 0; int sum_b = 0;
    for (int i = 0; i < a.second.size(); i++) {
        sum_a += a.second[i].second;
    }
    for (int i = 0; i < b.second.size(); i++) {
        sum_b += b.second[i].second;
    }

    return sum_a > sum_b;
}

// m["classic"] = (0, 500), (2, 150), (3, 800)
// 1. 속한 노래가 많이 재생된 장르
// 2. 장르 내에서 많이 재생된 노래 수록
// 3. 재생횟수 같으면 고유번호 낮은 노래 수록

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]].push_back(make_pair(i, plays[i]));
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), cmp); // vector 내부 내림차순 정렬
    }

    vector<pair<string, vector<pair<int, int>>>> v(m.begin(), m.end()); // vector로 변환

    sort(v.begin(), v.end(), cmp2); // 합 기준 정렬

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second.size(); j++) {
            if (j < 2) answer.push_back(v[i].second[j].first); // 최대 2개
        }
    }



    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    vector<int> answer = solution(genres, plays);
    for (auto x : answer) {
        cout << x <<  " ";
    }
}