#include <iostream>
#include <cmath>
using namespace std;

int N;

int main() {
	cin >> N;
	
	int k = 1;

	for (int i = 1; i <= 2 * N - 1; i++) {
		if (i <= N) {
			for (int j = 1; j <= N + (i - 1); j++) {
				if (i + j <= N) {
					printf(" ");
				}
				else {
					printf("*");
				}
			}
			printf("\n");
		} 
		else {
			for (int j = 1; j <= (2*N-1)-k; j++) {
				if (abs(i - j) >= N) {
					//printf("%d«‡ %dø≠\n", i, j);
					printf(" ");
				}
				else {
					printf("*");
				}
			}
			printf("\n");
			k++;
		}
		
	}
}