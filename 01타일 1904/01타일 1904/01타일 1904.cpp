#include <iostream>
#include <string>
using namespace std;

int N;
int M[1000001];

// 개수를 담아보자

void f(int count) {
	if (count == 1 || count==2 || count==3) { // count=1,2,3이면 count와 개수가 동일
		M[count]=count;
	}
	else {
		if (M[count] == 0) { // 아직 값이 채워지지 않았다면
			M[count] = (M[count - 1] + M[count - 2]) % 15746; // 값 채워넣기
		}
	}
	if (count == N) return; // 원하는 값에 도달했다면 return
	f(count + 1); // 아니라면 count 증가시켜 N에 도달하도록 만듦
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	f(1);
	printf("%d", M[N]);
}