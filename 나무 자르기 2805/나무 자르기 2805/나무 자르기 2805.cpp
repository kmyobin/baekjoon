#include <iostream>
using namespace std;

int N, M; 
int A[1000000];
int maximum = -1;
// 절단기 설정 값은 0 ~ 최대 max(A)

void BinarySearch(int start, int end) {
	if (start > end)return;

	int key = (start + end) / 2; // 절단기에서 설정할 수 있는 높이의 최댓값

	long long int sum = 0; // 나무의 길이가 2,000,000,000일 수 있기 때문에 큰 자료형
	for (int i = 0; i < N; i++)
	{
		if (A[i] - key >= 0) { // 자르고 그 위에 있는 것들 가져갈 수 있음
			sum += A[i] - key; // 가져갈 수 있는 나무를 구함

		}
	}
	
	if (sum >= M) { // 적어도 M미터의 나무를 구했다면
		maximum = (key > maximum) ? key : maximum; // 이 key가 최댓값인지
		BinarySearch(key + 1, end); // 더 큰 값을 위해 오른쪽 부분 탐색
	}
	else {
		BinarySearch(start, key - 1); // 못 구했다면 더 많이 잘라야 함. 그러려면 절단기 설정 높이가 더 낮아야함
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int maxi = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		maxi = (A[i] > maxi) ? A[i] : maxi;
	}


	BinarySearch(0, maxi);

	cout << maximum;

}