#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <locale>
using namespace std;

int D[1001][1001];
int ins, del, rep;

int EditDistance(string source, string target) {
	int s_len = source.length();
	int t_len = target.length();

	// 초기화
	for (int i = 1; i <= t_len; i++) {
		D[i][0] = D[i - 1][0] + ins;
	}
	for (int j = 1; j <= s_len; j++) {
		D[0][j] = D[0][j - 1] + del;
	}

	for (int i = 1; i <= t_len; i++) {
		for (int j = 1; j <= s_len; j++) {
			if (source[j - 1] == target[i - 1]) { // 문자가 같으면
				D[i][j] = D[i - 1][j - 1]; // 더이상 연산 불필요하므로 그대로 넣음
			}
			else { // 문자가 다르면 최솟값 넣음
				D[i][j] = min(min(D[i - 1][j] + ins, D[i][j - 1] + del), D[i - 1][j - 1] + rep);
			}
		}
	}

	return D[t_len][s_len]; // 맨 마지막 배열이 최소편집거리
}

int main() {

	string source, target;
	cin >> source >> target;
	ins = 1; del = 1; rep = 1;
	cout << EditDistance(source, target);
	return 0;

}