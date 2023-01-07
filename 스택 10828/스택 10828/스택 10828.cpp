#include <iostream>
using namespace std;

int N;

struct stack_ {
	int start = 1; int end = 0;
	int A[10001];

	void push(int value) {
		end++;
		A[end] = value;
	}

	int pop() {
		if (start > end)return -1;
		else {
			end--;
			return  A[end+1];
		}
	}

	int size() {
		if (start > end) return 0;
		else return end - start + 1;
	}

	int top() {
		if (start > end) return  -1;
		else return A[end];
	}

	int empty() {
		if (size() == 0) return 1;
		else return 0;
	}
};

stack_ mystack;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string command;
		cin >> command;
		if (command == "push") {
			int tmp;
			cin >> tmp;
			mystack.push(tmp);
		}
		else if (command == "top") {
			cout << mystack.top() << endl;
		}
		else if (command == "size") {
			cout << mystack.size() << endl;
		}
		else if (command == "pop") {
			cout << mystack.pop() << endl;
		}
		else {
			cout << mystack.empty() << endl;
		}
	}
}