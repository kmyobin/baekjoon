#include <iostream>
#include <algorithm>
using namespace std;

typedef struct info {
	int age;
	string name;
	int order;
}info;

info inf[100000];
int N;

bool cmp(info a, info b) {
	if (a.age == b.age) { // 나이가 같으면
		return a.order < b.order;
	}
	return a.age < b.age; 
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> inf[i].age >> inf[i].name;
		inf[i].order = i;
	}

	sort(inf, inf + N, cmp);

	for (int i = 0; i < N; i++)
	{
		printf("%d %s\n", inf[i].age, inf[i].name.c_str());
	}
}