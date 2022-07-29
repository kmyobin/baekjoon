#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;

unordered_set<string> myset;
string input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> input;

	for (int i = 1; i <= input.length(); i++) {
		for (int j = 0; j < input.length(); j++) {
			string temp = "";
			temp = input.substr(j, i);
			myset.insert(temp);
		}
	}

	printf("%d", myset.size());
}