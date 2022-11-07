#include <iostream>
#include <stack>
#include <string>
using namespace std;

// L : 커서 왼 쪽으로
// D : 커서 오른쪽으로
// B : 커서 왼쪽에 있는 문자 삭제
// P $ : $를 커서 왼쪽에 추가

stack<char> l;
stack<char> r;

string input;
int M;
string C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 입력
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		l.push(input[i]);
	}

	// 명령어 실행
	cin >> M;
	cin.ignore(); // cin으로 입력받은 이후 getline을 사용하면 '\n'때문에 무시되는 경우 발생
	for (int i = 0; i < M; i++)
	{
		getline(cin, C);
		if (C[0] == 'P') { // 커서 왼쪽에 문자 넣음

			l.push(C[2]);
		}
		else if (C[0] == 'L') { // 커서 왼쪽으로 이동
			if (l.empty()) {}
			else {
				r.push(l.top());
				l.pop();
			}
		}
		else if (C[0] == 'D') { // 커서 오른쪽으로 이동
			if (r.empty()) {}
			else {
				l.push(r.top());
				r.pop();
			}
		}
		else { // 커서 왼쪽에 있는 문자 삭제
			if (l.empty()) {}
			else { l.pop(); }
		}
	}

	while (!l.empty()) { // 커서 왼쪽에 있는 문자들 오른쪽으로 옮김
		r.push(l.top());
		l.pop();
	}

	while (!r.empty()) { // 답 출력
		printf("%c", r.top());
		r.pop();
	}
}