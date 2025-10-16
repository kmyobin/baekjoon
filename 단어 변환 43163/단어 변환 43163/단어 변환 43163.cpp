#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visited[50];
int minimum = 51;

void dfs(int cnt, string present, string target, vector<string> words) {
    if (present == target) { // �ܾ �ϼ������� �ּڰ� ����
        minimum = (minimum < cnt) ? minimum : cnt;
        return;
    }

    for (int i = 0; i < words.size(); i++) {
        // �ٸ� ���ĺ� ���� ����
        int diff = 0;
        for (int j = 0; j < words[i].size(); j++) {
            if (words[i][j] != present[j])diff++; 
        }

        if (!visited[i] && diff<=1) { // �湮���� ����, ��ġ���� �ʴ� ���ĺ� ������ 1 ���ϸ�
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
    if (it == words.end()) {} // words�� Ÿ���� ������ ������ �ʿ䰡 ����
    else dfs(0, begin, target, words);
    
    if (minimum != 51)answer = minimum; // �ּڰ��� ���ŵ��� �ʾҴٸ� return�� 0

    return answer;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" }; //{ "hot", "dot", "dog", "lot", "log", "cog" };

    int answer = solution(begin, target, words);

    cout << answer;
}