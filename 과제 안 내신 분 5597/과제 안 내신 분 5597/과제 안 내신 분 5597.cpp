#include <iostream>
using namespace std;

int A[31];


int main() {

	for (int i = 1; i <= 28; i++) {
		int x;
		cin >> x;
		A[x] = 1;
	}

	for (int i = 1; i <= 30; i++)
	{
		if (!A[i])cout << i << "\n";
	}

}