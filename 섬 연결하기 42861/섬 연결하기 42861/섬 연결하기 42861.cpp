#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n = 4;
vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

// 간선 숫자 = 노드 개수 - 1
/*
1. 정렬된 순서에 맞게 그래프에 포함
2. 포함시키기 전에는 사이클 테이블 확인
3. 사이클을 형성하는 경우 간선 포함 x
*/
int A[101][101];
int P[101];


// 부모 노드 찾는 함수
int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)return 1;
    return 0;
}

bool cmp(vector<int> a, vector<int> b) { // 2번째 인덱스 기준으로 오름차순 정렬
    if (a[2] == b[2]) {
        // 가중치가 똑같으면 
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    return a[2] < b[2];
}

int main() {    
    // 간선 비용 기준으로 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);

    // 각 정점이 포함된 그래프가 어디인지 저장
    for (int i = 0; i <= n; i++) {
        P[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < costs.size(); i++) {
        // 사이클이 발생하지 않는 경우 그래프에 포함
        if (!findParent(P, costs[i][0], costs[i][1])) {
            sum += costs[i][2];
            unionParent(P, costs[i][0], costs[i][1]);
        }
        //printP(n);
    }

    cout << sum;
}
    /*
    for (int i = 0; i < costs.size(); i++) {
        cout << costs[i][0] << ", " << costs[i][1] << ", " << costs[i][2] << endl;
    }
    */
    /*
    void printP(int n) {
        for (int i = 0; i <= n; i++) {
            cout << P[i] << " ";
        }
        cout << endl;
    }
    */

    /*
    class Edge {
    public :
        int node[2];
        int distance;
        Edge(int a, int b, int distance) {
            this->node[0] = a;
            this->node[1] = b;
            this->distance = distance;
        }

        bool operator < (Edge& edge) {
            return this->distance < edge.distance;
        }
    };*/