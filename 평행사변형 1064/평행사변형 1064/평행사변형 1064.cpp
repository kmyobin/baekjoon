#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct xy {
	double x;
	double y;
};

struct xy xy[3];

bool cmp1(struct xy A, struct xy B) {
	if (A.x == B.x) {
		return A.y < B.y;
	}
	return A.x < B.x; // x 오름차순 정렬
}

double PITA(int x1, int y1, int x2, int y2) { // 두 점 사이의 길이
	return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

int main() {
	for (int i = 0; i < 3; i++)
	{
		cin >> xy[i].x >> xy[i].y;
	}

	sort(xy, xy + 3, cmp1);
	
	if ((xy[0].y - xy[1].y) * (xy[1].x - xy[2].x) == (xy[1].y - xy[2].y) * (xy[0].x - xy[1].x)) {
		// 한 직선에 3개의 점이 있으면(기울기가 같으면) 사각형이 만들어 질 수 없음
		// 하지만 나눗셈(/)을 쓴다면 division by zero가 발생할 수 있으므로 사용하지 않음
		cout << "-1.0";
	}
	else
	{
		double AB = PITA(xy[0].x, xy[0].y, xy[1].x, xy[1].y);
		double AC = PITA(xy[0].x, xy[0].y, xy[2].x, xy[2].y);
		double BC = PITA(xy[1].x, xy[1].y, xy[2].x, xy[2].y);
		double sum1 = 2 * (AB + AC);
		double sum2 = 2 * (AB + BC);
		double sum3 = 2 * (BC + AC);


		double maximum = max(sum3, max(sum1, sum2));
		double minimum = min(sum3, min(sum1, sum2));

		printf("%.16lf", (maximum - minimum));
	}
}