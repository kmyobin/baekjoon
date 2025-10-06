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
       // �Ƿε� �� ������
        maximum = (maximum > order.size()) ? maximum : order.size(); // �ִ� ������ üũ   
        return;
    }

    // �湮 ���� üũ
    if (visited[num] == 0) {
        // �湮�� �� ������ �Ƿε� üũ
        if (present_piro >= min_piro) {
           // �ּ��Ƿε����� ���� �Ƿε��� ũ�ų� ���ƾ� Ž�� ����
           visited[num] = 1; // �湮���� "��"
           present_piro -= wasted_piro; // �Ҹ��Ƿε� ���
           order.push_back(num); // �湮�� ������ ����
           maximum = (maximum > order.size()) ? maximum : order.size();
           for (int i = 0; i < d.size(); i++) {
                if (num != i && visited[i] == 0) { // ���� �ִ� ���� �ƴϰ�, �湮�� �� ���� ���̸�
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