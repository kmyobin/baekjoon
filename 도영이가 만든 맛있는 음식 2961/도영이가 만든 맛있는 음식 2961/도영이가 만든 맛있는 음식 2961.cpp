#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct food {
	int s; // ½Å ¸À
	int b; // ¾´ ¸À
};

int N;
struct food F[10];
bool visited[10];
int minimum = 1000000000;

void f(int S, int B, int ps, int pb, bool start) {
	S *= ps;
	B += pb;	
	if (abs(S - B) < minimum && (!start)) {
		//printf("S : %d, B : %d\n", S, B);
		minimum = abs(S - B);
	}

	bool fin = true;
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			fin = false;
			break;
		}
	}

	if (fin == true) { return; }
	else {
		for (int i = 0; i < N; i++) { // ¹è¿­ Å©±â¸¸Å­
			if (!visited[i]) {
				visited[i] = true;
				f(S, B, F[i].s, F[i].b, false);
				visited[i] = false;

			}
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> F[i].s >> F[i].b;
	}

	f(1, 0, 1, 0, true);

	printf("%d", minimum);
}