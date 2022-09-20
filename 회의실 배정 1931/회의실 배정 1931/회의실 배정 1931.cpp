#include <iostream>
#include <algorithm>
using namespace std;

int N; int cnt;
int first = 2147483647;

struct A {
	int start;
	int end;
};

struct A A[100000];

bool cmp(struct A a, struct A b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i].start >> A[i].end;
		first = (A[i].start < first) ? A[i].start : first;
	}
	
	sort(A, A + N, cmp);
	

	int before_last = first; // 0

	for (int i = 0; i < N; i++) {
		if (A[i].start >= before_last) {
			cnt++;
			before_last = A[i].end;
		}
	}
	cout << cnt;
}