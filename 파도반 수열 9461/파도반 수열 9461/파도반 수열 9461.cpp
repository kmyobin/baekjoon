#include <iostream>
using namespace std;

unsigned long long int A[101] = { 0,1,1,1,2,2,3,4,5, }; // 초기 값 설정

void dp() {
	for (int i = 9; i <= 100; i++) {
		A[i] = A[i - 1] + A[i - 5];
	}
}

int T, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	dp();

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << A[N] << endl;
	}
}