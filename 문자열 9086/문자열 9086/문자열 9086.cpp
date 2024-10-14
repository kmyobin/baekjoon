#include <iostream>
#include <string>
using namespace std;

int T;

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;

		cout << input[0] << input[input.length() - 1] << endl;
	}
}