#include <iostream>
using namespace std;

int A, B, C;
int h, m;

int main() {
	cin >> A >> B;
	cin >> C;

	if (B + C >= 60) {
		h = A + (B + C) / 60;
		m = (B + C) % 60;
		if (h >= 24) {
			h -= 24;
		}
		
	}
	else {
		h = A;
		m = B + C;
	}

	printf("%d %d", h, m);
}