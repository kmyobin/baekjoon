#include <string>
#include <vector>
#include <iostream>
using namespace std;

int k = 76; // 80;
vector<vector<int>> dungeons = { {72, 29},{44, 28},{72, 4},{59, 22} }; //{ {80,20},{50,40},{30,10} };

int maximum = 0;
void f(int present_piro, int num, vector<vector<int>> d, vector<int> order, vector<int> visited) {

    int min_piro = d[num][0];
    int wasted_piro = d[num][1];

    if (present_piro < min_piro) {
       // 피로도 다 했으면
        maximum = (maximum > order.size()) ? maximum : order.size(); // 최대 던전수 체크   
        return;
    }

    // 방문 여부 체크
    if (visited[num] == 0) {
        // 방문한 적 없으면 피로도 체크
        if (present_piro >= min_piro) {
           // 최소피로도보다 현재 피로도가 크거나 같아야 탐험 가능
           visited[num] = 1; // 방문여부 "여"
           present_piro -= wasted_piro; // 소모피로도 깎기
           order.push_back(num); // 방문한 순서에 넣음
           maximum = (maximum > order.size()) ? maximum : order.size();
           for (int i = 0; i < d.size(); i++) {
                if (num != i && visited[i] == 0) { // 현재 있는 곳이 아니고, 방문한 적 없던 곳이면
                    f(present_piro, i, d, order, visited);
                }
           }
        }
    }
}

int main() {    

    for (int i = 0; i < dungeons.size(); i++) {
        vector<int> order_;
        vector<int> visited(dungeons.size());
        f(k, i, dungeons, order_, visited);
        visited.clear();
    }

    cout << maximum;
}