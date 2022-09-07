#include <iostream>
#include <cmath>
using namespace std;

int N;
int cnt; // Queen이 놓아지는 경우의 수
int col[16]; // col[i] = j : i행 j열

void solve(int row) { // 행을 움직이면서 돌 것임
    if (row > N) { // 전체 행을 다 돌았다는 건 N-Queen 조건을 만족한다는 것
        cnt++; // 경우의 수 증가
        return;
    }

    for (int i = 1; i <= N; i++) { // 열만큼 반복
        bool is_no = false; // N-Queen 규칙에 위배되는지 따져보는 bool 변수
        col[row] = i; // row행 i열에 Queen을 놓았다면
        for (int k = 1; k < row; k++) { // 그 전 행들에 있는 Queen들과의 규칙과 위배되는지
            if (col[k] == col[row] || abs(col[k] - col[row]) == abs(k - row)) {
                // 같은 열이거나 대각선에 있다면
                is_no = true; // N-Queen 규칙 위배
                break;
            }
        }
        if (is_no == true) { // 지금 놓은 거 규칙에 위배되므로
            col[row] = 0; // 할당해주었던 열 값 지워줌
        }
        else { // 규칙을 무사히 통과했다면
            solve(row + 1); // 다음 행에서 살펴보기
            col[row] = 0; // 다른 곳으로 backtracking
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    solve(1);
    printf("%d", cnt);

}
