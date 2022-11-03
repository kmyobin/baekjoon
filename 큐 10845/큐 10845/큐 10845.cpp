#include <iostream>
#include <string>
#define MAX 100000 // queue의 최대 크기는 10,000
using namespace std;

template<class T> class MyQueue
{
public :
	int front; int rear; int size;
	T* values;

	MyQueue() {
		size = MAX;
		values = new T[size];
		front = 0; rear = 0;
	}

	~MyQueue() { delete[] values; }

	void push(T value) {
		values[rear] = value;
		rear++;
	}

	void pop() {
		if (!empty()) {
			cout << values[front] << "\n";
			front++;
		}
		else { // queue에 들어있는 정수가 없는 경우
			cout << -1 << "\n";
		}
	}

	void size_() { // 재정의 오류 발생
		cout << rear - front <<"\n";
	}

	bool empty() {
		if (front == rear) {
			return true;
		}
		else return false;
	}

	void front_() { // 재정의 오류 발생
		if (!empty()) cout << values[front] << "\n";
		else cout << -1 << "\n";
	}

	void back() {
		if (!empty()) cout << values[rear - 1] << "\n";
		else cout << -1 << "\n";
	}
};

int N;
string command[6] = { "push", "pop", "size", "empty", "front", "back" };
string input;

MyQueue<int> myqueue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N + 1; i++) // getline 함수 때문에 자꾸 N-1만큼 입력을 받음,, 그래서 N만큼 반복하도록
	{
		getline(cin, input); // 한 줄을 다 입력받음
		for (int j = 0; j < 6; j++) {
			if (input.find(command[j]) != string::npos) { // 찾았다면				
				if (j == 0) { // push
					string temp = "";
					for (int k = 5; k < input.length(); k++) {
						temp += input[k]; // 정수 string으로 받은다음
					}
					int in = stoi(temp); // stoi로 정수 만듦
					myqueue.push(in);
				}
				else if (j == 1) { // pop
					myqueue.pop();
				}
				else if (j == 2) { // size
					myqueue.size_();
				}
				else if (j == 3) { // empty
					if (myqueue.empty() == true) {
						cout << 1 << "\n";
					}
					else {
						cout << 0 << "\n";
					}
				}
				else if (j == 4) { // front
					myqueue.front_();
				}
				else { // back
					myqueue.back();
				}
			}
		}
	}
}