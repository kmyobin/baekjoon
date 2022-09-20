#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N;
int A[21][21];
int minimum = 2147483647;
bool checked[21];

void f(int count, int present) {	// count : N/2가 되면 종료시킬 것, pressent : 
	if (count == N / 2) { // start팀과 link팀이 완성됐다면
		int sum1 = 0; int sum2 = 0; // sum1 : start 팀의 능력치, sum2 : link 팀의 능력치
		for (int i = 1; i <= N; i++) { // 능력치 계산
			for (int j = i+1; j <= N; j++) {
				if (checked[i] && checked[j]) sum1 += A[i][j] + A[j][i]; // start팀
				else if ((!checked[i]) && (!checked[j])) sum2 += A[i][j] + A[j][i]; // link팀
			}
		}		
		minimum = min(minimum, abs(sum1 - sum2)); // 최솟값 계산
		return;
	}

	for (int i = present; i < N; i++) {
		checked[i] = true; // backtracking
		f(count + 1, i + 1);
		checked[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	f(0, 1);
	printf("%d", minimum);
}