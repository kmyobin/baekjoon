#include <iostream>
#include <queue>
using namespace std;

int N;
queue<int> myqueue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		myqueue.push(i);
	}

	while (1) {
		if (myqueue.size() == 1) {
			break;
		}
		myqueue.pop();
		int temp = myqueue.front();
		myqueue.pop();
		myqueue.push(temp);
	}

	cout << myqueue.front();
}