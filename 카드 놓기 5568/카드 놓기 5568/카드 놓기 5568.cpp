#include <iostream>
#include <string>
using namespace std;

int n, k;
string A[10];
bool visited[10];
int cnt;
string X[5040]; // 최대 만들 수 있는 정수 10*9*8*7=4940개
int x;

bool is_include(string T) { // 만들었던 정수가 이미 있던 것인지
	for (int i = 0; i < x; i++)
	{
		if (X[i] == T) { // 겹치면
			return true;
		}
	}
	return false;
}

void f(int count, string p, string res) {
	if (count > k) { // 다 골랐으면
		if (!is_include(res)) { // 새로 만들어진 정수라면
			cout << res << " 담겼습니다.\n";
			X[x] = res; // 담고
			cnt++; x++; 
		}
		return;
	}
	res += p;
	for (int i = 0; i < n; i++) { // 배열 크기만큼
		if (!visited[i]) {
			visited[i] = true;
			f(count + 1, A[i], res);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	f(0, "", "");
	printf("%d", cnt);
}