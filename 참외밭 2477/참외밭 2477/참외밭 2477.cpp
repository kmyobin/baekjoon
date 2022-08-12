#include <iostream>
using namespace std;

int K;
int max_row = -1, max_col = -1; // 큰 직사각형 넓이
int min_row, min_col; // 작은 직사각형 넓이

struct info {
	int dir;
	int len;
};

info inf[6];

int Com[4][2][3] = {
	{{2,3,2}, {3,2,3}},
	{{4,2,4}, {2,4,2}},
	{{3,1,3}, {1,3,1}},
	{{1,4,1}, {4,1,4}}
};

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> K;

	for (int i = 0; i < 6; i++)
	{
		cin >> inf[i].dir >> inf[i].len;
		if (inf[i].dir == 3 || inf[i].dir == 4) { // 남북 (세로)
			max_row = inf[i].len > max_row ? inf[i].len : max_row;
		}
		else { // 동서 (가로)
			max_col = inf[i].len > max_col ? inf[i].len : max_col;
		}
	}

	for (int i = 0; i < 4; i++) // inf를 움직임
	{
		for (int j = 0; j < 4; j++) { // Com을 움직임
			if (inf[i].dir == Com[j][0][0] && inf[i + 1].dir == Com[j][0][1] && inf[i + 2].dir == Com[j][0][2]) {
				min_row = inf[i + 1].len;
				min_col = inf[i + 2].len;
			}
			else if (inf[i].dir == Com[j][1][0] && inf[i + 1].dir == Com[j][1][1] && inf[i + 2].dir == Com[j][1][2]) {
				min_row = inf[i].len;
				min_col = inf[i + 1].len;
			}
		}
	}
	for (int j = 0; j < 4; j++) {
		if (inf[4].dir == Com[j][0][0] && inf[5].dir == Com[j][0][1] && inf[0].dir == Com[j][0][2]) {
			min_row = inf[5].len;
			min_col = inf[0].len;
		}
		else if (inf[5].dir == Com[j][1][0] && inf[0].dir == Com[j][1][1] && inf[1].dir == Com[j][1][2]) {
			min_row = inf[5].len;
			min_col = inf[0].len;
		}
	}
	int area = (max_row * max_col) - (min_row * min_col); // 큰 직사각형 - 패인 직사각형
	printf("%d", area * K);

}