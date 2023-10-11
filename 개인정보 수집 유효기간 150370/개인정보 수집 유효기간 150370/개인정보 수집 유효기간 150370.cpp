#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> getExpired(vector<int> x, int month) {
    vector<int> ymd;
    int y = x[0]; int m = x[1]; int d = x[2];

    // 100개월 = 8년 4개월 = (100 / 12)년 (100 - 12*(100/12))개월
    // 2021.05.02 + 100개월
    //    8. 4.
    // 2029.09.02

    int new_year = (month / 12);
    int new_month = month - 12 * new_year; // 0 <= new_month <= 11

    m += new_month;
    // 12 + 11 = 23개월 = 1년 11개월
    if (m > 12) {
        new_year += (m / 12);
        m %= 12;
    }

    y += new_year;

    ymd.push_back(y); ymd.push_back(m); ymd.push_back(d);

    return ymd;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int year = stoi(today.substr(0, 4)); 
    int month = stoi(today.substr(5, 2)); 
    int day = stoi(today.substr(8, 2));

    map<string, int> mm;
    for (int i = 0; i < terms.size(); i++) {
        stringstream ss(terms[i]);
        string term, period; // 공백 기준 끊기
        ss >> term >> period;
        mm[term] = stoi(period);
    }


    for (int i = 0; i < privacies.size(); i++) {
       
        string term;
        term = privacies[i][11];

        int y = stoi(privacies[i].substr(0, 4));
        int m = stoi(privacies[i].substr(5, 2));
        int d = stoi(privacies[i].substr(8, 2));

        int available_month = mm[term];
        vector<int> cur; cur.push_back(y); cur.push_back(m); cur.push_back(d);
        vector<int> fut = getExpired(cur, available_month);

        int today_day = day + month * 28 + year * 12 * 28;
        int expired_day = fut[2] + fut[1] * 28 + fut[0] * 12 * 28;

        if (today_day >= expired_day) answer.push_back(i + 1);
    }

    return answer;
}

int main() {
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };


    vector<int> result = solution(today, terms, privacies);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << "]";
}