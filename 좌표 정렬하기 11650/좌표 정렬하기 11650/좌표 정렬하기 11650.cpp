#include <iostream>
#include <algorithm>
using namespace std;

int N;

typedef struct xy {
	int x;
	int y;
}xy;

xy xy_[100000];

bool cmp(xy xy1, xy xy2) {
	if (xy1.x == xy2.x) {
		return xy1.y < xy2.y;
	}
	return xy1.x < xy2.x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> xy_[i].x >> xy_[i].y;
	}

	sort(xy_, xy_ + N, cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", xy_[i].x, xy_[i].y);
	}
}