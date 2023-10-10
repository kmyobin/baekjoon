#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

int N, L;
int A[101][101];
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	// 행 탐색
	for (int i = 1; i <= N; i++) {
		int before = A[i][1];
		bool G[101] = { false }; // 경사로		
		bool isError = false;
		for(int j=2; j<=N; j++){
			if (!G[j]) {
				if (A[i][j] != before) {
					if (A[i][j] > before && A[i][j] - before == 1) {
						// before : 2, A[i][j] : 3
						// 경사가 높아진다면
						// 경사로 깔아야지
						// 이전 블록에 경사를 깔아야지
						for (int k = 1; k <= L; k++) {
							if (j - k < 1 || A[i][j - k] != before || G[j - k]) {
								// 범위 내에 없거나, 평평하지 않거나, 이미 경사로가 있다면
								isError = true; break;
							}
						}

						if (isError)break;
						else {
							// error 없이 모든 for문을 통과했다면
							for (int k = 1; k <= L; k++) {
								G[j - k] = true; // 경사로 있는 걸로 갱신
							}
						}
					}
					else if (A[i][j] < before && before - A[i][j] == 1) {
						// before : 3, A[i][j] : 2		
						// 경사가 낮아진다면
						// 경사로 깔아야지
						// 지금 i, j부터 경사로 깔아야지
						for (int k = 0; k < L; k++) {
							if (j + k > N || A[i][j + k] != A[i][j] || G[j + k]) {
								isError = true; break;
							}
						}
						if (isError)break;
						else {
							// error 없이 모든 for문을 통과했다면
							for (int k = 0; k < L; k++) {
								G[j + k] = true; // 여기 경사로 있다 
							}
						}
					}
					else {
						// 경사로 1칸 차이 초과
						isError = true;
						break;
					}
				}
				else {
					// 경사가 똑같다면
					// 냅둬
				}

				if (isError)break;
				before = A[i][j];
			}
			
		}
		if (!isError) {
			answer++;
		}
	}

	for (int j = 1; j <= N; j++) {
		int before = A[1][j];
		bool G[101] = { false }; // 경사로		
		bool isError = false;
		for (int i = 2; i <= N; i++) {
			if (!G[i]) {
				if (A[i][j] != before) {
					if (A[i][j] > before && A[i][j] - before == 1) {
						// before : 2, A[i][j] : 3
						// 경사가 높아진다면
						// 경사로 깔아야지
						// 이전 블록에 경사를 깔아야지
						for (int k = 1; k <= L; k++) {
							if (i - k < 1 || A[i - k][j] != before || G[i - k]) {
								isError = true; break;
							}
						}

						if (isError)break;
						else {
							// error 없이 모든 for문을 통과했다면
							for (int k = 1; k <= L; k++) {
								G[i - k] = true; // 여기 경사로 있다
							}
						}
					}
					else if (A[i][j] < before && before - A[i][j] == 1) {
						// before : 3, A[i][j] : 2		
						// 경사가 낮아진다면
						// 경사로 깔아야지
						// 지금 i, j부터 경사로 깔아야지
						for (int k = 0; k < L; k++) {
							if (i + k > N || A[i + k][j] != A[i][j] || G[i + k]) {
								isError = true; break;
							}
						}
						if (isError)break;
						else {
							// error 없이 모든 for문을 통과했다면
							for (int k = 0; k < L; k++) {
								G[i + k] = true; // 여기 경사로 있다 
							}
						}
					}
					else {
						isError = true;
						break;
					}
				}
				else {
					// 경사가 똑같다면
					// 냅둬
				}

				if (isError)break;
				before = A[i][j];
			}

		}
		if (!isError) {
			answer++;
		}
	}


	cout << answer;
}