#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string input;

// -가 나오면 그 뒤에 오는 것들 전부 빼줘야 최솟값이 나온다

int main() {
	cin >> input;

	int sum = 0;
	string temp = ""; // 숫자들을 담아줄 배열
	bool minus = false; // '-' 부호가 앞에 있었으면 계산 방식이 달라지기 때문에

	for (int i = 0; i < input.length() + 1; i++) {
		// 맨 마지막에 오는 숫자도 처리해줘야되기 때문에 길이 + 1 만큼 반복
		if (input[i] == '-' || input[i] == '+') { // 부호인 경우
			if (minus == true) sum -= stoi(temp); // 앞에 '-'가 온 적이 있다면 괄호로 묶여있다고 생각하고 빼준다
			else sum += stoi(temp); // 앞에 '-'가 온 적이 없으므로 더해준다
			if (input[i] == '-') minus = true; // '-'이면 minus를 true로 변경함
			temp = ""; // 더해주거나 빼주었으므로 temp 초기화
		}
		else if (input[i] == NULL) { // 맨 마지막 숫자를 다뤄주는 else if문
			if (minus == true) {
				sum -= stoi(temp);
			}
			else sum += stoi(temp);
		}
		else { // 숫자일 때
			temp += input[i];
		}
	}

	cout << sum;
}