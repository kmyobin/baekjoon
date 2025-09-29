#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> people = { 40,40,40,40 };
int limit = 120;

int main() {
    int answer = 0;

    sort(people.begin(), people.end());

    int left = 0;
    int right = people.size() - 1;

    while (left <= right) {
        if (people[left] + people[right] <= limit) {
            // ���� ������ ����� ���ſ� ����� Ż �� ������
            left++; // ������ �� �� ������ (������ �ִ� �θ� Ż �� ����)
        }
        answer++; // �׷��� ������
        right--; // ���ſ� �� �� ������
    }

    cout << answer;
}