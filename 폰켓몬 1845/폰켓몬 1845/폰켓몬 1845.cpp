#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;

    for (auto n : nums) {
        m[n]++;
    }

    // 가져갈 수 있는 폰켓몬 수와 갖고 있는 폰켓몬 종류 수 중 최솟값
    answer = min(nums.size() / 2, m.size()); // size로 하면 틀림 ..
    return answer;
}

int main() {
    vector<int> nums = { 3,1,2,3 };
    cout << solution(nums);
}