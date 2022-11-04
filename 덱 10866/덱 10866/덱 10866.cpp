#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

template<class T> class MyDeque
{
public:
	int front; int rear; int size;
	T* values;

	MyDeque() {
		size = MAX;
		values = new T[size];
		front = 0; rear = 0;
	}

	~MyDeque() { delete[] values; }
	
	void push_front(T value) { // front에서 값 넣기
		values[front] = value; // 값 넣고
		front = (front - 1 + MAX) % MAX; // front--와 비슷(배열 최소 인덱스는 0이므로 배열 끝으로 가서 front를 가리킬수도) 
	}

	void push_back(T value) { // rear에서 값 넣기
		rear = (rear + 1) % MAX; // 미리 index를 증가시키고
		values[rear] = value; // 값 넣음
	}

	void pop_front() { // front 값 빼기
		if (!empty()) {
			front = (front + 1) % MAX; // 비어있는 곳을 가리키므로 증가시킨다음
			cout << values[front] << "\n"; // 출력 후
			values[front] = NULL; // NULL값으로 비워줌
			
		}
		else { // queue에 들어있는 정수가 없는 경우
			cout << -1 << "\n";
		}
	}
	void pop_back() { // rear 값 빼기
		if (!empty()) {
			cout << values[rear] << "\n";
			rear = (rear - 1 + MAX) % MAX;
		}
		else { // queue에 들어있는 정수가 없는 경우
			cout << -1 << "\n";
		}
	}

	void size_() { // 재정의 오류 발생
		cout << (rear - front + MAX) % MAX << "\n";
	}

	bool empty() {
		return front == rear;
	}

	void front_() { // 재정의 오류 발생
		if (!empty()) cout << values[(front + 1) % MAX] << "\n"; // front는 비어있는 곳을 가리키므로 +1
		else cout << -1 << "\n";
	}

	void back() { // 가장 뒤에 있는 정수 출력
		if (!empty()) cout << values[rear] << "\n"; // rear는 실제 값이 있는 곳을 가리키므로
		else cout << -1 << "\n";
	}
};

MyDeque<int> mydeque;

int N;
string command[8] = { "push_front", "push_back", "pop_front", "pop_back",
"size", "empty", "front", "back" };
string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N + 1; i++)
	{
		getline(cin, input);
		for (int j = 0; j < 8; j++) {
			if (input.find(command[j]) != string::npos) { // 찾았다면				
				if (j == 0) { // push_front
					string temp = "";
					for (int k = 11; k < input.length(); k++) {
						temp += input[k]; // 정수 string으로 받은다음
					}
					int in = stoi(temp); // stoi로 정수 만듦
					mydeque.push_front(in);
				}
				else if (j == 1) { // push_back
					string temp = "";
					for (int k = 10; k < input.length(); k++) {
						temp += input[k]; // 정수 string으로 받은다음
					}
					int in = stoi(temp); // stoi로 정수 만듦
					mydeque.push_back(in);
				}
				else if (j == 2) { // pop_front
					mydeque.pop_front();
				}
				else if (j == 3) { // pop_back
					mydeque.pop_back();
				}
				else if (j == 4) { // size
					mydeque.size_();
				}
				else if (j == 5) { // empty
					cout << mydeque.empty() << "\n";
				}
				else if (j == 6) { // front
					mydeque.front_();
				}
				else { // back
					mydeque.back();
				}
				break;
			}
		}
	}

}