/*A
AA
AAA
AAAA
AAAAA
AAAAE
AAAAI
AAAAO
AAAAU
AAAE
AAAEA
AAAEE
AAAEI
AAAEO
AAAEU
AAAI
AAAIA
AAAIE
AAAII
AAAIO
AAAIU
AAAO
AAAOA
AAAOE
AAAOI
AAAOO
AAAOU
AAAU
AAAUA
AAAUE
AAAUI
AAAUO
AAAUU
AAE
AAEA
AAEE
AAEI
AAEO
AAEU
AAI
AAIA
AAIE
AAII
AAIO
AAIU
AAO
AAOA
AAOE
AAOI
AAOO
AAOU
AAU
AAUA
AAUE
AAUI
AAUO
AAUU
AE
AEA
AEE
AEI
AEO
AEU
AI
AIA
AIE
AII
AIO
AIU
AO
AOA
AOE
AOI
AOO
AOU
AU
AUA
AUE
AUI
AUO
AUU

*/
#include <string>
#include <vector>
#include <iostream>>

using namespace std;

string word = "AAAAE";
int cnt;
string SS[3906];
string alpha[5] = { "A", "E", "I", "O", "U" };

void dfs(int x, string A) {
    if (x == 5) {
        return;
    }
   
    for (int i = 0; i < 5; i++) {
        A += alpha[i];

        cnt++;
        SS[cnt] = A;
        
        dfs(x + 1, A);
        A.pop_back();
    }

    return;
}

int main() {
    int answer = 0;

    string A = "";
    dfs(0, A);

    for (int i = 1; i <= 3905; i++) {
        if (SS[i] == word) {
            answer = i;
            break;
        }
    }

    cout << answer;
    //return answer;
}