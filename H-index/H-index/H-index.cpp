#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> citations = { 0 };// { 3, 0, 6, 1, 5 }; // �� ���� �ο� Ƚ�� { 0,2,2,4,5,7,9,9,9 };//
	int answer = 0;

	sort(citations.begin(), citations.end()); // �ִ� �ο� Ƚ���� ���ϱ� ���� sort
	int max_cit = citations.back(); // �ִ� �ο� Ƚ����ŭ vector ����
	
	vector<int> A(max_cit + 1);

	int cnt = 0;
	for (int i = 0; i < A.size(); i++) {
		if (i > citations[cnt]) {
			cnt++;
		}

		A[i] = citations.size() - cnt;
	}

	for (int i = A.size() - 1; i >= 0; i--) {
		if (i <= A[i]) {
			answer = i;
			break;
		}
	}

	cout << answer;
}