#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int N;
int A[100];
int B[99];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N); // A 배열 오름차순 정렬


	for (int i = 0; i < N-1; i++) { // A배열 차이 B 배열에 넣기
		B[i] = A[i + 1] - A[i];
	}
	sort(B, B + N - 1); // B 배열 오름차순 정렬


	int R = B[0];
	for (int i = 0; i < N - 2; i++) {
		int big = B[i+1]; int small = R;
		while (1) {
			R = big % small;
			if (R == 0) {
				R = small;
				break;
			}
			big = small; small = R;
		}
	} 
	// R의 공약수 구하면 됨(1 제외)

	// 약수 구하기
	set<int> myset;
	for (int i = 1; i * i <= R; i++) {
		if (R % i == 0) {
			myset.insert(i);
			myset.insert(R / i);
		}
	}
	myset.erase(1); // M은 1보다 크므로 없앰

	set<int> ::iterator iter;
	for (iter = myset.begin(); iter != myset.end(); iter++)
	{
		printf("%d ", *iter);
	}
}