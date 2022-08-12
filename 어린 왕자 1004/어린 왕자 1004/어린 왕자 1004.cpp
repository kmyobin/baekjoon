#include <iostream>
#include <cmath>
using namespace std;

int T, n;
double x_1, y_1, x_2, y_2;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int cnt = 0;
		cin >> x_1 >> y_1 >> x_2 >> y_2;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int cx, cy, r;
			cin >> cx >> cy >> r;

			// 같은 행성계에 존재한다면
			if (sqrt(pow(x_1 - cx, 2) + pow(y_1 - cy, 2)) < r &&
				sqrt(pow(x_2 - cx, 2) + pow(y_2 - cy, 2)) < r) {
				continue;
			}

			// 이탈해야한다면
			if (sqrt(pow(x_1 - cx, 2) + pow(y_1 - cy, 2)) < r) {
				cnt++;
			}
			// 진입해야한다면
			if (sqrt(pow(x_2 - cx, 2) + pow(y_2 - cy, 2)) < r) {
				cnt++;
			}

		}
		printf("%d\n", cnt);
	}
}