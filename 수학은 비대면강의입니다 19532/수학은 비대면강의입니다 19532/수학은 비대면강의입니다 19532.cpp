#include <iostream>
using namespace std;


int a, b, c, d, e, f;
int main() {
	cin >> a >> b >> c >> d >> e >> f;

	int x, y;

	y = (c * d - f * a) / (b * d - e * a);
	if (a != 0)x = (c - b * y) / a; // divisionbyzero ¹æÁö
	else x = (f - e * y) / d;

	cout << x << " " << y;
}