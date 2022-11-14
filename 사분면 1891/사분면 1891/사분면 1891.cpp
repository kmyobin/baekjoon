#include <iostream>
#include <cmath>
#include <string>
typedef long long int ll; // 2의 50승이 크므로
using namespace std;

int d;  int A[50];
ll x; ll y;
ll a; ll b;
string input;

void quadtoxy(ll min_x, ll max_x, ll min_y, ll max_y, int i) {
	// 사분면을 좌표로
	if (i == d) { // 사분면 자릿수 다 돌았으면
		x = min_x; y = min_y; // x, y에 넣음
		return;
	}
	ll xmid = (min_x + max_x) / 2;
	ll ymid = (min_y + max_y) / 2;

	if (A[i] == 1) { // 1사분면
		quadtoxy(xmid, max_x, min_y, ymid, i + 1);
	}
	else if (A[i] == 2) { // 2사분면
		quadtoxy(min_x, xmid, min_y, ymid, i + 1);
	}
	else if (A[i] == 3) { // 3사분면
		quadtoxy(min_x, xmid, ymid, max_y, i + 1);
	}
	else { // 4사분면
		quadtoxy(xmid, max_x, ymid, max_y, i + 1);
	}
}

void xytoquad(ll min_x, ll max_x, ll min_y, ll max_y, int i) {
	// 좌표를 사분면으로
	if (i == d) { // 사분면 다 찼으면
		return;
	}
	ll xmid = (min_x + max_x) / 2;
	ll ymid = (min_y + max_y) / 2;

	if (xmid <= x && x < max_x &&
		min_y <= y && y < ymid) { // 1사분면
		printf("1");
		xytoquad(xmid, max_x, min_y, ymid, i + 1);
	}
	else if (min_x <= x && x < xmid &&
		min_y <= y && y < ymid) { // 2사분면
		printf("2");
		xytoquad(min_x, xmid, min_y, ymid, i + 1);
	}
	else if (min_x <= x && x < xmid &&
		ymid <= y && y < max_y) { // 3사분면
		printf("3");
		xytoquad(min_x, xmid, ymid, max_y, i + 1);
	}
	else { // 4사분면
		printf("4");
		xytoquad(xmid, max_x, ymid, max_y, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> d >> input;
	for (int i = 0; i < d; i++) {
		A[i] = input[i] - '0'; // char to int
	}

	ll n = 1;
	for (int i = 0; i < d; i++) {
		n *= 2; // 생기는 좌표 범위는 0~n-1
	}
	quadtoxy(0, n, 0, n, 0); // 사분면을 좌표로

	cin >> a >> b;
	b = (-b); // b는 위로 가는게(마이너스) 양수 취급을 받으므로 반대로 음수로 만들어야함
	x += a; y += b; 

	if (x >= n || x < 0 || y >= n || y < 0) { // 범위 밖이면
		printf("-1");
	}
	else {
		xytoquad(0, n, 0, n, 0);
	}
}