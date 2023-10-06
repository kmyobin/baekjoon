#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int N;
int A[100000];
int minimum = INT_MAX;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N); // 최대한 작은 수, 큰 수의 합이 0에 가깝도록 오름차순 정렬

	// 양 끝단에서 다가오는 two pointer
	int start = 0, end = N - 1; int temp;
	while (start<end) {
		temp = A[start] + A[end];

		if (abs(temp) < minimum) {
			v.clear();
			v.push_back(A[start]);
			v.push_back(A[end]);
			minimum = abs(temp);
		}

		if (temp < 0) {
			// 0보다 작으면 더 커져야 한다..
			start++;
		}
		else if (temp > 0) {
			// 0보다 크면 더 작아져야 한다..
			end--;
		}
		else {
			// temp == 0 이면 바로 종료
			v.clear();
			v.push_back(A[start]);
			v.push_back(A[end]);

			break;
		}

	}

	sort(v.begin(), v.end());

	cout << v[0] << " " << v[1];
	
}