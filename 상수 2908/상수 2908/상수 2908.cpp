#include <iostream>
#include <string>
using namespace std;

string a, b;

int main() {
	cin >> a >> b;
	int a_ = 100 * (a[2] - 48) + 10 * (a[1] - 48) + (a[0] - 48);
	int b_ = 100 * (b[2] - 48) + 10 * (b[1] - 48) + (b[0] - 48);
	printf("%d", a_ > b_ ? a_ : b_);
}