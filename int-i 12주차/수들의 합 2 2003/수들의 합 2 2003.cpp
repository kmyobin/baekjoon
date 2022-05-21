#include <iostream>
using namespace std;

unsigned long int N, M; // M의 범위 고려

// two pointer :리스트에 순차적으로 접근할 때 두 개의 점의 위치를 기록하며 처리하는 알고리즘
// 1. 시작점과 끝점이 첫번째 원소의 인덱스를 가리키도록
// 2. 현재 부분의 합이 M과 같다면 count
// 3. 현재 부분 합 < M -> end ++
// 4. 현재 부분 합 >= M -> start++
// 5. 모든 경우를 확인할 때까지 2-4번 과정 반복

// 모든 경우를 확인할 조건 : start 또는 end의 index가 N을 초과한 경우

unsigned long int cnt;
unsigned long int s, e;
unsigned long int sum;

int A[10001]; // index 1부터 사용하므로 +1만큼 배열을 잡아줌

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	s = 1; e = 1; // index 1부터 시작
	
	while (1) {
		if ((s > N) || (e > N))break; // index를 초과하면 break
		sum = 0;
		for (int i = s; i <= e; i++) { // A[s]~A[e]까지 더함
			sum += A[i];
		}
		if (sum == M) { // 원하는 값이 나오면 
			cnt++; // count 증가
			s++; // start 증가 시킴
		}
		else if (sum < M)e++; // 합 < 원하는 값이면 end 증가시킴(더 더해야 하므로)
		else s++; // 합 > 원하는 값이면 start 증가시킴(더 줄여야 원하는 값에 가까워지므로)
	}
	printf("%d", cnt);
	
	return 0;
}