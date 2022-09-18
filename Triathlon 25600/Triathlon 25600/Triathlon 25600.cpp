#include <iostream>
using namespace std;

int N;
int a, d, g;
int maximum = -1;
int score;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> d >> g;
		score = a * (d + g);
		if (a == (d + g)) {
			score *= 2;
		}
		if (score > maximum)maximum = score;
	}
	printf("%d", maximum);
}