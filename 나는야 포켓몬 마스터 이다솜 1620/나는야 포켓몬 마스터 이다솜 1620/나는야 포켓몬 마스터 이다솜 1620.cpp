#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;

unordered_map<int, string> myunorderedmap1;
unordered_map<string, int> myunorderedmap2;

bool isNumber(const string& str) {
	for (char const& c : str) {
		if (isdigit(c) == 0)return false;
	}
	return true;
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
		myunorderedmap1.insert({ i + 1, input }); // key가 숫자인 경우
		myunorderedmap2.insert({ input, i + 1 }); // key가 문자열인 경우
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (isNumber(input)) { // 숫자로 입력되면 문자열 출력
			printf("%s\n", myunorderedmap1[stoi(input)].c_str());
		}
		else { // 문자열로 입력되면 숫자 출력
			printf("%d\n", myunorderedmap2[input]);
		}
	}
}