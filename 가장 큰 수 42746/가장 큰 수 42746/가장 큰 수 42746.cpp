#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b) {
    string x = a + b; string y = b + a;
    return stoi(x) > stoi(y); // 숫자 합 한 것을 기준으로 
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> x;
    for (auto n : numbers) {
        x.push_back(to_string(n));
    }
    sort(x.begin(), x.end(), cmp);
    for (auto a : x) {
        //cout<<a<<" ";
        answer += a;
    }

    if (answer[0] == '0') return "0";
    return answer;
}

int main() {
    vector<int> numbers = { 6,10,2 };
    cout << solution(numbers);
}