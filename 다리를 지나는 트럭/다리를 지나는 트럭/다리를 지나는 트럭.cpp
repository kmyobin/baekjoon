#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;

int bridge_length = 100;
int weight = 100;
vector<int> truck_weights = { 10 };// { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

int main() {
    int answer = 0;
    queue<int> q;

    for (int i = 0; i < bridge_length; i++) {
        q.push(0); // �ǳʴ� �ð���ŭ 0�� ä������ (q�� �ǳʴ� �ð���ŭ�� ũ�⸦ ����)
    }
    int sum = 0; // �ٸ��� �ִ� Ʈ�� ������ ����
    int i = 0; 
    while (!q.empty()) {
        // 1. �ð��� ������ ���� Ʈ�� ������
        // 1-1. Ʈ�� ���Կ����� ������
        sum -= q.front(); 
        // 1-2. queue������ ������
        q.pop();

        if (i < truck_weights.size()) {
            // 2. �ٸ��� Ʈ���� �ƴ´�
            sum += truck_weights[i];
            if (sum <= weight) {
                // 2-1. Ʈ���� ������ �ٸ� ���緮�� �ߵ� �� ������ queue���ٰ� Ʈ�� �ƴ´�
                q.push(truck_weights[i]);
                i++;
            }
            else {
                // 2-2. Ʈ���� ������ �ٸ� ���緮�� �ߵ� �� ������ queue���ٰ� Ʈ�� ����
                sum -= truck_weights[i];
                q.push(0);
            }
        }
        answer++;
    }

    cout << answer;
}