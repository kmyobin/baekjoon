#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> costs, int distance, int n) {
    
    int maximum = 0;
    int left = 0; int right = distance;
    while (left <= right) {
        int mid = (left + right) / 2;
        vector<int> c = costs; // 미리 저장

        // 바위를 n번 삭제하여 모든 바위 간격이 mid 이상이면 성공
        int prev = 0;
        int gap = distance; // 간격의 최솟값
        int cnt = 0; // 삭제하는 바위 개수
        c.push_back(distance);
        for (int i = 0; i < c.size(); i++) {
            if (c[i] - prev >= mid) {
                // 바위 간격이 mid 이상
                gap = (gap < c[i] - prev) ? gap : c[i] - prev;
                prev = c[i]; // 살아남은 바위만 이전바위 취급해줌
            }
            else {
                // 바위 간격이 mid 미만인 경우 바위 삭제
                cnt++;
            }
        }

        // n개 초과 삭제된거면 조건에 맞지 않음
        if (cnt > n) {
            // n개 초과 삭제한거면 mid 미만이 n개 초과라는 것. 구간 내리기
            right = mid - 1;
        }
        else {
            // n개 이하면 ㄱㅊ 이제 이 안에서 최댓값 찾자. 구간 올리기
            maximum = maximum > gap ? maximum : gap;
            left = mid + 1;
        }

    }

    return maximum;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());
    
    answer = binarySearch(rocks, distance, n);

    cout << "maximum: " << answer << endl;

    return answer;
}

int main() {
    int distance = 25;
    vector<int> rocks = { 2,14,11,21,17 }; // 2 11 14 17 21
    int n = 2;

    int answer = solution(distance, rocks, n);

    cout << answer;
}