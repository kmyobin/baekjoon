#include <iostream>
using namespace std;

int N;
struct myqueue {
	int start = 0, end = -1;
	int A[2000001];

	void push(int x) {
		end++;
		A[end] = x;
	}

	void pop() {
		if (empty()) { cout << "-1\n"; }
		else {
			cout << A[start] << "\n";
			start++;
		}
	}

	int size() {
		return end - start + 1;
	}

	int empty() {
		if (size() == 0) { return 1; }
		else return 0;
	}

	int front() {
		if (empty()) return -1;
		else return A[start];
	}

	int back() {
		if (empty()) return -1;
		else return A[end];
	}
};

struct myqueue myq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string temp; cin >> temp;
		if (temp == "push") {
			int value; cin >> value;
			myq.push(value);
		}
		else if (temp == "pop") {
			myq.pop();
		}
		else if (temp == "front") {
			cout << myq.front() << "\n";
		}
		else if (temp == "back") {
			cout << myq.back() << "\n";
		}
		else if (temp == "size") {
			cout << myq.size() << "\n";
		}
		else {
			cout << myq.empty() << "\n";
		}
	}
}