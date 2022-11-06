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

	for (int i = 0; i < N; i++)
	{
		myqueue.push(i + 1);
	}

	printf("<");
	while (!myqueue.empty()) {
		for (int i = 0; i < K - 1; i++) { // 뒤에 push한만큼 앞에서 pop
			myqueue.push(myqueue.front());
			myqueue.pop();
		}
		// 위의 for문 과정을 거치고 나면 K번째 수가 나옴
		if (myqueue.size() == 1) { // 맨 마지막 과정에선 출력 형식이 살짝 다름
			printf("%d>", myqueue.front());
		}
		else {
			printf("%d, ", myqueue.front()); // 출력 후
		}
		myqueue.pop(); // 없애줌
	}
}