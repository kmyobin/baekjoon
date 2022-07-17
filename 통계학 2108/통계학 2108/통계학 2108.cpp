#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct memo {
	int num;
	int cnt;
}memo;

memo m[500001];
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

	for (int i = 0; i < N; i++){
		int x;
		bool isit = false;
		cin >> x;
		result += x; // 산술평균
		for (int j = 0; j < k; j++) {
			if (x == m[j].num) { // 이미 입력됐었던 수라면
				m[j].cnt++;
				isit = true;
				break;
			}
		}
		if (isit == true) {} // 이미 입력됐었던 수라면 pass
		else { // 새로 입력된 수라면
			m[k].num = x;
			m[k].cnt++;
			k++;
		}
	}

	// 1. 산술평균
	cout << int(floor(result / double(N) + 0.5)) << endl;
	 

	// 2. 중앙값
	sort(m, m + k, cmp1);

	// 최댓값, 최솟값 미리 구함
	int maximum = m[k - 1].num;
	int minimum = m[0].num;	
	
	
	int middle = N / 2;
	bool isit = false;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m[i].cnt; j++) {
			if (middle == 0) {
				cout << m[i].num << endl;
				isit = true;
				break;
			}
			middle--;
		}
		if (isit == true) { break; }
	}



	// 3. 최빈값
	sort(m, m + k, cmp2);
	if (m[0].cnt == m[1].cnt) { // 최빈값이 두 개 이상이면
		cout << m[1].num << endl; // 두 번째로 작은 값
	}
	else {
		cout << m[0].num << endl;
	}

	// 4. 범위
	cout << maximum - minimum << endl;


}