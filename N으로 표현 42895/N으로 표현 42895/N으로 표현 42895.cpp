#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

int N = 5;
int number = 31168;

/*

DP[1] = {5} : 1개의 5로 만들 수 있는 숫자들
N1: N

DP[2] = NN, N1@N1

DP[3] = NNN, N2@N1

DP[4] = NNNN, N3@N1, N2@N2

DP[5] = NNNNN, N4@N1, N3@N2

DP[6] = NNNNNN, N5@N1, N4@N2, N3@N3


DP[k] = k개의 N으로 만들 수 있는 숫자들
DP[k]= NN..N(N은 k개), DP[i] @ DP[j] (i+j=k)
*/

int main() {
    int answer = -1;
    
    vector<unordered_set<int>> us(10);
    // unordered_set: 정렬되어있지 않음, 중복값 허용X

    for (int k = 1; k <= 8; k++) {

        int tmp = 0;
        for (int i = 0; i < k; i++) {
            tmp += pow(10, i) * N;
        }
        us[k].insert(tmp);

        for (int i = 1; i <= k - 1; i++) {
            for (int j = k - 1; j >= 1; j--) {
                if (i + j != k)continue; // i+j=k인 경우에만 계산
                for (auto a : us[i]) {
                    for (auto b : us[j]) {
                        us[k].insert(a + b);
                        if (a - b > 0)us[k].insert(a - b);
                        us[k].insert(a * b);
                        if (a / b > 0) us[k].insert(a / b); // 나머지는 무시하므로
                    }
                }
            }
        }
        
        if (us[k].find(number) != us[k].end()) { // 조합한 수가 있으면 answer
            answer = k;
            break;
        }
    }


    cout << answer;
    //return answer;
}