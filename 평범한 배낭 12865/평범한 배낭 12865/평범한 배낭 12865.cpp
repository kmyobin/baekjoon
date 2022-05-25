#include <iostream>
#include <cmath>
using namespace std;

int P[101][100001];
int Weight; // 배낭 무게

int knapsack(int n, int W[], int V[]) { // 보석의 개수, 무게 배열, 가치 배열
	int maximum = -1; // 가방에 담은 보석의 최대 가치를 나타냄
	for (int i = 1; i <= n; i++) { // 보석의 개수만큼 반복
		for (int w = 1; w <= Weight; w++) { // 배낭 무게만큼 반복
			if (W[i] <= w) { // 허용 무게를 넘지 않을 때
				P[i][w] = max(P[i - 1][w], V[i] + P[i - 1][w - W[i]]);
				// i번째 보석을 넣지 않았을 때와 넣었을 때를 비교하여 최댓값을 넣음
			}
			else { // 허용 무게를 초과하므로 보석을 넣지 않음
				P[i][w] = P[i - 1][w]; // i번째 보석을 넣지 않음
			}
			// p[i][w] = 처음부터 i번째의 물건을 탐색하고 배낭의 용량이 w일 때 배낭에 들어간 물건의 최대 가치
		}
	}

	return P[n][Weight];
	// 최댓값은 당연히 처음부터 끝까지 물건을 탐색하고 배낭의 용량이 Weight일 때의 P값
}
int main() {
	int W[101]; int V[101];
	int n;
	cin >> n >> Weight;
	for (int i = 1; i <= n; i++) {
		cin >> W[i] >> V[i];
	}

	cout << knapsack(n, W, V);
}