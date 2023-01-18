#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string x;
	while (1) {		
		getline(cin, x);
		if (x == ".") break; // x가 점 하나면 입력 종료

		int i = 0;
		stack<char> mystack; bool isWrong = false;
		while (1) {
			if (x[i] == '.') break;
			// 1. 괄호가 시작
			if (x[i] == '(' || x[i] == '[') mystack.push(x[i]);
			// 2. 소괄호가 닫히는 경우
			if (x[i] == ')') {
				if (!mystack.empty()) {
					if (mystack.top() == '(') mystack.pop();
					else { isWrong = true; break; }
				}
				else { isWrong = true; break; }				
			}
			// 3. 대괄호가 닫히는 경우
			if (x[i] == ']') {
				if (!mystack.empty()) {
					if (mystack.top() == '[')mystack.pop();
					else { isWrong = true;break; }
				}
				else { isWrong = true; break; }
			}
			i++;
		}
		if (!isWrong) {
			if (mystack.empty())printf("yes\n");
			else printf("no\n");
		}
		else printf("no\n");
	}
}