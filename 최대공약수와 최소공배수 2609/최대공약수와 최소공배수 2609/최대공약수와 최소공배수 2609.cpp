#include <iostream>
using namespace std;

int A, B;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B;

	int maximum = (A > B) ? B : A;
	int temp = 0;

	for (int i = maximum; i >= 1; i--) {
		if (A % i == 0 && B % i == 0) {
			printf("%d\n", i);
			temp = i;
			break;
		}
	}

	printf("%d", temp * (A / temp) * (B / temp));

}