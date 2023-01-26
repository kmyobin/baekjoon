#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct mymy {
	int idx; 
	bool isCheck = false;
};

int K; int A[100]; // 중요도 내림차순 정렬에 필요한 배열

bool cmp(int a, int b) { // 내림차순
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int N, M; queue<mymy> myqueue;
		cin >> N >> M;

		// queue 생성
		for (int j = 0; j < N; j++)
		{
			int tmp; cin >> tmp;
			if (j == M) { 
				// 내가 궁금한 queue 순서라면
				// isCheck를 true로
				myqueue.push({ tmp, true }); 
			} 
			else myqueue.push({ tmp, false });
			A[j] = tmp; // 중요도를 배열에도 담음
		}

		// 순서 출력
		int order = 1;
		while (1) {
			sort(A, A + N, cmp); // 내림차순 정렬
			int maximum = A[0]; // 지금 제일 큰 중요도
			mymy tmp; tmp = myqueue.front();
			if (tmp.idx < maximum) {
				// 하나라도 중요도 큰 게 뒤에 있다면
				// queue의 가장 뒤에 재배치
				myqueue.pop(); myqueue.push(tmp); 				
			}
			else {
				// 내가 제일 크면
				if (tmp.isCheck) {
					// 내가 궁금해하던 순서라면
					// 순서 출력 후 바로 종료
					cout << order << "\n";
					break;
		  		}
				else {
					// 내가 궁금해하던게 아니면
					// 인쇄 (pop)
					myqueue.pop();
					N--; // 인쇄될 때마다 문서의 개수가 하나씩 줄어드므로
					A[0] = 0; // 1-9이므로 0으로 설정하여 없는 중요도 취급
					order++; // 순서 증가
				}
			}
		}
	}
}