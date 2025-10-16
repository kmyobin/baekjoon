#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[50];
int minimum = 51;

void dfs(int cnt, string present, string target, vector<string> words) {
    if (present == target) { // 단어가 완성됐으면 최솟값 갱신
        minimum = (minimum < cnt) ? minimum : cnt;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        // 다른 알파벳 개수 세기
        int diff = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] != present[j])diff++; 
        }

        if (!visited[i] && diff<=1) { // 방문한적 없고, 일치하지 않는 알파벳 개수가 1 이하면
            visited[i] = true;
            dfs(cnt + 1, words[i], target, words);
            visited[i] = false;
        }      
    }

    return;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    auto it = find(words.begin(), words.end(), target);
    if (it == words.end()) {} // words에 타겟이 없으면 시작할 필요가 없음
    else dfs(0, begin, target, words);
    
    if (minimum != 51)answer = minimum; // 최솟값이 갱신되지 않았다면 return값 0

    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" }; //{ "hot", "dot", "dog", "lot", "log", "cog" };

    int answer = solution(begin, target, words);

    cout << answer;
}