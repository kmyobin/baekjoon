#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int main() {

	vector<int> prices = { 3,5,2,6,7,8,1,10,9 };//{ 1,2,3,2,3 };//{
	vector<int> answer(10);

	stack<int> s;

	int size = prices.size();

	for (int i = 0; i <size; i++) {
		while (!s.empty() && (prices[s.top()] > prices[i])) {
			// 주식 가격 떨어지면
			answer[s.top()] = i - s.top();
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty()) {
		// stack에 남아있는 인덱스는 가격이 끝까지 떨어지지 않음
		answer[s.top()] = size -1 - s.top();
		s.pop();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

}