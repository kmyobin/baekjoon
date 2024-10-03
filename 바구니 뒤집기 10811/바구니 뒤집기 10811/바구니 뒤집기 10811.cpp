#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
int N, M;
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)A.push_back(i);

	for(int i=0;i<M; i++){
		int x, y;

		cin >> x >> y;
		reverse(A.begin() + (x - 1), A.begin() + y);

	}

	for (int i = 0; i < N; i++)cout << A[i] + 1 << " ";

}