#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int minimum = 1001;

int solution(string s) {
    int size = s.length();

    for (int i = 1; i < s.length(); i++) {
        string result = ""; // 압축된 문자열이 담길 문자열
        // 문자열 i개씩 압축
        string cur = ""; string tmp = "";
        int t;
        for (int j = 0; j < s.length(); j += t * i) {
            cur = s.substr(j, i);
            t = 1;
            while (1) {
                if (j + t * i > s.length()) break;
                tmp = s.substr(j + t * i, i);
                if (cur != tmp) { // 다르다면
                    break;
                }
                t++;
            }
            if (t > 1) {// 두번 이상
                result += to_string(t); // 숫자 먼저 추가
            }
            result += cur;

        }

        int len = result.length();
        minimum = min(minimum, len);
    }


    if (minimum == 1001) {
        // for문에 들어가지 않은 경우 : 문자열 길이 1
        minimum = 1;
    }
    return minimum;
}

int main() {
    string s = "aabbaccc";
    cout << solution(s);

}