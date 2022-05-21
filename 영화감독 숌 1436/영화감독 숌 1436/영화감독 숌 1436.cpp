#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 종말의 숫자 : 어떤 수에 6이 적어도 3개 이상 연속 들어가는 수
// N번째 영화의 제목 = 세상의 종말 (N번째로 작은 종말의 숫자)
// 666, 1666, 2666, 3666, 4666, 5666, 6661, 6662, 6663, 6664, 6665,,

int N;
int i;
int cnt;

bool is_666(string::size_type n, string const& s) {
	if (n == string::npos) { // 못찾았으면 
		return false;
	}
	else { // 찾았으면
		return true;
	}
}

int main() {
	cin >> N;

	
	while (1) {
		string temp = to_string(i); // int->string으로 변환
	
		int n = temp.find("666");
		
		if (is_666(n,temp)) { // 666이 들어간다면
			cnt++; // cnt번째 영화 제목
		}
		if (cnt == N) { // N번째 영화제목까지 도달했다면
			cout << i;
			break;
		}
		i++;
	}

	return 0;
}