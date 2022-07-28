#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, M, cnt;
set<string> myset;
string Answer[500000];

bool cmp(string a, string b) { // 사전순 정렬
	return a < b;
}

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

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (myset.find(input) != myset.end()) { // 찾으면
			Answer[cnt] = input;
			cnt++;
		}
		else { // 못찾으면 pass
		}
	}
	sort(Answer, Answer + cnt, cmp); // 사전순 정렬
	printf("%d\n", cnt); // 듣도 && 보도
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\n", Answer[i].c_str());
	}
}