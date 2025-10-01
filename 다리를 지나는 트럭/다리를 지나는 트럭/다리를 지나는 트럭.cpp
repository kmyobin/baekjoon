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
        q.push(0); // 건너는 시간만큼 0을 채워넣음 (q는 건너는 시간만큼의 크기를 유지)
    }
    int sum = 0; // 다리에 있는 트럭 무게의 총합
    int i = 0; 
    while (!q.empty()) {
        // 1. 시간이 지남에 따라 트럭 나가라
        // 1-1. 트럭 무게에서도 빠지고
        sum -= q.front(); 
        // 1-2. queue에서도 나가라
        q.pop();

        if (i < truck_weights.size()) {
            // 2. 다리에 트럭을 싣는다
            sum += truck_weights[i];
            if (sum <= weight) {
                // 2-1. 트럭의 총합이 다리 적재량을 견딜 수 있으면 queue에다가 트럭 싣는다
                q.push(truck_weights[i]);
                i++;
            }
            else {
                // 2-2. 트럭의 총합이 다리 적재량을 견딜 수 없으면 queue에다가 트럭 뺀다
                sum -= truck_weights[i];
                q.push(0);
            }
        }
        answer++;
    }

    cout << answer;
}