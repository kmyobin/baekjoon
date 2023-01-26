#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> myqueue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		myqueue.push(i);
	}

	int idx = 0;
	cout << "<";
	while (1) {
		if (myqueue.empty())break;
		for (int i = 1; i <= K; i++) {
			int temp = myqueue.front();
			myqueue.pop();			
			if (i == K) {
				idx++;
				cout << temp;
				if (idx < N) {
					cout << ", ";
				}
			}
			else { myqueue.push(temp); }
		}
	}
	cout << ">";
}