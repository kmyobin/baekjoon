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
			// �ֽ� ���� ��������
			answer[s.top()] = i - s.top();
			s.pop();
		}

		s.push(i);
	}

	while (!s.empty()) {
		// stack�� �����ִ� �ε����� ������ ������ �������� ����
		answer[s.top()] = size -1 - s.top();
		s.pop();
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}

}