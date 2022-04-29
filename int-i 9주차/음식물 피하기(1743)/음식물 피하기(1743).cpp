#include <iostream>
#include <queue>
using namespace std;

int n, m, k; // 입력
int A[100][100]; int maximum = -1; // 입력 크기가 100만큼이므로 여유분으로 101까지, maximum 초기 설정은 제일 작게
int dc[4] = { 1,0,-1,0 }, dr[4] = { 0,1,0,-1 }; // 대각선으로 이동할 수 없음, 행/열
// 아래 / 오른쪽 / 위 / 왼쪽
// 컴퓨터에서의 배열
// ----------------------> 열
// |
// |
// |
// |
// |
// |
// | 행
int sum, before; // sum : 음식물 크기, before : 탐색 전 / 후를 나눠줌

struct VERTEX { int a, b; }; // x축, y축

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		A[x-1][y-1] = 1; // 배열이 0부터 시작하므로 1씩 줄여서 넣음
	}
}

void output() { // 출력
	cout << maximum;
}

bool safe(int a, int b) { // 배열의 크기를 넘어가는 지 check
	return (0 <= a && a < 100) && (0 <= b && b < 100);
}

void bfs(int a, int b, int c) { // 너비 우선 탐색
	queue<VERTEX> Q; // x 좌표, y 좌표를 담는 queue 생성 (LIFO)
	Q.push({ a,b });
	A[a][b] = c; // 이미 지나갔던 곳과 구분하기 위해서 c로 설정
	while (!Q.empty()) { // 비어있기 전까지 반복
		VERTEX cur = Q.front(); // front를 cur에 받아옴
		Q.pop(); // 그리고 그것을 뽑아냄
		for (int i = 0; i < 4; i++) // 아래 , 오른쪽 , 위쪽 , 왼쪽 순서대로 탐색함
		{
			if (safe(cur.a + dc[i], cur.b + dr[i]) && // 탐색할 좌표가 배열 크기 내에 있고
				A[cur.a + dc[i]][cur.b + dr[i]] == before) { // 아직 탐색 전이고, 거기에 음식물 쓰레기가 있다면
				sum++; // 음식물 크기 1 증가
				A[cur.a + dc[i]][cur.b + dr[i]] = c; // 탐색했다는 것을 알리기 위해 값을 c로 바꿔줌
				Q.push({ cur.a + dc[i], cur.b + dr[i] }); // 
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			before = A[i][j];
			if (A[i][j] == 1) { // 음식물 쓰레기가 있다면
				sum = 1; // 최소 크기 1
				bfs(i, j, before + 1); // 탐색했던 좌표를 기억하기 위해 before+1
				// bfs 끝나면
				if (sum > maximum) { // 최대 음식물 크기를 구해야 하므로
					maximum = sum; }
			}
		}
	}
}

int main() {
	input();
	solve();
	output();
}