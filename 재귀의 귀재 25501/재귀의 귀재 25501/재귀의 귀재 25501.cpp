#include <iostream>
using namespace std;

int T;
string s;
int cnt;

int recursion(int l, int r) {
    cnt++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else {
        return recursion(l + 1, r - 1);
    }
}

int isPalindrome() {
    return recursion(0, s.length() - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for (int i = 0; i < T; i++)
    {    
        cnt = 0;
        cin >> s;
        printf("%d ", isPalindrome());
        printf("%d\n", cnt);
        s = "";
    }

}