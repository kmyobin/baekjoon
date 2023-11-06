#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

/*
bool cmp(string a, string b){

}
*/

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end());

    for (int i = 1; i < phone_book.size(); i++) {
        auto idx = phone_book[i].find(phone_book[i - 1]);

        if (idx != string::npos && idx == 0) return false;
    }
    return true;
}

int main() {
    vector<string> phone_book = { "119", "97674223", "1195524421" };
    cout << solution(phone_book);
}