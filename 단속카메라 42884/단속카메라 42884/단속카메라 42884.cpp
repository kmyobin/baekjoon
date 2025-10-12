#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> routes = { {-20, -15} };//{ { -20, -15 }, { -14, -5 }, { -18, -13 }, { -5, -3 } }; 


bool cmp(vector<int> a, vector<int> b) {
    if (a[1] == b[1])return a[0] < b[0];
    return a[1] < b[1];
}

int main() {
    int answer = 0;

    sort(routes.begin(), routes.end(),cmp);
    
    int tmp = routes[0][1]; // ���� �������� �Ǵ�
    for (int i = 1; i < routes.size(); i++) {

        if (tmp < routes[i][0]) {
            // tmp���� ���� ���� �Ÿ��� ũ�� ��ġ�� ī�޶� ���ƾ���
            answer++;
            tmp = routes[i][1];
        }
    }

    cout << answer + 1;
}