#include <iostream>
using namespace std;

int T;
int a, b;

int one(int A) { 
	while (1) {
		if (A % 10 < 10) {
			return A % 10; // 0 ~ 9
		}
		A /= 10;
	}
}

int two(int A, int B) {
	int x = 0;

	if (A == 0) { return 10; }
	else if (A == 2) {
		x = B % 4;
		if (x == 0) {return 6;}
		else if (x == 1) {return 2;}
		else if (x == 2) {return 4;}
		else {return 8;}
	}
	else if (A == 3) {
		x = B % 4;
		if (x == 0) {return 1;}
		else if (x == 1) {return 3;}
		else if (x == 2) {return 9;}
		else {return 7;}
	}
	else if (A == 4) {
		x = B % 2;
		if (x == 0) {return 6;}
		else if (x == 1) {return 4;}
	}
	else if (A == 7) {
		x = B % 4;
		if (x == 0) {return 1;}
		else if (x == 1) {return 7;}
		else if (x == 2) {return 9;}
		else {return 3;}
	}
	else if (A == 8) {
		x = B % 4;
		if (x == 0) { return 6; }
		else if (x == 1) { return 8; }
		else if (x == 2) { return 4; }
		else return 2;
	}
	else if (A == 9) {
		x = B % 2;
		if (x == 0) { return 1; }
		else return 9;
	}
	else {
		return A;
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> a >> b;
		int x = one(a);
		printf("%d\n", two(x, b));
	}


}