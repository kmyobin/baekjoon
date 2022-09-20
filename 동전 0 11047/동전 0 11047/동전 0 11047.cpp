#include <iostream>
using namespace std;

int N, K; int maximum; int cnt;
int A[10];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		
	}

	for (int i = N-1; i>=0; i--) {
		cnt += K / A[i];
		K = K % A[i];
	}
	cout << cnt;

}