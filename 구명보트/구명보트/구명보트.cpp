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
            // 가장 가벼운 사람과 무거운 사람이 탈 수 있으면
            left++; // 가벼운 애 너 나가라 (어차피 최대 두명만 탈 수 있음)
        }
        answer++; // 그렇게 가세요
        right--; // 무거운 애 너 나가라
    }

    cout << answer;
}