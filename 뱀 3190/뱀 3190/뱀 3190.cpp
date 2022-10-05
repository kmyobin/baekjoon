#include <iostream>
#include <deque>
using namespace std;

int N, K, L; // K : 사과 개수
int X[101][101];

int itr = 1;
bool isover;

struct det {
	int x;
	char c;
};

struct det det[100];
deque<pair<int, int>> mydeque;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		X[row][col] = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x; char c;
		cin >> x >> c;
		det[i].x = x + 1; // x초 이후이므로 실질적으로 x+1초에 방향을 틈
		det[i].c = c;
	}

	
	int k = 0; // det 구조체를 가리킴
	char state = 'E'; // 처음에는 오른쪽을 향하므로 E
	int i = 1; int j = 1;
	mydeque.push_back(make_pair(i, j)); // 1,1에서 출발
	

	while (1) {
		// (1) 다음에 어딜 가야할지 (i, j) 설정
		if (itr  == det[k].x) { // 정해진 시간이 지났다면 회전
			if (det[k].c == 'L') {	// 왼쪽으로
				if (state == 'E') { state = 'N'; i--; } // 동쪽이었다면 북쪽으로
				else if (state == 'W') { state = 'S'; i++; } // 서쪽이었다면 남쪽으로
				else if (state == 'N') { state = 'W'; j--; } // 북쪽이었다면 서쪽으로
				else { state = 'E';	j++; } // 남쪽이었다면 동쪽으로
			}
			else { // 오른쪽으로
				if (state == 'E') { state = 'S'; i++; } // 동쪽이었다면 남쪽으로
				else if (state == 'W') { state = 'N'; i--; } // 서쪽이었다면 북쪽으로
				else if (state == 'N') { state = 'E'; j++; } // 북쪽이었다면 동쪽으로
				else { state = 'W'; j--; } // 남쪽이었다면 서쪽으로
			}
			k++; // 그 다음 시간
		}
		else { // 그냥 평소에 이동할 때
			if (state == 'E') { j++; }
			else if (state == 'W') { j--; }
			else if (state == 'N') { i--; }
			else { i++; }
			
		}
		
		// (2) 가려는 좌표가 적합한지
		// 종료 조건
		// 1. 벽에 부딪힘
		if (i > N || j > N || i < 1 || j < 1) { break; }
		// 2. 자기자신의 몸에 부딪힘
		for (int z = 0; z < mydeque.size(); z++) {
			if (mydeque[z].first == i && mydeque[z].second == j) { isover = true;	break; }
		}
		if (isover) break;
		

		// (3) 적합하면 사과가 있는지 / 없는지
		mydeque.push_front(make_pair(i,j)); // 몸길이를 늘려 다음칸에 위치시킴		

		if (X[i][j] == 1) { // 만약 사과가 있는 곳이라면
			X[i][j] = 0; // 사과 먹었으니까 원상태로
			// 몸길이는 증가
		}
		else { // 사과가 없는 곳이라면
			mydeque.pop_back(); // 꼬리쪽 pop
		}

		itr++; // 시간 증가
	}

	cout << itr;
}