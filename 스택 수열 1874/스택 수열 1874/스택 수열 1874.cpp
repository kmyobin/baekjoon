#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N; 
vector<char> myvector; // 배열의 크기를 지정해도 되지 않아서 편리하네용
stack<int> mystack;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int before = 0; // 어디까지 push 했는지 기억하기 위한 변수
	bool isWrong = false; // for문 탈출을 위한 변수
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		if (before < temp) { // temp까지 push를 해야되는 상황
			for (int j = before + 1; j <= temp; j++) { 
				myvector.push_back('+');
				mystack.push(j); // push
			}
			before = temp; // 어디까지 push했는지 저장
		}
		if (mystack.top() == temp) { // 입력된 수와 top()이 같으면 
			myvector.push_back('-');
			mystack.pop(); // pop
		}
		else { // pop할 때 원하는 원소가 튀어나오는게 아니라면
			cout << "NO";
			isWrong = true;
			break; // 종료
		}
	}
	if (!isWrong) {
		// 수열을 만들 수 있는 경우
		for (int i = 0; i < myvector.size(); i++) {
			cout << myvector.at(i) << "\n"; // push, pop 출력
		}
	}
}