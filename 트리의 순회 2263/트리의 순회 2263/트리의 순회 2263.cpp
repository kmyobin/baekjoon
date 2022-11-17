#include <iostream>
using namespace std;

int N;
int inorder[100000];
int postorder[100000];
int position[100001]; // 100000이면 오류

void preorder(int in_min, int in_max, int post_min, int post_max) {
	if (in_min > in_max || post_min > post_max) {
		return;
	}

	int root = postorder[post_max]; // 후위 순회로 root를 구함
	int rootIndex = position[root]; // 중위 순회 기준으로 하는 root의 index를 구함

	printf("%d ", root);

	// left
	preorder(in_min, rootIndex - 1,
		post_min, post_min + (rootIndex - 1) - in_min);
	// right
	preorder(rootIndex + 1, in_max, 
		(post_min + rootIndex) - in_min, post_max - 1);

}

int main() {
	cin >> N;

	// 중위 순회
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
		position[inorder[i]] = i;
		// position[x] = y : x의 인덱스는 y이다.
		// inorder 값들의 위치 정보를 저장하고 싶어	
	}

	// 후위 순회 : 맨 마지막 노드가 root 노드
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}

	preorder(0, N - 1, 0, N - 1);
}