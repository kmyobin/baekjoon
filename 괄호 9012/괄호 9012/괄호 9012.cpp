#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		// 배열 50으로 하면 에러
		char input[51]; cin >> input;
		bool isWrong = false; stack<int> mystack;
		for (int j = 0; j < strlen(input); j++) {
			if (input[j] == '(') {
				// 열리는 괄호
				mystack.push(1);
			}
			else {
				// 닫히는 괄호
				if (mystack.empty()) {
					// 이미 비어있다면 짝이 안맞는 것임
					cout << "NO\n";
					isWrong = true;
					break;
				}
				else {
					// 아직 안비어있다면
					mystack.pop();
				}
			}
		}
		if (!isWrong) {
			// for문을 다 지나간 경우
			if (!mystack.empty()) {
				// 다 비워져있어야 하는데 아니라면
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}

	}
}