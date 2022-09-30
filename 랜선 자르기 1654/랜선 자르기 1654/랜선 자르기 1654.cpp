#include <iostream>
using namespace std;

int N, K;
int A[1000000];
int maximum = -1;
// 802 : 200 200 200 200 2
// 743 : 200 200 200 143
// 457 : 200 200 57
// 539 : 200 200 139

// 200개 총 11 개


// 랜선 길이의 범위는? 0 ~ 2^31 -> 0 ~ max(A)


void BinarySearch(long long int start, long long int end) { // 안 하면 key 부분에서 오버플로우가 나는 듯
	if (start > end) return;

	long long int key = (start + end) / 2; // start랑 end 더해서 int의 범위를 넘어갈 수 있으므로 long long

	long long int cnt = 0; 
	bool is_success = false;
	for (int i = 0; i < K; i++) {
		cnt += A[i] / key; // 랜선의 길이가 최대 2^31-1이므로 key가 최소일 때 cnt에서 overflow 발생 가능. 그러므로 cnt가 long long
		if (cnt >= N) { // N개 이상으로 많이 만들면
			is_success = true;
			break; // 나가
		}
	}

	if (is_success) {
		maximum = (key > maximum) ? key : maximum; // 최댓값 갱신
		BinarySearch(key + 1, end); // 더 최대 길이 있는지 key보다 큰 범위에서 찾아봄
	}
	else { 
		BinarySearch(start, key - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N; // 이미 K개가 있는데 N개의 랜선이 필요함

	int maxi = -1;
	for (int i = 0; i < K; i++)
	{
		cin >> A[i];
		maxi = (A[i] > maxi) ? A[i] : maxi;
	}

	BinarySearch(1, maxi); // 1부터 maxi까지 탐색

	cout << maximum;
}