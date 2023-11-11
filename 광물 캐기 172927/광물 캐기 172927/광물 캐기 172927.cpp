#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 곡괭이 선택하는 기준 : diamond, iron, stone 순

// minerals : 8개 => 2개 필요
// minerals : 11개 => 3개 필요
// n개 필요할 때 dia, iron, stone 순으로 정렬
// 무조건 5개씩 끊음

// v[0][0] = 0번째 그룹이 다이아몬드로 조져질 때의 피로도
// v[0][1] = 0번째 그룹이 철로 조져질 때의 피로도
// v[0][2] = 0번째 그룹이 돌로 조져질 때의 피로도
// 1<=그룹의 수<=10

bool cmp(vector<int> a, vector<int>b) {
    if (a[2] == b[2]) {
        if (a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];
    }
    return a[2] > b[2];
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int dia = picks[0]; int iron = picks[1]; int stone = picks[2];
    int k = 0;
    int num = picks[0] + picks[1] + picks[2];

    vector<vector<int>> v(minerals.size() / 5 + (minerals.size() % 5 == 0 ? 0 : 1), vector<int>(3, 0));

    for (int i = 0; i < minerals.size(); i += 5) {
        int dia_sum = 0; int iron_sum = 0; int stone_sum = 0;
        for (int j = i; j < i + 5; j++) {
            if (j >= minerals.size() || j >= num * 5) break; // 광물 다 탐색했거나, 허용되는 광물 수를 넘기는 경우
            if (minerals[j] == "diamond") {
                dia_sum += 1; iron_sum += 5; stone_sum += 25;
            }
            else if (minerals[j] == "iron") {
                dia_sum += 1; iron_sum += 1; stone_sum += 5;
            }
            else {
                dia_sum += 1; iron_sum += 1; stone_sum += 1;
            }
        }
        v[k][0] = (dia_sum);
        v[k][1] = (iron_sum);
        v[k][2] = (stone_sum);
        k++;
    }

    sort(v.begin(), v.end(), cmp); // 피로도 높은 순으로 내림차순 정렬

    // 피로도가 높은 것부터 다이아 곡괭이 써야함    
    int i = 0;
    while (1) {
        if (i >= k) break; // 광물 이미 다 캤으면 종료
        if (dia > 0) {
            answer += v[i][0];
            dia--;
        }
        else if (iron > 0) {
            answer += v[i][1];
            iron--;
        }
        else if (stone > 0) {
            answer += v[i][2];
            stone--;
        }
        else break; // 곡괭이 다 썼으면 종료
        i++;
    }

    return answer;
}

int main() {
    vector<int> picks = { 1,3,2 };
    vector<string> minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
    cout << solution(picks, minerals);
}