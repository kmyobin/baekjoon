#include <iostream>
#include <algorithm>
using namespace std;

int N, cnt, col[16], inc[32], des[32];

void solve(int r) {
    if (r > N) {
        cnt++;
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!col[i] && !inc[r + i] && !des[N + (r - i) + 1]) {
            col[i] = inc[r + i] = des[N + (r - i) + 1] = 1;
            solve(r + 1);
            col[i] = inc[r + i] = des[N + (r - i) + 1] = 0;
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
