#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> co_r;
vector<int> co_c;

/*
0, 1 / 1, 2 / 2, 3
1, 5 / 2, 6 / 2, 7 / 3, 3 / 3, 4 / 4, 4
*/
vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    for (int i = 0; i < wallpaper.size(); i++) {
        for (int j = 0; j < wallpaper[i].size(); j++) {
            if (wallpaper[i][j] == '#') {
                co_r.push_back(i);
                co_c.push_back(j);
            }
        }
    }
    sort(co_r.begin(), co_r.end());
    sort(co_c.begin(), co_c.end());

    answer.push_back(co_r[0]);
    answer.push_back(co_c[0]);

    answer.push_back(co_r[co_r.size() - 1] + 1);
    answer.push_back(co_c[co_c.size() - 1] + 1);

    return answer;
}

int main() {
    vector<string> wallpaper = { ".#...", "..#..", "...#." };
    vector<int> result = solution(wallpaper);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)cout << ", ";
    }
    cout << "]";
}