#include <iostream>
using namespace std;

int N;
int A[100];
int v; int cnt;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> v;
	for (int i = 0; i < N; i++)
	{
		if (A[i] == v)cnt++;
	}
	cout << cnt;
}