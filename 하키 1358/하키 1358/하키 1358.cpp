#include <iostream>
#include <cmath>
using namespace std;

double W, H, X, Y, P;
int cnt;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> W >> H >> X >> Y >> P;

	for (int i = 0; i < P; i++)
	{
		double x, y;
		cin >> x >> y;

		// 1. 왼쪽 반원
		if (sqrt(pow(X - x, 2) + pow(Y + H / 2 - y, 2)) <= H / 2) {
			cnt++;
		}
		// 2. 가운데 직사각형
		else if ((X <= x && x <= X + W) && (Y <= y && y <= Y + H)) {
			cnt++;
		}
		// 3. 오른쪽 반원
		else if (sqrt(pow(X + W - x, 2) + pow(Y + H / 2 - y, 2)) <= H / 2) {
			cnt++;
		}
	}
	printf("%d", cnt);
}