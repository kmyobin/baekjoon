#include <iostream>
using namespace std;

int N;

struct mm {
	int num;
	int rank;
	int original;
};

mm B[1000000];

void quick_sort1(int left, int right) {
	if (left >= right)return;
	int p_right = right;
	int p_left = left;

	int pivot = B[(left + right) / 2].num;

	while (p_left <= p_right) {
		while (B[p_left].num < pivot) { p_left++; }
		while (pivot < B[p_right].num) { p_right--; }
		if (p_left <= p_right) {
			swap(B[p_left], B[p_right]);
			p_left++; p_right--;
		}
	}
	quick_sort1(left, p_right);
	quick_sort1(p_left, right);
}

void quick_sort2(int left, int right) {
	if (left >= right)return;
	int p_right = right;
	int p_left = left;

	int pivot = B[(left + right) / 2].original;

	while (p_left <= p_right) {
		while (B[p_left].original < pivot) { p_left++; }
		while (pivot < B[p_right].original) { p_right--; }
		if (p_left <= p_right) {
			swap(B[p_left], B[p_right]);
			p_left++; p_right--;
		}
	}
	quick_sort2(left, p_right);
	quick_sort2(p_left, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> B[i].num;
		B[i].original = i;
	}

	// num 기준으로 정렬
	quick_sort1(0, N - 1);

	// rank
	int before = B[0].num;
	int rank = 0;
	for (int i = 1; i < N; i++) {
		if (before == B[i].num) {
			B[i].rank = rank;
		}
		else {
			rank++;			
			B[i].rank = rank;
		}
		before = B[i].num;
	}

	// 원래 입력됐던 순서대로 정렬
	quick_sort2(0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", B[i].rank);
	}
}