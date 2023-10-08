#include <iostream>
using namespace std;

int N, M;
int A[501][501];
int sum;

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	/*
	天天天天
	*/
	int sr = 1, sc = 1, er = 1, ec = 4;
	while (1) {
		if (er > N)break;
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			temp += A[sr][sc + i];
		}
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; sc = 1; er++; ec = 4;
		}
	}

	/*
	|
	|
	|
	|
	*/
	sr = 1, sc = 1, er = 4, ec = 1;
	while (1) {
		if (er > N)break;
		int temp = 0;
		for (int i = 0; i < 4; i++) {
			temp += A[sr + i][sc];
		}
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 1;
		}
	}

	/*
	天天
	天天
	*/
	sr = 1; sc = 1; er = 2; ec = 2;
	while (1) {
		if (er > N)break;
		int temp = 0;
		temp = A[sr][sc] + A[sr + 1][sc] + A[er][ec] + A[er - 1][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	|
	|
	天天
	*/
	sr = 1; sc = 1; er = 3; ec = 2;
	while (1) {
		if (er > N)break;
		int temp = 0;
		temp = A[sr][sc] + A[sr + 1][sc] + A[sr + 2][sc] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	     |
	天天天
	*/
	sr = 2; sc = 1; er = 1; ec = 3;
	while (1) {
		if (sr > N)break;
		int temp = 0;
		temp = A[sr][sc] + A[sr][sc + 1] + A[sr][sc + 2] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 3;
		}
	}

	/*
	天天天
	|
	*/
	sr = 2; sc = 1; er = 1; ec = 3;
	while (1) {
		if (sr > N)break;
		int temp = A[sr][sc] + A[sr - 1][sc] + A[er][ec-1] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 3;
		}
	}

	/*
	天天
	   |
	   |
	*/
	sr = 1; sc = 1; er = 3; ec = 2;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr][sc + 1] + A[er][ec] + A[er - 1][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	   |
	   |
	天天
	*/
	sr = 3; sc = 1; er = 1; ec = 2;
	while (1) {
		if (sr > N)break;
		int temp = A[sr][sc] + A[sr][sc + 1] + A[er][ec] + A[er + 1][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	|
	天天天
	*/
	sr = 1; sc = 1; er = 2; ec = 3;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr+1][sc] + A[er][ec] + A[er][ec-1];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 3;
		}
	}

	/*
	天天天
	     |
	*/
	sr = 1; sc = 1; er = 2; ec = 3;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr][sc+1] + A[er][ec] + A[er-1][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 3;
		}
	}

	/*
	天天
	|
	|
	*/
	sr = 3; sc = 1; er = 1; ec = 2;
	while (1) {
		if (sr > N)break;
		int temp = A[sr][sc] + A[sr-1][sc] + A[er][ec] + A[er][ec-1];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	|
	天天
	   |
	*/
	sr = 1; sc = 1; er = 3; ec = 2;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr + 1][sc] + A[er][ec] + A[er-1][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	  天天
	天天
	*/
	sr = 2; sc = 1; er = 1; ec = 3;
	while (1) {
		if (sr > N)break;
		int temp = A[sr][sc] + A[sr][sc+1] + A[er][ec] + A[er][ec-1];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 3;
		}
	}

	/*
	   |
	天天
	|
	*/
	sr = 3; sc = 1; er = 1; ec = 2;
	while (1) {
		if (sr > N)break;
		int temp = A[sr][sc] + A[sr-1][sc] + A[er][ec] + A[er+1][ec ];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	天天
	  天天
	*/
	sr = 1; sc = 1; er = 2; ec = 3;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr][sc+1] + A[er][ec] + A[er][ec-1];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 3;
		}
	}

	/*
	天天天
	  |
	*/
	sr = 1; sc = 1; er = 2; ec = 2;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr][sc + 1] + A[sr][sc+2] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec+1 > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}

	/*
	  |
	天|
	  |
	*/
	sr = 2; sc = 1; er = 3; ec = 2;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr][sc + 1] + A[sr-1][sc + 1] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}
	
	/*
	  |
	天天天
	*/
	sr = 1; sc = 2; er = 2; ec = 3;
	while (1) {
		if (er > N)break;
		int temp = A[sr][sc] + A[sr+1][sc] + A[sr +1][sc - 1] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 2; ec = 3;
		}
	}

	/*
	|
	|天
	|
	*/
	sr = 1; sc = 1; er = 2; ec = 2;
	while (1) {
		if (er + 1 > N)break;
		int temp = A[sr][sc] + A[sr + 1][sc] + A[er + 1][ec - 1] + A[er][ec];
		sum = (sum > temp) ? sum : temp;
		sc++; ec++;
		if (ec > M) {
			sr++; er++; sc = 1; ec = 2;
		}
	}


	cout << sum;
}