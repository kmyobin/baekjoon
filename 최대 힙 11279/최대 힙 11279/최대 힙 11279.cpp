#include <iostream>
#include <queue>
using namespace std;

int N; int X; int A[100001];
// 0 : 가장 큰 값 출력 후 삭제해라
// 자연수 : 그 값을 넣어라

priority_queue<int> myqueue; // 최대힙을 구현할 수 있는 우선순위 큐, 기본 내림차순 정렬

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		//cout << "input : ";
		cin >> X;
		if (X == 0) { // 가장 큰 수 출력
			if (myqueue.empty()) // 배열이 비어있다면
				printf("0\n");
			else {
				printf("%d\n", myqueue.top()); // 내림차순 정렬이므로
				myqueue.pop();
			}
		}
		else {
			myqueue.push(X);
		}
		//cout << "-------------\n";
	}
}