#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n = 4;
vector<vector<int>> costs = {{0, 1, 1}, {0, 2, 2}, {1, 2, 5}, {1, 3, 1}, {2, 3, 8}};

// ���� ���� = ��� ���� - 1
/*
1. ���ĵ� ������ �°� �׷����� ����
2. ���Խ�Ű�� ������ ����Ŭ ���̺� Ȯ��
3. ����Ŭ�� �����ϴ� ��� ���� ���� x
*/
int A[101][101];
int P[101];


// �θ� ��� ã�� �Լ�
int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a < b) parent[b] = a;
    else parent[a] = b;
}

// ���� �θ� �������� Ȯ��
int findParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);
    if (a == b)return 1;
    return 0;
}

bool cmp(vector<int> a, vector<int> b) { // 2��° �ε��� �������� �������� ����
    if (a[2] == b[2]) {
        // ����ġ�� �Ȱ����� 
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }
    return a[2] < b[2];
}

int main() {    
    // ���� ��� �������� �������� ����
    sort(costs.begin(), costs.end(), cmp);

    // �� ������ ���Ե� �׷����� ������� ����
    for (int i = 0; i <= n; i++) {
        P[i] = i;
    }

    int sum = 0;
    for (int i = 0; i < costs.size(); i++) {
        // ����Ŭ�� �߻����� �ʴ� ��� �׷����� ����
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