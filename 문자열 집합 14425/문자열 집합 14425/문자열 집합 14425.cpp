#include <iostream>
#include <set>
using namespace std;

set<string> myset;
int N, M;
int cnt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		myset.insert(input);
	}
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		auto pos = myset.find(input);
		if (pos == myset.end()) {
			
		}
		else { cnt++; }
	}

	printf("%d", cnt);
}