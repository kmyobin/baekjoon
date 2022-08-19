#include <iostream>
using namespace std;

int T, A, B;
int R;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> B;
		int big, small;
		if (A > B) { big = A; small = B; }
		else { big = B; small = A; }
		while (1) {
			R = big % small;
			if (R == 0) {
				R = small;
				break;
			}
			big = small; small = R;
		}
		printf("%d\n", R * (A / R) * (B / R));
	}
}