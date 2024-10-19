#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int N, B;

int main() {
	cin >> N >> B;

	int len = 0;
	while (1) {
		if (pow(B, len) > N) break;
		len++;
	}

	string answer;

	for (int i = len - 1; i >= 0; i--) {
		for (int j = B; j >= 0; j--) {
			if (j * pow(B, i) <= N) {
				N -= j * pow(B, i);
				if (10 <= j && j <= 35) { // A ~ Z 사이인 경우
					answer += char(j + 55);

				}
				else {
					answer += char(j + '0');
				}
				break;
			}		
		}
	}
	cout << answer;
}