#include <iostream>
using namespace std;

int n;

void star(int i, int j, int n) {
	if ((i/n) % 3 == 1 && (j/n) % 3 == 1)printf(" "); // 가운데가 비어져있음
	else if (n/3==0) printf("*"); // n이 1이고 if문에 해당 안되면 *
	else {
		star(i, j, n / 3);
	}
}

int main() {
	// for문을 1부터 돌리려고 했으나 조건이 너무 달라지기 때문에 0으로 바꿈
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		printf("\n");
	}
}