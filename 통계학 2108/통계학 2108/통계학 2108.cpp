#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct memo {
	int num;
	int cnt;
}memo;

memo m[500001];

int A[500001];
double result;
int N;

bool cmp1(memo a, memo b) {
	return a.num < b.num;
}

bool cmp2(memo a, memo b) {
	if (a.cnt == b.cnt) {
		a.num < b.num;
	}
	return a.cnt > b.cnt;
}
// 반올림 하는 법 floor(X+0.5)

// 산술평균 : N개의 수들의 합 / N
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 최빈값 : N개의 수들 중 가장 많이 나타나는 값
// 범위 : 최댓값 - 최솟값

int main() {
	cin >> N;

	int k = 0;

	for (int i = 0; i < N; i++)
	{
		int x;
		bool isit = false;
		cin >> x;
		result += x; // 산술평균
		for (int j = 0; j < k; j++) {
			if (x == m[j].num) { // 이미 입력됐었던 수라면
				printf("%d가 이미 입력된 관계로 카운트만 했습니다.\n", x);

				m[j].cnt++;
				isit = true;
				break;
			}
		}
		if (isit == true) {} // 이미 입력됐었던 수라면 pass
		else { // 새로 입력된 수라면
			printf("%d가 새로입력되었습니다.\n", x);
			m[k].num = x;
			m[k].cnt++;
			k++;
		}
		A[i] = x;

	}
	for (int i = 0; i < k; i++) {
		printf("num: %d, cnt: %d | ", m[i].num, m[i].cnt);
	}
	printf("\n");
	// 1. 산술평균
	cout << int(floor(result / double(N) + 0.5)) << endl;


	// 2. 중앙값
	sort(m, m + k, cmp1);
	sort(A, A + N);
	for (int i = 0; i < k; i++) {
		printf("num: %d, cnt: %d | ", m[i].num, m[i].cnt);
	}
	printf("\n");
	int maximum = m[k - 1].num;
	int minimum = m[0].num;
	cout << A[N / 2] << endl;

	// 3. 최빈값
	sort(m, m + k, cmp2);
	for (int i = 0; i < k; i++) {
		printf("num: %d, cnt: %d | ", m[i].num, m[i].cnt);
	}
	printf("\n");
	if (m[0].cnt == m[1].cnt) { // 최빈값이 두 개 이상이면
		cout << m[1].num << endl; // 두 번째로 작은 값
	}
	else {
		cout << m[0].num << endl;
	}

	// 4. 범위
	cout << maximum - minimum << endl;


}