1330번 두 수 비교하기
두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성하시오.



#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B;
	scanf("%d %d", &A, &B);

	if (A > B)
		printf(">");
	else if (A < B)
		printf("<");
	else
		printf("==");
	return 0;
}
