#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T, N;

int dp[101][101];
int R;

int f(int n, int k) {

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 0; i <= k; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
		}
	}

	return dp[n][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	f(100, 100); // 미리 조합 구해놓고 dp 배열에 할당하기

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		// 초기화
		R = 1;
		unordered_map <string, int> mymap; 

		for (int j = 0; j < N; j++)
		{
			string wear, kind;
			cin >> wear >> kind;		
			// wear는 중복되지 않으므로 사실상 필요없음. 옷의 종류가 중요함
			// 1종류 이상은 무조건 착용해야 함
			// 
			// ex : M 종류의 옷이 3개일 때
			// m1선택,  m2선텍, m3선택, 아무것도 선택 x 
			// 총 (M + 1)가지의 경우의 수 존재

			mymap[kind]++; // 해당 종류의 옷 개수 증가
		}
		for (auto const& pair : mymap) {
			R *= dp[pair.second + 1][1]; // M+1C1 형태
		}
		printf("%d\n", R - 1); // 아무것도 입지 않은 경우를 빼줌
	}


}