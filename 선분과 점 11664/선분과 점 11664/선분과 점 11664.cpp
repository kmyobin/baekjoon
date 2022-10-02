#include <iostream>
#include <cmath>
using namespace std;

struct xyz { // xyz 구조체
	double x;
	double y;
	double z;
};

struct xyz A;
struct xyz B;
struct xyz C;

double minimum = 2147483647; // 초기 최솟값은 최대로 설정해야 ..

void BinarySearch(struct xyz start, struct xyz end) { 
	double temp = sqrt((start.x - end.x) * (start.x - end.x) + (start.y - end.y) * (start.y - end.y)
		+ (start.z - end.z) * (start.z - end.z)); // start와 end와의 거리를 구함
	double error = 1; 
	for (int i = 0; i < 6; i++) {
		error *= 0.1; // 오차는 10^-6까지 허용하므로
	}
	
	if (-1 * error <= temp && temp <= error) { // start와 end와의 거리가 허용오차 이내에서 0이면 같은 점을 가리킨다는 소리. 탐색 종료
		return;
	}

	struct xyz key; // 삼분탐색
	key.x = (start.x + end.x) / 2;;
	key.y = (start.y + end.y) / 2;
	key.z = (start.z + end.z) / 2;

	// len : 새로 설정한 선분AB 위의 점 key와 점 C사이의 거리
	double len = sqrt((key.x - C.x) * (key.x - C.x) + (key.y - C.y) * (key.y - C.y) + (key.z - C.z) * (key.z - C.z));
	
	minimum = (len < minimum) ? len : minimum; // 최솟값 갱신

	// start_C : start와 C 사이의 거리
	double start_C= sqrt((start.x - C.x) * (start.x - C.x) + (start.y - C.y) * (start.y - C.y) + (start.z - C.z) * (start.z - C.z));
	// end_C : end와 C 사이의 거리
	double end_C = sqrt((end.x - C.x) * (end.x - C.x) + (end.y - C.y) * (end.y - C.y) + (end.z - C.z) * (end.z - C.z));
	

	if (start_C > end_C) { // end_C와의 거리가 더 가깝다면 최소거리를 만족하는 점은 점 key와 점 end 사이에 있을것
		BinarySearch(key, end);
	}
	else { // 반대로는 start와 key 사이에 존재
		BinarySearch(start, key);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A.x >> A.y >> A.z;
	cin >> B.x >> B.y >> B.z;
	cin >> C.x >> C.y >> C.z;


	BinarySearch(A, B); // 선분 AB안에서 찾음
	 
	cout << fixed;
	cout.precision(10); // 소수점 10자리 출력
	cout << minimum;

}