#include <iostream>
#include <string>
using namespace std;

int main() {

	string line;

	while (1) {
		getline(cin, line);

		if (line=="") break;

		cout << line << endl;
	}
}