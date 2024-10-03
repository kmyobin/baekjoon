#include <iostream>
#include <string>
using namespace std;

string x;
int main() {
	cin >> x;

	int e = x.size() - 1; // 맨 마지막
	for (int i = 0; i <= e; i++, e--) {
		if (x[i] != x[e]) {
			cout << "0" << endl;
			return 0;
		}
	}
	cout << "1" << endl;
}