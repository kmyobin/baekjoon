#include <iostream>
#include <algorithm>
using namespace std;

int N;
string A[20000];

bool cmp(string a, string b) {
	if (a.length() == b.length()) { // 길이가 같으면
		return a < b; // 사전순으로 정렬
	}
	return a.length() < b.length(); // 길이순으로 정렬
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		bool isit = false;
		string input;
		cin >> input;
		for (int j = 0; j < k; j++) {
			if (input == A[j]) {
				isit = true;
				break;
			}
		}
		if (isit == true) {} // 이미 입력되어있으면 pass
		else { // 새로 입력됨이 확인되면 A에 넣음
			A[k] = input; k++;
		}
	}
	
	sort(A, A + k, cmp);

	for (int i = 0; i < k; i++) {
		printf("%s\n", A[i].c_str());
	}

}