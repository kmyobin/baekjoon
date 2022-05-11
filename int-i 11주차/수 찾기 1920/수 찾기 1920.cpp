#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long int A[100001];

// 1. 입력을 받고 이를 정렬함
// 2. 탐색할 때는 이분탐색 이용
// 
// 정렬에서 시간 초과 발생
// O(nlogn)인 heap_sort 이용

void BinarySearch(int start, int end, int key) {
	if (start > end) {
		printf("0\n"); // cout으로 하면 시간초과
		return;
	}

	int mid = (start + end) / 2; // 반갈

	if (A[mid] == key) { // 찾았으면
		printf("1\n");
		return;
	}
	else if (A[mid] > key) {
		return BinarySearch(start, mid-1, key);
	}
	else {
		return BinarySearch(mid+1, end, key);
	}
}

void max_heapify(int h, int m) { // root / 크기
	// parent node가 child node보다 커야 하는 maxheap
	int v = A[h]; // 일단 keep
	int j = 0;
	for (j = 2 * h; j <= m; j *= 2) {
		if (j < m && A[j] < A[j + 1]) {
			j = j + 1;
		}
		// j는 값이 큰 자식 노드
		if (v >= A[j]) break; // arr[j]가 v에 해당하는 값보다 더 큼
		else A[j / 2] = A[j]; // a[j]를 부모 노드로 이동(더 크므로)
	}
	A[j / 2] = v; // 바꿔줌
}

void max_heap_sort(int size) {
	int n = size - 1;
	// A[0]를 사용하지 않기 때문에 모든 i는 1까지 돌아감

	for (int i = n / 2; i >= 1; i--) {
		max_heapify(i, n); // maxheap 성질에 맞게 데이터를 바꿔줌 (부모>자식)
	}
	for (int i = n - 1; i >= 1; i--) { // 오름차순 정렬
		int temp = A[1];
		A[1] = A[i + 1];
		A[i + 1] = temp;
		max_heapify(1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	max_heap_sort(N+1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		long int value;
		cin >> value;
		BinarySearch(1, N, value);
	}
}