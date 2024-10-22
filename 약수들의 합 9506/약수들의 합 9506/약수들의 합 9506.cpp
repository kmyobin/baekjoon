#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;

int main() {
	while (1) {
		cin >> n;
		if (n == -1) break;
		int sum = 0;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				v.push_back(i);
			}
		}

		cout << n << " ";
		if (sum == n) {
			cout << "=";
			for (int i = 0; i < v.size(); i++) {
				cout << " " << v[i];
				if (i < v.size() - 1) cout << " +";
			}
		}
		else cout << "is NOT perfect.";
		
		cout << "\n";
		v.clear();
	}
}