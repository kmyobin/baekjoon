#include <iostream>
#include <stack>
#include <string>
using namespace std;

string S;
stack<char> mystack; // 문자열 하나씩 담음

void print() { // stack 출력
	int size = mystack.size(); 
	for (int i = 0; i < size; i++) {
		cout << mystack.top();
		mystack.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, S);

	int i = 0; bool istag = false;
	while (i<S.length()) {
		if (istag) { // tag 안에 있다면
			cout << S[i];
			if (S[i] == '>') { // tag 닫히면
				istag = false; // 다시 false
			}
		}
		else { // tag 안에 있지 않다면
			if (S[i] == '<') { // tag가 시작됐다면
				print(); // 그 전에 담아놨을지도 모를 단어 출력
				cout << S[i];
				istag = true;
			}
			else {
				if (S[i] == ' ') { // tag 안에 있지도 않고 공백이 나타났다면 단어
					print(); // 거꾸로 단어 출력
					cout << S[i]; // 공백은 뒤에 출력
				}				
				else { // 단어가 입력되고 있다면
					mystack.push(S[i]); // 단어이므로 stack에 push
					if (i == S.length() -1) { // 맨 마지막에 단어가 오는 경우
						print();
					}
				}
			}
		}
		i++;
	}

}