#include <iostream>
using namespace std;

unsigned int S;

int main() {
	cin >> S;

	// 서로 다른 N개의 자연수의 합 : S
	// N의 최댓값을 구하려면 최대한 잘게 쪼개서 더해야함
	// 제일 잘게 쪼개면 1로만 더해야되는데 서로 다른 자연수를 더해야 하므로 
	// 1을 묶어주면서 더해줌
	// 20 = 1 + 1 + 1 + 1 + 1 + 1 + ... + 1
	// 20 = 1 + (! + 1) + (1 + 1 + 1) + ...
	// 이러면 남는 1들이 생기는데 그건 앞에다 더해줘도 N은 변하지 않음

	unsigned int i = 1;
	while (1) {
		if (S < i) {
			cout << i - 1; // i++ 해주기 전 상태로
			break;
		}
		S -= i;
		i++;
	}
}