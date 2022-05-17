#include <iostream>
using namespace std;

int N;

struct person {
	int weight;
	int height;
};

struct person p[50];

int main() {
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		p[i].weight = x; p[i].height = y; 
	}
	int rank = 0;
	for (int i = 0; i < N; i++)
	{
		rank = 0;
		for (int j = 0; j < N; j++)
		{
			
			if (p[i].weight < p[j].weight && p[i].height < p[j].height) { // 나보다 큰 사람만 비교해서 rnak++
				rank++;
			}
		}
		cout << rank+1 << endl;
	}
}