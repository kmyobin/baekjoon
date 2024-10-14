#include <iostream>
#include <string>
using namespace std;

char x[5][15];


int main(){
	fill(&x[0][0], &x[0][0] + 5 * 15, '\0');


	for (int i = 0; i < 5; i++) {
		cin >> x[i];
	}
	
	
	for (int j = 0; j < 15; j++) {
		for (int i = 0; i < 5; i++) {
			if (x[i][j] == '\0')continue;
			cout << x[i][j];
		}
	}

}