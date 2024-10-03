#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
int A[10000000];

void make_prime_arr() {

    for (int i = 2; i < 10000000; i++) A[i] = 1; // A[1]은 소수 아님

    for (int i = 2; i < 10000000; i++) {
        if (A[i] == 0) continue; // 이미 소수가 아니면 지우기(그것의 배수도 소수가 아닐테니)
        for (int j = 2 * i; j < 10000000; j += i) {
            A[j] = 0; // 소수가 아닌 것들 지우기
        }
    }
}


int ans[10000000]; // 소수가 이미 count되었으면 구분하기 위한 용도
int solution(string numbers) {
    make_prime_arr(); // 소수 만들어서 A[] 배열에 저장

    int answer = 0;
    vector<char> v;

    sort(numbers.begin(), numbers.end()); // next_permutation 특성상 오름차순 정렬해야 모든 경우의 수가 나옴

    for (int i = 0; i < numbers.size(); i++)v.push_back(numbers[i]);

    do {
        string s = "";

        for (int i = 0; i < v.size(); i++) {
            s += v[i];

            if (A[stoi(s)] == 1) {
                // 소수인 경우
                if (ans[stoi(s)] != 1) {
                    answer++;
                    ans[stoi(s)] = 1;
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

int main() {

    string numbers = "011";

    cout << solution(numbers);
}