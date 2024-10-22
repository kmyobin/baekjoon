#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<int> v;

int main() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		if (N % i == 0) {
			v.push_back(i);
		}		
	}

	if (v.size() < K)cout << 0;
	else cout << v[K-1];
}