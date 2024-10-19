#include <iostream>
using namespace std;

int T, C;
int A[4] = { 25, 10, 5, 1 };
int cnt[4];

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> C;

		for (int j = 0; j < 4; j++) {
			while (1) {
				if (A[j] > C)break;
				C -= A[j];
				cnt[j]++;
			}
		}
		cout << cnt[0] << " " << cnt[1] << " " << cnt[2] << " " << cnt[3] << endl;

		fill(cnt, cnt + 4, 0);
	}
}