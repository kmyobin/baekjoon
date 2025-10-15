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
        vector<int> c = costs; // �̸� ����

        // ������ n�� �����Ͽ� ��� ���� ������ mid �̻��̸� ����
        int prev = 0;
        int gap = distance; // ������ �ּڰ�
        int cnt = 0; // �����ϴ� ���� ����
        c.push_back(distance);
        for (int i = 0; i < c.size(); i++) {
            if (c[i] - prev >= mid) {
                // ���� ������ mid �̻�
                gap = (gap < c[i] - prev) ? gap : c[i] - prev;
                prev = c[i]; // ��Ƴ��� ������ �������� �������
            }
            else {
                // ���� ������ mid �̸��� ��� ���� ����
                cnt++;
            }
        }

        // n�� �ʰ� �����ȰŸ� ���ǿ� ���� ����
        if (cnt > n) {
            // n�� �ʰ� �����ѰŸ� mid �̸��� n�� �ʰ���� ��. ���� ������
            right = mid - 1;
        }
        else {
            // n�� ���ϸ� ���� ���� �� �ȿ��� �ִ� ã��. ���� �ø���
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