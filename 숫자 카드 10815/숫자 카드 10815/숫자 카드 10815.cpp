#include <iostream>
#include <set>
using namespace std;

int N, M;
set<int> myset;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		myset.insert(x);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int x;
		cin >> x;
		auto pos = myset.find(x);
		if (pos == myset.end()) {
			printf("0 ");
		}
		else { printf("1 "); }
	}
}