#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int N;
stack<int> s;
int cnt = 1;

int main() {

	cin >> N;

	for (int i = 1; i <= N; i++) {
		int input;
		cin >> input;

		if (cnt != input)s.push(input);
		else {
			cnt++;
			while (1) {
				if (!s.empty() && cnt == s.top()) {
					cnt++;
					s.pop();
				}
				else break;
			}
		}

	}

	if (s.empty())cout << "Nice";
	else {
		if (s.top() != cnt)cout << "Sad";
		else cout << "Nice";
	}
}

/*
stack<int> s;
queue<int> q;
int N;
int max_s = -1;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tmp; cin >> tmp;
		q.push(tmp);
	}

	s.push(0);

	while (1) {

		if (q.empty()) {
			if (max_s + 1 == s.top()) {
				cout << "Nice";
			}
			else {
				cout << "Sad";
			}
			break;
		}

		// max_s, s.top, q.front ºñ±³

		if (max_s + 1 == q.front()) {
			max_s = q.front();
			q.pop();
		}
		else if (s.top() + 1 == q.front()) {
			if (max_s + 1 != s.top()) {
				cout << "Sad";
				break;
			}

			max_s = s.top();
			s.pop();

			s.push(q.front());
			q.pop();
		}
		else if (max_s + 1 == s.top()) {
			while (1) {
				if (!s.empty() && max_s + 1 == s.top()) {
					max_s = s.top();
					s.pop();
				}
				else break;
			}
			s.push(q.front());
			q.pop();
		}
		else {
			if (s.top() < q.front()) {
				cout << "Sad";
				break;
			}

			s.push(q.front());
			q.pop();
		}
	}

}
*/