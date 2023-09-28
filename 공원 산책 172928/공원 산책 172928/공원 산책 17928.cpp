#include <string>
#include <vector>
#include <iostream>
using namespace std;
char A[51][51];
int Row, Column;

bool safe(int r, int c) {
    return 0 <= r && r < Row && 0 <= c && c < Column;
}

bool no_x(int r, int c, char dir, int n) {
    if (dir == 'N') {
        for (int i = 1; i <= n; i++) {
            if (A[r - i][c] == 'X') return true; // 장애물
        }
    }
    else if (dir == 'S') {
        for (int i = 1; i <= n; i++) {
            if (A[r + i][c] == 'X') return true;
        }
    }
    else if (dir == 'W') {
        for (int i = 1; i <= n; i++) {
            if (A[r][c - i] == 'X') return true;
        }
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (A[r][c + i] == 'X') return true;
        }
    }
    return false;
}

pair<int, int> next_index(pair<int, int> coor, char dir, int n) {
    int r = coor.first; int c = coor.second;
    if (dir == 'E') {
        c += n;
    }
    else if (dir == 'N') {
        r -= n;
    }
    else if (dir == 'S') {
        r += n;
    }
    else {
        c -= n;
    }

    return make_pair(r, c);
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    int start_r = 0; int start_c = 0;
    Column = park[0].length();
    Row = park.size();
    for (int i = 0; i < park.size(); i++) {
        for (int j = 0; j < park[i].length(); j++) {
            A[i][j] = park[i][j];
            if (park[i][j] == 'S') {
                start_r = i; start_c = j;
            }
        }
    }

    int r = start_r, c = start_c;
    for (int i = 0; i < routes.size(); i++) {
        string input = routes[i];
        char dir = input[0];
        int n = input[2] - '0';
        pair<int, int> next_coor = next_index(make_pair(r, c), dir, n);
        if (safe(next_coor.first, next_coor.second) &&
            !no_x(r, c, dir, n)) {
            // 공원을 벗어나지 않고, 장애물을 만나지 않는다면
            r = next_coor.first, c = next_coor.second;
        }

    }


    answer.push_back(r);
    answer.push_back(c);
    return answer;
}

int main() {
    vector<string> park = { "SOO","OOO","OOO" };
    vector<string> routes = { "E 2","S 2","W 1" };
    vector<int> result = solution(park, routes);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i!=result.size()-1) cout << ", ";
        
    }
    cout << "]";
}