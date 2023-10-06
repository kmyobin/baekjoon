#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 7 ~ 42
// 7 8 9 10 11 12 ... 40 41 42
// 시간에 대한 이분탐색
vector<int> times_;
long long n_; long long answer_;

void binary_search(long long start, long long end) {
    while (1) {
        if (start > end) return;

        long long middle = (start + end) / 2;

        long long result_people = 0;

        for (long long time : times_) {
            result_people += middle / time;
            if (result_people == n_) break;
        }

        if (result_people >= n_) {
            answer_ = (answer_ < middle) ? answer_ : middle;
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }
    }
}

long long solution(int n, vector<int> times) {
    long long answer = 0;

    sort(times.begin(), times.end());

    times_ = times; n_ = (long long)n;

    long long start = (long long)times[0];
    long long end = (long long)times[0] * (long long)n; // 형변환 안해주면 X
    answer_ = end;

    binary_search(start, end);

    answer = answer_;
    return answer;
}

int main() {
    int n = 6; vector<int> times = { 7,10 };
    long long answer = solution(n, times);
    cout << answer;
}