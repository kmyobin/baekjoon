#include <iostream>
#include <stack>
using namespace std;

int K; long long sum;

stack<int> mystack;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int input;
		cin >> input;
		if (input == 0) {
			sum -= mystack.top();
			mystack.pop();			
		}
		else {
			sum += input;
			mystack.push(input);
		}
	}

	cout << sum;
}