#include <iostream>
using namespace std;

int N; int A[1000];

void bubble_sort(int A[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (A[j] > A[j + 1]) { // 오름차순 정렬
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
			}
		}
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	bubble_sort(A, N);

	for (int i = 0; i < N; i++) {
		cout << A[i] << endl;
	}
}