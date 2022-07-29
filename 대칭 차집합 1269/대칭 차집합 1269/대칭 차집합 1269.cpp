#include <iostream>
#include <set>
using namespace std;

int N, M;
int cnt;
set<int> myset1;
set<int> myset2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		myset1.insert(input);
	}

	for (int i = 0; i < M; i++) {
		int input;
		cin >> input;
		myset2.insert(input);
	}

	set<int> ::iterator iter;
	for (iter = myset1.begin(); iter != myset1.end(); iter++)
	{
		if (myset2.find(*iter) != myset2.end()) { // 중복된 숫자가 있다면

		}
		else {
			cnt++;
		}
	}
	for (iter = myset2.begin(); iter != myset2.end(); iter++)
	{
		if (myset1.find(*iter) != myset1.end()) { // 중복된 숫자가 있다면

		}
		else {
			cnt++;
		}
	}
	printf("%d", cnt);
}