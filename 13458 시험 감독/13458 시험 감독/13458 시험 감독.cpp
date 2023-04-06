#include <iostream>
using namespace std;
#define MAX 1000001

int N;
int A[MAX];
int B, C;

long int min_visor; // 감독 수의 최댓값은 (10^6)*(10^6) = 10^12

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	cin >> B >> C;

	min_visor += N; // 총감독관은 시험장마다 있어야 하므로

	for (int i = 1; i <= N; i++)
	{
		A[i] -= B; // 총감독관이 담당하는 학생 빼기
		if (A[i] < 0) A[i] = 0; // too much면 0으로 통일(음수로 가지 않도록)
	}

	for (int i = 1; i <= N; i++)
	{
		min_visor += A[i] / C; 
		if (A[i] % C > 0) { // 나머지가 있다면
			min_visor++; // 감독 1명 추가
		}
	}

	cout << min_visor;
}