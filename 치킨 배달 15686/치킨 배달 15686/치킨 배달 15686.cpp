#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INT 2147483647
using namespace std;

int N, M;

struct Point {
	int x; int y;
};

struct C {
	int x; int y; bool isvisited = false;
};

vector<Point> house;
vector<C> chicken;
int min_sum = MAX_INT; // 도시의 치킨 거리

/*
조합 문제
최대 M개 고른다 -> 조합

조합으로 M개의 치킨집을 뽑는다
각 집에서 M개의 치킨집까지의 거리 중 최솟값들을 구하여 더한다
가장 최소거리 합이 나오는 조합의 거리 값을 구한다
*/

void distance() {	
	// 각 집에 대한 치킨집의 최소거리 구함
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int minimum = MAX_INT;
		for (int j = 0; j < chicken.size(); j++) {
			if (chicken[j].isvisited == true) {
				// 선택된 치킨집이라면 거리를 구함
				int dist= abs(chicken[j].x - house[i].x) + abs(chicken[j].y - house[i].y);
				minimum = (dist < minimum) ? dist : minimum;				
			}
		}
		sum += minimum; // 해당 집에서 제일 최소 거리인 치킨집 더함
	}

	min_sum = (sum < min_sum) ? sum : min_sum;
}

void selectChicken(int index, int count) {
	if (count == M) {
		distance(); // 조합이 모두 뽑혔으면 거리를 구함
	}
	else {
		// 아직 덜 뽑혔다면
		for (int i = index; i < chicken.size(); i++) {
			if (chicken[i].isvisited == false) {
				chicken[i].isvisited = true; // 선택된 기준은 true로
				selectChicken(i + 1, count + 1); // 다음 index부터 접근하여 조합을 계속해서 구함
				chicken[i].isvisited = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			// 좌표값 저장
			if (input == 1) {
				// 집이면
				house.push_back({ i,j });
			}
			else if (input == 2) {
				// 치킨집이면
				chicken.push_back({ i,j,false });
			}
		}
	}

	selectChicken(0, 0); // 치킨집 고른다

	cout << min_sum;	
}